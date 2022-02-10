#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/brush.h>
#include <xtd/drawing/native/system_colors.h>
#include <xtd/drawing/native/toolkit.h>
#include "../../../../../include/xtd/drawing/native/wx_brush.h"
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <algorithm>
#include <wx/colour.h>
#include <xtd/argument_exception.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing::native;

intptr_t brush::create() {
  toolkit::initialize(); // Must be first
  return reinterpret_cast<intptr_t>(new wx_brush());
}

void brush::solid(intptr_t brush, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  reinterpret_cast<wx_brush*>(brush)->create_solid_brush({r, g, b, a});
}

void brush::conical_gradient(intptr_t brush, int32_t center_x, int32_t center_y, const std::vector<std::tuple<uint8_t, uint8_t, uint8_t, uint8_t, float>>& colors, float angle) {
  if (colors.size() < 2) throw argument_exception(csf_);
  
  auto center_point = wxPoint(center_x, center_y);
  auto [start_r, start_g, start_b, start_a, start_pos] = colors[0];
  auto [end_r, end_g, end_b, end_a, end_pos] = colors[colors.size() - 1];
  wxGraphicsGradientStops colours(wxColour(start_r, start_g, start_b, start_a), wxColour(end_r, end_g, end_b, end_a));
  for (auto color : colors) {
    auto [r, g, b, a, pos] = color;
    colours.Add(wxColour(r, g, b, a), pos);
  }
  
  reinterpret_cast<wx_brush*>(brush)->create_conical_gradiant_brush(center_point, colours, angle);                                                                                
}

void brush::linear_gradient(intptr_t brush, int32_t x1, int32_t y1, int32_t x2, int32_t y2, const std::vector<std::tuple<uint8_t, uint8_t, uint8_t, uint8_t, float>>& colors, float angle) {
  if (colors.size() < 2) throw argument_exception(csf_);

  if (angle <= 22) angle = 0;
  else if (angle <= 67) angle = 45;
  else if (angle <= 112) angle = 90;
  else if (angle <= 157) angle = 135;
  else if (angle <= 202) angle = 180;
  else if (angle <= 247) angle = 225;
  else if (angle <= 292) angle = 270;
  else if (angle <= 337) angle = 315;
  else if (angle <= 359) angle = 0;
  
  auto p1 = wxPoint(x1, y1);
  auto p2 = wxPoint(x2, y2);
  auto [start_r, start_g, start_b, start_a, start_pos] = colors[0];
  auto [end_r, end_g, end_b, end_a, end_pos] = colors[colors.size() - 1];
  wxGraphicsGradientStops colours(wxColour(start_r, start_g, start_b, start_a), wxColour(end_r, end_g, end_b, end_a));
  for (auto color : colors) {
    auto [r, g, b, a, pos] = color;
    colours.Add(wxColour(r, g, b, a), pos);
  }

  if (angle == 0 || angle == 180) p2.y = p1.y;
  if (angle == 90 || angle == 270) p2.x = p1.x;
  if (angle == 135 || angle == 315) swap(p1.x, p2.x);
  if (angle == 180 || angle == 225 || angle == 270 || angle == 315) swap(p1, p2);
  
  reinterpret_cast<wx_brush*>(brush)->create_linear_gradiant_brush(p1, p2, colours);
}

void brush::radial_gradient(intptr_t brush, int32_t center_x, int32_t center_y, int32_t focal_x, int32_t focal_y, const std::vector<std::tuple<uint8_t, uint8_t, uint8_t, uint8_t, float>>& colors, float radius) {
  if (colors.size() < 2) throw argument_exception(csf_);
  
  auto center_point = wxPoint(center_x, center_y);
  auto focal_point = wxPoint(focal_x, focal_y);
  auto [start_r, start_g, start_b, start_a, start_pos] = colors[0];
  auto [end_r, end_g, end_b, end_a, end_pos] = colors[colors.size() - 1];
  wxGraphicsGradientStops colours(wxColour(start_r, start_g, start_b, start_a), wxColour(end_r, end_g, end_b, end_a));
  for (auto color : colors) {
    auto [r, g, b, a, pos] = color;
    colours.Add(wxColour(r, g, b, a), pos);
  }

  reinterpret_cast<wx_brush*>(brush)->create_radial_gradiant_brush(center_point, focal_point, colours, radius);
}

void brush::texture(intptr_t brush, intptr_t texture) {
  reinterpret_cast<wx_brush*>(brush)->create_texture_brush(*reinterpret_cast<wxImage*>(texture));
}

void brush::destroy(intptr_t brush) {
  delete reinterpret_cast<wx_brush*>(brush);
}
