#include <cmath>
#include <vector>
#include <xtd/argument_exception.h>
#include <xtd/as.h>
#include <xtd/convert_string.h>
#include <xtd/ustring.h>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/graphics.h>
#include <xtd/drawing/native/compositing_modes.h>
#include <xtd/drawing/native/compositing_qualities.h>
#include <xtd/drawing/native/copy_pixel_operations.h>
#include <xtd/drawing/native/path_fill_mode.h>
#include <xtd/drawing/native/interpolation_modes.h>
#include <xtd/drawing/native/pixel_offset_modes.h>
#include <xtd/drawing/native/smoothing_modes.h>
#include <xtd/drawing/native/text_rendering.h>
#include "../../../../../include/xtd/drawing/native/hdc_wrapper.h"
#include "../../../../../include/xtd/drawing/native/wx_brush.h"
#include "../../../../../include/xtd/drawing/native/wx_pen.h"
#include "../../../../../include/xtd/drawing/native/wxConicalGradient.h"
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <wx/app.h>
#include <wx/dcgraph.h>
#include <wx/dcmemory.h>
#include <wx/dcscreen.h>
#include <wx/region.h>

using namespace xtd;
using namespace xtd::drawing::native;

namespace {
  class graphics_context {
  public:
    explicit graphics_context(intptr_t handle) : hdc_(reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc()) {
      brush_ = hdc_.GetBrush();
      pen_ = hdc_.GetPen();
      back_color_ = hdc_.GetTextBackground();
      fore_color_ = hdc_.GetTextForeground();
      font_ = hdc_.GetFont();
    }
    
    ~graphics_context() {
      hdc_.SetBrush(brush_);
      hdc_.SetPen(pen_);
      hdc_.SetTextBackground(back_color_);
      hdc_.SetTextForeground(fore_color_);
      hdc_.SetFont(font_);
    }
    
  private:
    wxDC& hdc_;
    wxBrush brush_;
    wxColour back_color_;
    wxColour fore_color_;
    wxPen pen_;
    wxFont font_;
  };
  
  wxBrush to_brush(const wx_brush& brush) {
    if (brush.is_solid_brush()) return wxBrush(brush.get_solid_brush().color);
    if (brush.is_texture_brush()) return wxBrush(brush.get_texture_brush().texture);
    throw xtd::argument_exception("brush not defined"_t, current_stack_frame_);
  }
  
  wxGraphicsBrush to_graphics_brush(wxGraphicsContext& graphics, const wx_brush& brush) {
    if (brush.is_conical_gradiant_brush()) return graphics.CreateBrush(wxBrush(brush.get_conical_gradiant_brush().colors.Item(0).GetColour()));
    if (brush.is_linear_gradiant_brush()) return graphics.CreateLinearGradientBrush(static_cast<double>(brush.get_linear_gradiant_brush().point1.x), static_cast<double>(brush.get_linear_gradiant_brush().point1.y), static_cast<double>(brush.get_linear_gradiant_brush().point2.x), static_cast<double>(brush.get_linear_gradiant_brush().point2.y), brush.get_linear_gradiant_brush().colors);
    if (brush.is_radial_gradiant_brush()) return graphics.CreateRadialGradientBrush(static_cast<double>(brush.get_radial_gradiant_brush().focal_point.x), static_cast<double>(brush.get_radial_gradiant_brush().focal_point.y), static_cast<double>(brush.get_radial_gradiant_brush().center_point.x), static_cast<double>(brush.get_radial_gradiant_brush().center_point.y), static_cast<double>(brush.get_radial_gradiant_brush().radius), brush.get_radial_gradiant_brush().colors);
    if (brush.is_solid_brush()) return graphics.CreateBrush(wxBrush(brush.get_solid_brush().color));
    if (brush.is_texture_brush()) return graphics.CreateBrush(wxBrush(brush.get_texture_brush().texture));
    throw xtd::argument_exception("brush not defined"_t, current_stack_frame_);
  }
  
  wxPen to_pen(const wx_pen& pen) {
    if (pen.is_solid_color_pen()) {
      wxPen wxpen(pen.get_solid_color_pen().color, pen.get_solid_color_pen().width);
      wxpen.SetStyle(wxPenStyle::wxPENSTYLE_USER_DASH);
      wxpen.SetDashes(pen.get_solid_color_pen().dashes.size(), pen.get_solid_color_pen().dashes.data());
      wxpen.SetCap(pen.line_cap());
      wxpen.SetJoin(pen.line_join());
      return wxpen;
    }
    throw xtd::argument_exception("brush not defined"_t, current_stack_frame_);
  }
  
  wxGraphicsPen to_graphics_pen(wxGraphicsContext& graphics, const wx_pen& pen) {
    if (pen.is_solid_color_pen()) {
      wxGraphicsPenInfo pen_info;
      pen_info.Colour(pen.get_solid_color_pen().color);
      pen_info.Style(wxPenStyle::wxPENSTYLE_USER_DASH);
      pen_info.Dashes(pen.get_solid_color_pen().dashes.size(), pen.get_solid_color_pen().dashes.data());
      pen_info.Width(pen.get_solid_color_pen().width);
      pen_info.Cap(pen.line_cap());
      pen_info.Join(pen.line_join());
      return graphics.CreatePen(pen_info);
    }
    if (pen.is_hatch_fill_pen()) {
      wxGraphicsPenInfo pen_info;
      pen_info.Colour({0, 0, 0, 0});
      pen_info.Stipple(wxBitmap(pen.get_hatch_fill_pen().brush.get_texture_brush().texture));
      pen_info.Width(pen.get_hatch_fill_pen().width);
      pen_info.Cap(pen.line_cap());
      pen_info.Join(pen.line_join());
      return graphics.CreatePen(pen_info);
    }
    if (pen.is_linear_gradiant_pen()) {
      wxGraphicsPenInfo pen_info;
      pen_info.Colour({0, 0, 0, 0});
      pen_info.LinearGradient(pen.get_linear_gradiant_pen().brush.get_linear_gradiant_brush().point1.x, pen.get_linear_gradiant_pen().brush.get_linear_gradiant_brush().point1.y, pen.get_linear_gradiant_pen().brush.get_linear_gradiant_brush().point2.x, pen.get_linear_gradiant_pen().brush.get_linear_gradiant_brush().point2.y, pen.get_linear_gradiant_pen().brush.get_linear_gradiant_brush().colors);
      pen_info.Width(pen.get_linear_gradiant_pen().width);
      pen_info.Cap(pen.line_cap());
      pen_info.Join(pen.line_join());
      return graphics.CreatePen(pen_info);
    }
    if (pen.is_radial_gradiant_pen()) {
      wxGraphicsPenInfo pen_info;
      pen_info.Colour({0, 0, 0, 0});
      pen_info.RadialGradient(pen.get_radial_gradiant_pen().brush.get_radial_gradiant_brush().focal_point.x, pen.get_radial_gradiant_pen().brush.get_radial_gradiant_brush().focal_point.y, pen.get_radial_gradiant_pen().brush.get_radial_gradiant_brush().center_point.x, pen.get_radial_gradiant_pen().brush.get_radial_gradiant_brush().center_point.y, pen.get_radial_gradiant_pen().brush.get_radial_gradiant_brush().radius, pen.get_radial_gradiant_pen().brush.get_radial_gradiant_brush().colors);
      pen_info.Width(pen.get_radial_gradiant_pen().width);
      pen_info.Cap(pen.line_cap());
      pen_info.Join(pen.line_join());
      return graphics.CreatePen(pen_info);
    }
    if (pen.is_texture_fill_pen()) {
      wxGraphicsPenInfo pen_info;
      pen_info.Colour({0, 0, 0, 0});
      pen_info.Stipple(wxBitmap(pen.get_texture_fill_pen().brush.get_texture_brush().texture));
      pen_info.Width(pen.get_texture_fill_pen().width);
      pen_info.Cap(pen.line_cap());
      pen_info.Join(pen.line_join());
      return graphics.CreatePen(pen_info);
    }
    if (pen.is_conical_gradiant_pen()) {
      wxGraphicsPenInfo pen_info;
      pen_info.Colour(pen.get_conical_gradiant_pen().brush.get_conical_gradiant_brush().colors.Item(0).GetColour());
      pen_info.Width(pen.get_conical_gradiant_pen().width);
      pen_info.Cap(pen.line_cap());
      pen_info.Join(pen.line_join());
      return graphics.CreatePen(pen_info);
    }

    throw xtd::argument_exception("brush not defined"_t, current_stack_frame_);
  }
}

void graphics::clear(intptr_t handle, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  if (handle == 0) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  auto path = graphics.CreatePath();
  double width = 0.0, height = 0.0;
  graphics.GetSize(&width, &height);
  path.AddRectangle(0, 0, width, height);
  graphics.SetBrush(wxBrush({r, g, b, a}));
  graphics.FillPath(path);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::clip(intptr_t handle, intptr_t region) {
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc().SetClippingRegion(reinterpret_cast<wxRegion*>(region)->GetBox());
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics()->Clip(*reinterpret_cast<wxRegion*>(region));
}

void graphics::compositing_mode(intptr_t handle, int32_t compositing_mode) {
  // Not defined in wxWidgets
}

void graphics::compositing_quality(intptr_t handle, int32_t compositing_quality) {
  // Not defined in wxWidgets
}

void graphics::copy_from_screen(intptr_t handle, int32_t source_x, int32_t source_y, int32_t destination_x, int32_t destination_y, int32_t block_region_size_x, int32_t block_region_size_y, int32_t copy_pixel_operation) {
  wxScreenDC screen_dc;
  wxRasterOperationMode raster_operation_mode = wxRasterOperationMode::wxCOPY;
  switch (copy_pixel_operation) {
    case CPO_BLACKNESS: raster_operation_mode = wxRasterOperationMode::wxCLEAR; break;
    case CPO_CAPTURE_BLT: raster_operation_mode = wxRasterOperationMode::wxCOPY; break;
    case CPO_DESTINATION_INVERT: raster_operation_mode = wxRasterOperationMode::wxINVERT; break;
    case CPO_MERGE_COPY: raster_operation_mode = wxRasterOperationMode::wxAND; break;
    case CPO_MERGE_PAINT: raster_operation_mode = wxRasterOperationMode::wxOR_INVERT; break;
    case CPO_NO_MIRROR_BITMAP: raster_operation_mode = wxRasterOperationMode::wxINVERT; break;
    case CPO_NOT_SOURCE_COPY: raster_operation_mode = wxRasterOperationMode::wxSRC_INVERT; break;
    case CPO_NOT_SOURCE_ERASE: raster_operation_mode = wxRasterOperationMode::wxOR_INVERT; break;
    case CPO_PAT_COPY:  break;
    case CPO_PAT_INVERT:  break;
    case CPO_PAT_PAINT:  break;
    case CPO_SOURCE_AND: raster_operation_mode = wxRasterOperationMode::wxAND; break;
    case CPO_SOURCE_COPY: raster_operation_mode = wxRasterOperationMode::wxCOPY; break;
    case CPO_SOURCE_ERASE: raster_operation_mode = wxRasterOperationMode::wxAND_INVERT; break;
    case CPO_SOURCE_INVERT: raster_operation_mode = wxRasterOperationMode::wxXOR; break;
    case CPO_SOURCE_PAINT: raster_operation_mode = wxRasterOperationMode::wxOR; break;
    case CPO_WHITENESS: raster_operation_mode = wxRasterOperationMode::wxSET; break;
    default: raster_operation_mode = wxRasterOperationMode::wxCOPY; break;
  }
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc().Blit(destination_x, destination_y, block_region_size_x, block_region_size_y, &screen_dc, source_x, source_y, raster_operation_mode);
}

void graphics::destroy(intptr_t handle) {
  if (!handle) return;
  xtd::drawing::native::hdc_wrapper* hdc_wrapper = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle);
  delete hdc_wrapper;
}

void graphics::draw_arc(intptr_t handle, intptr_t pen, float x, float y, float width, float height, float start_angle, float sweep_angle) {
  if (!handle) return;
  graphics_context gc(handle);
  wxDC& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc();
  dc.SetBrush(*wxTRANSPARENT_BRUSH);
  dc.SetPen(to_pen(*reinterpret_cast<wx_pen*>(pen)));
  dc.DrawEllipticArc(x, y, width, height, 360 - start_angle - sweep_angle, 360 - start_angle);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_bezier(intptr_t handle, intptr_t pen, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
  if (!handle) return;
  auto path = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics()->CreatePath();
  path.MoveToPoint(x1, y1);
  path.AddCurveToPoint(x2, y2, x3, y3, x4, y4);
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.SetBrush(wxNullBrush);
  graphics.SetPen(to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  graphics.DrawPath(path);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_beziers(intptr_t handle, intptr_t pen, const std::vector<std::pair<float, float>>& points) {
  if (!handle) return;
  auto path = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics()->CreatePath();
  path.MoveToPoint(points[0].first, points[0].second);
  for (auto index  = 1U; index < points.size(); index += 3) {
    path.AddCurveToPoint(points[index].first, points[index].second, points[index + 1].first, points[index + 1].second, points[index + 2].first, points[index + 2].second);
    path.MoveToPoint(points[index + 2].first, points[index + 2].second);
  }
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.SetBrush(wxNullBrush);
  graphics.SetPen(to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  graphics.DrawPath(path);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_curve(intptr_t handle, intptr_t pen, std::vector<std::pair<float, float>> points, float tension) {
  if (!handle) return;
  graphics_context gc(handle);
  wxDC& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc();
  dc.SetBrush(*wxTRANSPARENT_BRUSH);
  dc.SetPen(to_pen(*reinterpret_cast<wx_pen*>(pen)));
  std::vector<wxPoint> wx_points;
  for (auto [x, y] : points)
    wx_points.push_back(wxPoint(as<int32_t>(x), as<int32_t>(y)));
  dc.DrawSpline(wx_points.size(), wx_points.data());
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_ellipse(intptr_t handle, intptr_t pen, float x, float y, float width, float height) {
  if (!handle) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.SetBrush(wxNullBrush);
  graphics.SetPen(to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  graphics.DrawEllipse(x, y, width, height);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_image(intptr_t handle, intptr_t image, float x, float y) {
  if (!handle) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  wxBitmap bitmap = wxBitmap(*reinterpret_cast<wxImage*>(image));
  graphics.DrawBitmap(bitmap, x, y, bitmap.GetWidth(), bitmap.GetHeight());
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_image_disabled(intptr_t handle, intptr_t image, float x, float y, float brightness) {
  if (!handle) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  wxBitmap bitmap = wxBitmap(*reinterpret_cast<wxImage*>(image)).ConvertToDisabled(static_cast<uint8_t>(255 * brightness));
  graphics.DrawBitmap(bitmap, x, y, bitmap.GetWidth(), bitmap.GetHeight());
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_line(intptr_t handle, intptr_t pen, float x1, float y1, float x2, float y2) {
  if (!handle) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.SetBrush(wxNullBrush);
  graphics.SetPen(to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  graphics.StrokeLine(x1, y1, x2, y2);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_path(intptr_t handle, intptr_t pen, intptr_t graphics_path) {
  if (!handle) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.SetBrush(wxNullBrush);
  graphics.SetPen(to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  graphics.DrawPath(*reinterpret_cast<wxGraphicsPath*>(graphics_path));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_rectangle(intptr_t handle, intptr_t pen, float x, float y, float width, float height) {
  if (!handle) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.SetBrush(wxNullBrush);
  graphics.SetPen(to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  graphics.DrawRectangle(x, y, width, height);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_rounded_rectangle(intptr_t handle, intptr_t pen, float x, float y, float width, float height, float radius) {
  if (!handle) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.SetBrush(wxNullBrush);
  graphics.SetPen(to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  graphics.DrawRoundedRectangle(x, y, width, height, radius);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_string(intptr_t handle, const ustring& text, intptr_t font, float x, float y, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  if (!handle) return;
  // Workaround : with wxWidgets version <= 3.1.4 wxGraphicsContext::DrawText doesn't work with unicode on Windows.
  if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows") {
    wxDC& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc();
    dc.SetFont(*reinterpret_cast<wxFont*>(font));
    dc.SetTextForeground({ r, g, b, a });
    dc.DrawText(wxString(convert_string::to_wstring(text)), x, y);
  } else {
    wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
    graphics.SetBrush(wxNullBrush);
    graphics.SetPen(wxNullPen);
    graphics.SetFont(*reinterpret_cast<wxFont*>(font), { r, g, b, a });
    graphics.DrawText(wxString(convert_string::to_wstring(text)), x, y);
  }
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_string(intptr_t handle, const ustring& text, intptr_t font, float x, float y, float w, float h, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  if (!handle) return;
  // Workaround : with wxWidgets version <= 3.1.4 wxGraphicsContext::DrawText doesn't work with unicode on Windows.
  if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows") {
    wxDC& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc();
    dc.SetClippingRegion({static_cast<int32_t>(x), static_cast<int32_t>(y)}, {static_cast<int32_t>(w), static_cast<int32_t>(h)});
    dc.SetFont(*reinterpret_cast<wxFont*>(font));
    dc.SetTextForeground({ r, g, b, a });
    dc.DrawText(wxString(convert_string::to_wstring(text)), x, y);
    dc.DestroyClippingRegion();
  } else {
    wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
    graphics.Clip(x, y, w, h);
    graphics.SetBrush(wxNullBrush);
    graphics.SetPen(wxNullPen);
    graphics.SetFont(*reinterpret_cast<wxFont*>(font), { r, g, b, a });
    graphics.DrawText(wxString(convert_string::to_wstring(text)), x, y);
    graphics.ResetClip();
  }
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::fill_ellipse(intptr_t handle, intptr_t brush, float x, float y, float width, float height) {
  if (!handle) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  if (reinterpret_cast<wx_brush*>(brush)->is_conical_gradiant_brush()) {
    wxBitmap conical_gradient_bitmap = wxConicalGradient::CreateBitmap(wxSize(width, height), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().colors, reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().center_point - wxPoint(x, y), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().angle);
    wxImage conical_gradient_image = conical_gradient_bitmap.ConvertToImage();
    wxBitmap conical_gradient_bitmap_mask(width, height);
    auto conical_gradient_mask_graphics = wxGraphicsContext::Create(wxMemoryDC(conical_gradient_bitmap_mask));
    conical_gradient_mask_graphics->SetBrush(conical_gradient_mask_graphics->CreateBrush(wxBrush(wxColour(255, 255, 255))));
    conical_gradient_mask_graphics->DrawEllipse(0, 0, width, height);
    conical_gradient_image.SetMaskFromImage(conical_gradient_bitmap_mask.ConvertToImage(), 0, 0, 0);
    conical_gradient_bitmap = conical_gradient_image;
    graphics.DrawBitmap(conical_gradient_bitmap, x, y, width, height);
  } else {
    graphics.SetPen(wxNullPen);
    graphics.SetBrush(to_graphics_brush(graphics, *reinterpret_cast<wx_brush*>(brush)));
    graphics.DrawEllipse(static_cast<double>(x), static_cast<double>(y), static_cast<double>(width), static_cast<double>(height));
  }
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::fill_path(intptr_t handle, intptr_t brush, intptr_t graphics_path, int32_t mode) {
  if (!handle) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  if (reinterpret_cast<wx_brush*>(brush)->is_conical_gradiant_brush()) {
    double x, y, width, height;
    reinterpret_cast<wxGraphicsPath*>(graphics_path)->GetBox(&x, &y, &width, &height);
    wxBitmap conical_gradient_bitmap = wxConicalGradient::CreateBitmap(wxSize(width, height), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().colors, reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().center_point - wxPoint(x, y), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().angle);
    wxImage conical_gradient_image = conical_gradient_bitmap.ConvertToImage();
    wxBitmap conical_gradient_bitmap_mask(x + width, y + height);
    auto conical_gradient_mask_graphics = wxGraphicsContext::Create(wxMemoryDC(conical_gradient_bitmap_mask));
    conical_gradient_mask_graphics->SetBrush(conical_gradient_mask_graphics->CreateBrush(wxBrush(wxColour(255, 255, 255))));
    conical_gradient_mask_graphics->FillPath(*reinterpret_cast<wxGraphicsPath*>(graphics_path));
    conical_gradient_image.SetMaskFromImage(conical_gradient_bitmap_mask.ConvertToImage(), 0, 0, 0);
    conical_gradient_bitmap = conical_gradient_image;
    graphics.DrawBitmap(conical_gradient_bitmap, x, y, width, height);
  } else {
    graphics.SetPen(wxNullPen);
    graphics.SetBrush(to_graphics_brush(graphics, *reinterpret_cast<wx_brush*>(brush)));
    graphics.FillPath(*reinterpret_cast<wxGraphicsPath*>(graphics_path), mode == PFM_ALTERNATE ? wxODDEVEN_RULE : wxWINDING_RULE);
  }
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::fill_pie(intptr_t handle, intptr_t brush, float x, float y, float width, float height, float start_angle, float sweep_angle) {
  if (!handle) return;
  graphics_context gc(handle);
  wxDC& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc();
  if (reinterpret_cast<wx_brush*>(brush)->is_conical_gradiant_brush()) {
    wxBitmap conical_gradient_bitmap = wxConicalGradient::CreateBitmap(wxSize(width, height), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().colors, reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().center_point - wxPoint(x, y), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().angle);
    wxImage conical_gradient_image = conical_gradient_bitmap.ConvertToImage();
    wxBitmap conical_gradient_bitmap_mask(width, height);
    auto conical_gradient_bitmap_mask_dc = wxMemoryDC(conical_gradient_bitmap_mask);
    conical_gradient_bitmap_mask_dc.SetBrush(wxBrush(wxColour(255, 255, 255)));
    conical_gradient_bitmap_mask_dc.DrawEllipticArc(0, y, width, height, 360 - start_angle - sweep_angle, 360 - start_angle);
    conical_gradient_image.SetMaskFromImage(conical_gradient_bitmap_mask.ConvertToImage(), 0, 0, 0);
    conical_gradient_bitmap = conical_gradient_image;
    dc.DrawBitmap(conical_gradient_bitmap, x, y);
  } else {
    dc.SetBrush(to_brush(*reinterpret_cast<wx_brush*>(brush)));
    dc.SetPen(wxNullPen);
    dc.DrawEllipticArc(x, y, width, height, 360 - start_angle - sweep_angle, 360 - start_angle);
  }
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::fill_rectangle(intptr_t handle, intptr_t brush, float x, float y, float width, float height) {
  if (!handle) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  if (reinterpret_cast<wx_brush*>(brush)->is_conical_gradiant_brush()) {
    graphics.DrawBitmap(wxConicalGradient::CreateBitmap(wxSize(width, height), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().colors, reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().center_point - wxPoint(x, y), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().angle), x, y, width, height);
  } else {
    graphics.SetPen(wxNullPen);
    graphics.SetBrush(to_graphics_brush(graphics, *reinterpret_cast<wx_brush*>(brush)));
    graphics.DrawRectangle(static_cast<double>(x), static_cast<double>(y), static_cast<double>(width), static_cast<double>(height));
  }

  // Workaround : with wxWidgets version <= 3.1.5 Radial gradient does not fill rectangle with end color on Windows.
#if defined(WIN32)
  if (reinterpret_cast<wx_brush*>(brush)->is_radial_gradiant_brush()) {
    auto wx_radial_brush = reinterpret_cast<wx_brush*>(brush)->get_radial_gradiant_brush();
    wxImage image(width, height);
    image.InitAlpha();
    for (int y_ia = 0; y_ia < height; y_ia++)
      for (int x_ia = 0; x_ia < width; x_ia++)
        image.SetAlpha(x_ia, y_ia, 0);
    wxBitmap conical_gradient_bitmap(image);
    auto conical_gradient_graphics = wxGraphicsContext::Create(wxMemoryDC(conical_gradient_bitmap));
    conical_gradient_graphics->SetPen(wxNullPen);
    conical_gradient_graphics->SetBrush(wxBrush(reinterpret_cast<wx_brush*>(brush)->get_radial_gradiant_brush().colors.Item(reinterpret_cast<wx_brush*>(brush)->get_radial_gradiant_brush().colors.GetCount() - 1).GetColour()));
    conical_gradient_graphics->DrawRectangle(0, 0, static_cast<double>(width), static_cast<double>(height));
    wxImage conical_gradient_image = conical_gradient_bitmap.ConvertToImage();
    wxBitmap conical_gradient_bitmap_mask(width, height);
    auto conical_gradient_mask_graphics = wxGraphicsContext::Create(wxMemoryDC(conical_gradient_bitmap_mask));
    conical_gradient_mask_graphics->SetPen(wxNullPen);
    conical_gradient_mask_graphics->SetBrush(conical_gradient_mask_graphics->CreateBrush(wxBrush(wxColour(255, 255, 255))));
    conical_gradient_mask_graphics->DrawRectangle(0, 0, width, height);
    conical_gradient_mask_graphics->SetBrush(conical_gradient_mask_graphics->CreateRadialGradientBrush(wx_radial_brush.focal_point.x - x, wx_radial_brush.focal_point.y - y, wx_radial_brush.center_point.x - x, wx_radial_brush.center_point.y - y, wx_radial_brush.radius, wxColour(0, 0, 0), wxColour(0, 0, 0)));
    conical_gradient_mask_graphics->DrawRectangle(0, 0, static_cast<double>(width), static_cast<double>(height));
    conical_gradient_image.SetMaskFromImage(conical_gradient_bitmap_mask.ConvertToImage(), 0, 0, 0);
    conical_gradient_bitmap = conical_gradient_image;
    graphics.DrawBitmap(conical_gradient_bitmap, x, y, width, height);
  }
#endif

  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::fill_region(intptr_t handle, intptr_t brush, intptr_t region) {
  if (!handle) return;
  int32_t x, y, width, height;
  wxRegion* wx_region = reinterpret_cast<wxRegion*>(region);
  wx_region->GetBox(x, y, width, height);
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.Clip(*wx_region);
  if (reinterpret_cast<wx_brush*>(brush)->is_conical_gradiant_brush()) {
    graphics.DrawBitmap(wxConicalGradient::CreateBitmap(wxSize(width, height), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().colors, reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().center_point - wxPoint(x, y), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().angle), x, y, width, height);
  } else {
    graphics.SetPen(wxNullPen);
    graphics.SetBrush(to_graphics_brush(graphics, *reinterpret_cast<wx_brush*>(brush)));
    graphics.DrawRectangle(static_cast<double>(x), static_cast<double>(y), static_cast<double>(width), static_cast<double>(height));
  }
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::fill_rounded_rectangle(intptr_t handle, intptr_t brush, float x, float y, float width, float height, float radius) {
  if (!handle) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  if (reinterpret_cast<wx_brush*>(brush)->is_conical_gradiant_brush()) {
    wxBitmap conical_gradient_bitmap = wxConicalGradient::CreateBitmap(wxSize(width, height), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().colors, reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().center_point - wxPoint(x, y), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().angle);
    wxImage conical_gradient_image = conical_gradient_bitmap.ConvertToImage();
    wxBitmap conical_gradient_bitmap_mask(width, height);
    auto conical_gradient_mask_graphics = wxGraphicsContext::Create(wxMemoryDC(conical_gradient_bitmap_mask));
    conical_gradient_mask_graphics->SetBrush(conical_gradient_mask_graphics->CreateBrush(wxBrush(wxColour(255, 255, 255))));
    conical_gradient_mask_graphics->DrawRoundedRectangle(0, 0, width, height, radius);
    conical_gradient_image.SetMaskFromImage(conical_gradient_bitmap_mask.ConvertToImage(), 0, 0, 0);
    conical_gradient_bitmap = conical_gradient_image;
    graphics.DrawBitmap(conical_gradient_bitmap, x, y, width, height);
  } else {
    graphics.SetPen(wxNullPen);
    graphics.SetBrush(to_graphics_brush(graphics, *reinterpret_cast<wx_brush*>(brush)));
    graphics.DrawRoundedRectangle(static_cast<double>(x), static_cast<double>(y), static_cast<double>(width), static_cast<double>(height), static_cast<double>(radius));
  }

  // Workaround : with wxWidgets version <= 3.1.5 Radial gradient does not fill rounded rectangle with end color on Windows.
#if defined(WIN32)
  if (reinterpret_cast<wx_brush*>(brush)->is_radial_gradiant_brush()) {
    auto wx_radial_brush = reinterpret_cast<wx_brush*>(brush)->get_radial_gradiant_brush();
    wxImage image(width, height);
    image.InitAlpha();
    for (int y_ia = 0; y_ia <height; y_ia++)
      for (int x_ia = 0; x_ia < width; x_ia++)
        image.SetAlpha(x_ia, y_ia, 0);
    wxBitmap conical_gradient_bitmap(image);
    auto conical_gradient_graphics = wxGraphicsContext::Create(wxMemoryDC(conical_gradient_bitmap));
    conical_gradient_graphics->SetPen(wxNullPen);
    conical_gradient_graphics->SetBrush(wxBrush(reinterpret_cast<wx_brush*>(brush)->get_radial_gradiant_brush().colors.Item(reinterpret_cast<wx_brush*>(brush)->get_radial_gradiant_brush().colors.GetCount() - 1).GetColour()));
    conical_gradient_graphics->DrawRoundedRectangle(0, 0, static_cast<double>(width), static_cast<double>(height), static_cast<double>(radius));
    wxImage conical_gradient_image = conical_gradient_bitmap.ConvertToImage();
    wxBitmap conical_gradient_bitmap_mask(width, height);
    auto conical_gradient_mask_graphics = wxGraphicsContext::Create(wxMemoryDC(conical_gradient_bitmap_mask));
    conical_gradient_mask_graphics->SetPen(wxNullPen);
    conical_gradient_mask_graphics->SetBrush(conical_gradient_mask_graphics->CreateBrush(wxBrush(wxColour(255, 255, 255))));
    conical_gradient_mask_graphics->DrawRoundedRectangle(0, 0, width, height, radius);
    conical_gradient_mask_graphics->SetBrush(conical_gradient_mask_graphics->CreateRadialGradientBrush(wx_radial_brush.focal_point.x - x, wx_radial_brush.focal_point.y - y, wx_radial_brush.center_point.x - x, wx_radial_brush.center_point.y - y, wx_radial_brush.radius, wxColour(0, 0, 0), wxColour(0, 0, 0)));
    conical_gradient_mask_graphics->DrawRoundedRectangle(0, 0, static_cast<double>(width), static_cast<double>(height), static_cast<double>(radius));
    conical_gradient_image.SetMaskFromImage(conical_gradient_bitmap_mask.ConvertToImage(), 0, 0, 0);
    conical_gradient_bitmap = conical_gradient_image;
    graphics.DrawBitmap(conical_gradient_bitmap, x, y, width, height);
  }
#endif

  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

intptr_t graphics::from_image(intptr_t image) {
  xtd::drawing::native::hdc_wrapper* hdc_wrapper = new xtd::drawing::native::hdc_wrapper;
  if (image == 0) hdc_wrapper->create<wxScreenDC>();
  else hdc_wrapper->create_memory_hdc(new wxBitmap(*reinterpret_cast<wxImage*>(image)), reinterpret_cast<wxImage*>(image));
  return reinterpret_cast<intptr_t>(hdc_wrapper);
}

float graphics::get_dpi_x(intptr_t handle) {
  double dpi_x = 0.0, dpi_y = 0.0;
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics()->GetDPI(&dpi_x, &dpi_y);
  return static_cast<float>(dpi_x);
}

float graphics::get_dpi_y(intptr_t handle) {
  double dpi_x = 0.0, dpi_y = 0.0;
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics()->GetDPI(&dpi_x, &dpi_y);
  return static_cast<float>(dpi_y);
}

void graphics::interpolation_mode(intptr_t handle, int32_t interpolation_mode) {
  auto graphics = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  switch (interpolation_mode) {
    case IM_INVALID: break;
    case IM_DEFAULT: graphics->SetInterpolationQuality(wxInterpolationQuality::wxINTERPOLATION_DEFAULT); break;
    case IM_LOW: graphics->SetInterpolationQuality(wxInterpolationQuality::wxINTERPOLATION_FAST); break;
    case IM_HIGHT: graphics->SetInterpolationQuality(wxInterpolationQuality::wxINTERPOLATION_GOOD); break;
    case IM_BICUBIC: graphics->SetInterpolationQuality(wxInterpolationQuality::wxINTERPOLATION_GOOD); break;
    case IM_NEAREST_NEIGHBOOR: graphics->SetInterpolationQuality(wxInterpolationQuality::wxINTERPOLATION_GOOD); break;
    case IM_HIGH_QUALLITY_BILINEAR: graphics->SetInterpolationQuality(wxInterpolationQuality::wxINTERPOLATION_BEST); break;
    case IL_HIGN_QUALITY_BICUBIC: graphics->SetInterpolationQuality(wxInterpolationQuality::wxINTERPOLATION_BEST); break;
    default: graphics->SetInterpolationQuality(wxInterpolationQuality::wxINTERPOLATION_DEFAULT); break;
  }
}

void graphics::measure_string(intptr_t handle, const ustring& text, intptr_t font, float& width, float& height) {
  if (!handle) return;
  width = 0;
  height = 0;
  auto strings = text.split({ '\n' });
  for (auto string : strings) {
    double line_width = 0, line_height = 0;
    // Workaround : with wxWidgets version <= 3.1.4 wxGraphicsContext::GetTextExtent doesn't work with unicode on Windows.
    if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows") {
      reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc().SetFont(*reinterpret_cast<wxFont*>(font));
      wxSize line_size = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc().GetTextExtent(wxString(convert_string::to_wstring(string)));
      line_width = line_size.GetWidth();
      line_height = line_size.GetHeight();
    } else {
      wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
      graphics.SetFont(*reinterpret_cast<wxFont*>(font), { 0, 0, 0 });
      graphics.GetTextExtent(wxString(convert_string::to_wstring(string)), &line_width, &line_height);
    }
    width = std::max(width, static_cast<float>(line_width));
    height += static_cast<float>(line_height);
    
    // Workaround : with wxWidgets version <= 3.1.5 width size text is too small on macOS and linux.
    if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() != "Windows" && reinterpret_cast<wxFont*>(font)->GetStyle() > wxFontStyle::wxFONTSTYLE_NORMAL) width += std::ceil(reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc().GetFontMetrics().averageWidth / 2.3f);
  }
}

void graphics::pixel_offset_mode(intptr_t handle, int32_t pixel_offset_mode) {
  auto graphics = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  switch (pixel_offset_mode) {
    case PO_INVALID: break;
    case PO_DEFAULT: graphics->DisableOffset(); break;
    case PO_HIGH_SPEED: graphics->DisableOffset(); break;
    case PO_HIGHT_QUALITY: graphics->EnableOffset(); break;
    case PO_NONE: graphics->DisableOffset(); break;
    case PO_HALF: graphics->ShouldOffset(); break;
    default: graphics->DisableOffset(); break;
  }
}

void graphics::rotate_transform(intptr_t handle, float angle) {
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.Rotate(angle);
}

void graphics::smoothing_mode(intptr_t handle, int32_t smoothing_mode) {
  auto graphics = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  switch (smoothing_mode) {
    case SM_INVALID: break;
    case SM_DEFAULT: graphics->SetAntialiasMode(wxAntialiasMode::wxANTIALIAS_NONE); break;
    case SM_HIGH_SPEED: graphics->SetAntialiasMode(wxAntialiasMode::wxANTIALIAS_NONE); break;
    case SM_HIGHT_QUALITY: graphics->SetAntialiasMode(wxAntialiasMode::wxANTIALIAS_DEFAULT); break;
    case SM_NONE: graphics->SetAntialiasMode(wxAntialiasMode::wxANTIALIAS_NONE); break;
    case SM_ANTI_ALIAS: graphics->SetAntialiasMode(wxAntialiasMode::wxANTIALIAS_DEFAULT); break;
    default: graphics->SetAntialiasMode(wxAntialiasMode::wxANTIALIAS_NONE); break;
  }
}

void graphics::text_contrast(intptr_t handle, int32_t text_contrast) {
  // Not defined in wxWidgets
}

void graphics::text_rendering_hint(intptr_t handle, int32_t text_rendering_hint) {
  // Not defined in wxWidgets
}

void graphics::translate_clip(intptr_t handle, float dx, float dy) {
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.Translate(dx, dy);
}

void graphics::visible_clip_bounds(intptr_t handle, float& x, float& y, float& width, float& height) {
  double wx_x = 0.0, wx_y = 0.0, wx_width = 0.0, wx_height = 0.0;
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics()->GetClipBox(&wx_x, &wx_y, &wx_width, &wx_height);
  x = as<float>(wx_x);
  y = as<float>(wx_y);
  width = as<float>(wx_width);
  height = as<float>(wx_height);
}
