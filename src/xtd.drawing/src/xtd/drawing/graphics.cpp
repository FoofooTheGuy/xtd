#include <vector>
#include "../../../include/xtd/drawing/bitmap.h"
#include "../../../include/xtd/drawing/graphics.h"
#include "../../../include/xtd/drawing/solid_brush.h"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/graphics.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

namespace {
  ustring get_hotkey_prefix_locations(const ustring& str, std::vector<size_t>& locations) {
    size_t offset = 0;
    for (auto index = 0U; index < str.size(); index++) {
      if (str[index] == '&' && str[index + 1] != '&')
        locations.push_back(index + offset);
      else if (str[index] == '&' && str[index + 1] == '&') {
        offset -= 2;
        ++index;
      }
    }
    auto new_str = str.replace("&&", "&");
    for (auto index = 0U; index < locations.size(); ++index)
      new_str = new_str.remove(locations[index], 1);
    return new_str;
  }
}

graphics::graphics(const graphics& value) {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::graphics::destroy(data_->handle_);
  data_ = value.data_;
}

graphics& graphics::operator=(const graphics& value) {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::graphics::destroy(data_->handle_);
  data_ = value.data_;
  return *this;
}

graphics::~graphics() {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::graphics::destroy(data_->handle_);
}

void graphics::clear(const color& color) {
  native::graphics::clear(data_->handle_, color.a(), color.r(), color.g(), color.b());
}

void graphics::draw_arc(const pen& pen, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle) {
  native::graphics::draw_arc(data_->handle_, pen.data_->handle_, x, y, width, height, start_angle, sweep_angle);
}

void graphics::draw_bezier(const pen& pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, int32_t x4, int32_t y4) {
  native::graphics::draw_bezier(data_->handle_, pen.data_->handle_, x1, y1, x2, y2, x3, y3, x4, y4);
}

void graphics::draw_ellipse(const pen& pen, int32_t x, int32_t y, int32_t width, int32_t height) {
  native::graphics::draw_ellipse(data_->handle_, pen.data_->handle_, x, y, width, height);
}

void graphics::draw_image(const xtd::drawing::image& image, int32_t x, int32_t y, int32_t width, int32_t height) {
  if (size(width, height) == image.size())  native::graphics::draw_image(data_->handle_, image.handle(), x, y);
  else native::graphics::draw_image(data_->handle_, bitmap(image, size(width, height)).handle(), x, y);
}

void graphics::draw_image(const image& image, int32_t x, int32_t y) {
  draw_image(image, x, y, image.size().width(), image.size().height());
}

void graphics::draw_image_disabled(const image& image, int32_t x, int32_t y, float brightness) {
  native::graphics::draw_image_disabled(data_->handle_, image.handle(), x, y, brightness);
}

void graphics::draw_line(const pen& pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
  native::graphics::draw_line(data_->handle_, pen.data_->handle_, x1, y1, x2, y2);
}

void graphics::draw_rectangle(const pen& pen, int32_t x, int32_t y, int32_t width, int32_t height) {
  native::graphics::draw_rectangle(data_->handle_, pen.data_->handle_, x, y, width, height);
}

void graphics::draw_rounded_rectangle(const pen& pen, int32_t x, int32_t y, int32_t width, int32_t height, int32_t radius) {
  native::graphics::draw_rounded_rectangle(data_->handle_, pen.data_->handle_, x, y, width, height, radius);
}

void graphics::draw_string(const ustring& text, const font& font, const brush& brush, float x, float y, const string_format& format) {
  if (dynamic_cast<const solid_brush*>(&brush) != nullptr)
    native::graphics::draw_string(data_->handle_, text, font.data_->handle_, static_cast<int32_t>(x), static_cast<int32_t>(y), static_cast<const solid_brush&>(brush).color().a(), static_cast<const solid_brush&>(brush).color().r(), static_cast<const solid_brush&>(brush).color().g(), static_cast<const solid_brush&>(brush).color().b());
}

void graphics::draw_string(const ustring& text, const font& font, const brush& brush, const rectangle_f& layout_rectangle, const string_format& format) {
  if (dynamic_cast<const solid_brush*>(&brush) != nullptr) {
    auto text_size = measure_string(text, font);
    auto y = layout_rectangle.y();
    auto height = layout_rectangle.height();
    
    if (format.line_alignment() == string_alignment::center) {
      y += (layout_rectangle.height() - text_size.height()) / 2;
      height -= (layout_rectangle.height() - text_size.height()) / 2;
    } else  if (format.line_alignment() == string_alignment::far) {
      y += (layout_rectangle.height() - text_size.height());
      height -= (layout_rectangle.height() - text_size.height());
    }
    
    auto lines = text.split({'\n'});
    for (auto line : lines) {
      if (line.empty()) line = " ";
      vector<size_t> hotkey_prefix_locations;
      string line_without_hotkey_prefix = get_hotkey_prefix_locations(line, hotkey_prefix_locations);
      auto drawable_line = format.hotkey_prefix() == hotkey_prefix::none ? line : line_without_hotkey_prefix;
      auto x = layout_rectangle.x();
      auto width = layout_rectangle.width();
      auto line_size = measure_string(drawable_line, font);
      if (format.alignment() == string_alignment::center) {
        x += (layout_rectangle.width() - line_size.width()) / 2;
        width -= (layout_rectangle.width() - line_size.width()) / 2;
      } else  if (format.alignment() == string_alignment::far) {
        x += (layout_rectangle.width() - line_size.width());
        width -= (layout_rectangle.width() - line_size.width());
      }
      
      if (format.hotkey_prefix() != hotkey_prefix::show) native::graphics::draw_string(data_->handle_, drawable_line, font.data_->handle_, static_cast<int32_t>(x), static_cast<int32_t>(y), static_cast<int32_t>(width), static_cast<int32_t>(height), static_cast<const solid_brush&>(brush).color().a(), static_cast<const solid_brush&>(brush).color().r(), static_cast<const solid_brush&>(brush).color().g(), static_cast<const solid_brush&>(brush).color().b());
      else {
        /*
          for (auto index  = 0; index <hotkey_prefix_locations.size(); ++index) {
            g.draw_string(text_without_hotkey_prefix.substring(hotkey_prefix_locations[index], 1), xtd::drawing::font(font, font_style::underline), solid_brush(text_color), button_rect, to_string_format(flags));
            auto chunk_size = (index+1 < hotkey_prefix_locations.size() ? hotkey_prefix_locations[index+1] : text_without_hotkey_prefix.size()) - hotkey_prefix_locations[index] - 1;
            g.draw_string(text_without_hotkey_prefi.substring(hotkey_prefix_locations[index], chunk_size), font, solid_brush(text_color), button_rect, to_string_format(flags));
          }
         */
        native::graphics::draw_string(data_->handle_, drawable_line, font.data_->handle_, static_cast<int32_t>(x), static_cast<int32_t>(y), static_cast<int32_t>(width), static_cast<int32_t>(height), static_cast<const solid_brush&>(brush).color().a(), static_cast<const solid_brush&>(brush).color().r(), static_cast<const solid_brush&>(brush).color().g(), static_cast<const solid_brush&>(brush).color().b());
      }
      
      y += line_size.height();
    }
  }
}

void graphics::fill_ellipse(const brush& brush, int32_t x, int32_t y, int32_t width, int32_t height) {
  native::graphics::fill_ellipse(data_->handle_, brush.data_->handle_, x, y, width, height);
}

void graphics::fill_pie(const brush& brush, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle) {
  native::graphics::fill_pie(data_->handle_, brush.data_->handle_, x, y, width, height, start_angle, sweep_angle);
}

void graphics::fill_rectangle(const brush& brush, int32_t x, int32_t y, int32_t width, int32_t height) {
  native::graphics::fill_rectangle(data_->handle_, brush.data_->handle_, x, y, width, height);
}

void graphics::fill_rounded_rectangle(const brush& brush, int32_t x, int32_t y, int32_t width, int32_t height, int32_t radius) {
  native::graphics::fill_rounded_rectangle(data_->handle_, brush.data_->handle_, x, y, width, height, radius);
}

graphics graphics::from_image(const image& image) {
  return graphics(native::graphics::from_image(image.handle()));
}

size_f graphics::measure_string(const ustring& text, const font& font) {
  int32_t width = 0;
  int32_t height = 0;
  native::graphics::measure_string(data_->handle_, text, font.handle(), width, height);
  return size_f(static_cast<float>(width), static_cast<float>(height));
}

void graphics::rotate_transform(float angle) {
  native::graphics::rotate_transform(data_->handle_, angle);
}

void graphics::translate_clip(int32_t dx, int32_t dy) {
  native::graphics::translate_clip(data_->handle_, dx, dy);
}
