#include <xtd/as.h>
#include "../../../include/xtd/forms/link_label.h"
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/control_paint.h"
#include "../../../include/xtd/forms/screen.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/toolkit.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

link_label::link_collection::link_collection(const link_label::link_collection::allocator_type& allocator) : link_label::link_collection::base(allocator) {
}

link_label::link_collection::link_collection(const link_label::link_collection::base& collection) : link_label::link_collection::base(collection) {}
link_label::link_collection::link_collection(const link_label::link_collection& collection) : link_label::link_collection::base(collection) {}
link_label::link_collection& link_label::link_collection::operator =(const link_label::link_collection& collection) {
  base::operator =(collection);
  return *this;
}

link_label::link_collection::const_reference link_label::link_collection::operator [](const ustring& name) const noexcept {
  for (auto& item : *this)
    if (item.name() == name) return item;
  return empty_;
}

link_label::link_collection::reference link_label::link_collection::operator [](const ustring& name) noexcept {
  for (auto& item : *this)
    if (item.name() == name) return item;
  return empty_;
}

link_label::link_label() {
  double_buffered(true);
  set_style(control_styles::all_painting_in_wm_paint | control_styles::optimized_double_buffer | control_styles::opaque | control_styles::user_paint | control_styles::standard_click | control_styles::resize_redraw, true);
  data_->links.item_added += [&] {
    if (data_->links.size() == 2 && data_->links[0].start() == 0 && data_->links[0].length() == text().length())
      data_->links.erase_at(0);
    //tab_stop(true);
    invalidate();
  };
  data_->links.item_removed += [&] {
    invalidate();
  };
  data_->links.item_updated += [&] {
    invalidate();
  };
}

xtd::drawing::color link_label::active_link_color() const noexcept {
  return data_->active_link_color.value_or(xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().active_text());
}

link_label& link_label::active_link_color(const xtd::drawing::color& color) {
  if (data_->active_link_color != color) {
    data_->active_link_color = color;
    invalidate();
  }
  return *this;
}

xtd::drawing::color link_label::disabled_link_color() const noexcept {
  return data_->disabled_link_color.value_or(xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().gray_text());;
}

link_label& link_label::disabled_link_color(const xtd::drawing::color& color) {
  if (data_->active_link_color != color) {
    data_->disabled_link_color = color;
    invalidate();
  }
  return *this;
}

xtd::forms::link_area link_label::link_area() const noexcept {
  return data_->link_area;
}

link_label& link_label::link_area(xtd::forms::link_area value) {
  if (data_->link_area != value) {
    data_->link_area = value;
    invalidate();
  }
  return *this;
}

xtd::forms::link_behavior link_label::link_behavior() const noexcept {
  return data_->link_behavior;
}

link_label& link_label::link_behavior(xtd::forms::link_behavior value) {
  if (data_->link_behavior != value) {
    data_->link_behavior = value;
    invalidate();
  }
  return *this;
}

xtd::drawing::color link_label::link_color() const noexcept {
  return data_->link_color.value_or(xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().link_text());;
}

link_label& link_label::link_color(const xtd::drawing::color& color) {
  if (data_->link_color != color) {
    data_->link_color = color;
    invalidate();
  }
  return *this;
}

const link_label::link_collection& link_label::links() const noexcept {
  return data_->links;
}

link_label::link_collection& link_label::links() {
  return data_->links;
}

xtd::forms::cursor link_label::override_cursor() const noexcept {
  return data_->override_cursor.value_or(xtd::forms::cursors::hand());
}

link_label& link_label::override_cursor(const xtd::forms::cursor& cursor) {
  data_->override_cursor = cursor;
  return *this;
}

xtd::drawing::color link_label::visited_link_color() const noexcept {
  return data_->visited_link_color.value_or(xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().visited_text());;
}

link_label& link_label::visited_link_color(const xtd::drawing::color& color) {
  if (data_->visited_link_color != color) {
    data_->visited_link_color = color;
    invalidate();
  }
  return *this;
}

drawing::size link_label::measure_control() const noexcept {
  rectangle bounds;
  for (auto [rect, is_link] : generate_text_rects())
    bounds = drawing::rectangle::make_union(bounds, rect);
  return bounds.size() + drawing::size(2, 1) + drawing::size(border_style() == border_style::none ? 0 : 4, border_style() == border_style::none ? 0 : 4);
}

void link_label::on_cursor_changed(const event_args& e) {
  label::on_cursor_changed(e);
  if (!data_->mouse_hover)
    data_->original_cursor = cursor();
}

void link_label::on_mouse_click(const mouse_event_args& e) {
  label::on_mouse_click(e);
  if (!enabled()) return;
  auto& link = point_in_link(e.location());
  if (link != link_empty_ && link.enabled()) {
    link_label_clicked_event_args args(link, e.button());
    link_clicked(*this, args);
    if (args.visited()) {
      link.visited(true);
      invalidate();
    }
  }
}

void link_label::on_mouse_down(const mouse_event_args& e) {
  label::on_mouse_down(e);
  if (!enabled()) return;
  auto& link = point_in_link(e.location());
  if (link != link_empty_) {
    link.data_->active = true;
    invalidate();
  }
}

void link_label::on_mouse_up(const mouse_event_args& e) {
  label::on_mouse_up(e);
  if (!enabled()) return;
  for (auto& link : data_->links)
    link.data_->active = false;
  invalidate();
}

void link_label::on_mouse_move(const mouse_event_args& e) {
  label::on_mouse_move(e);
  if (!enabled()) return;
  data_->mouse_hover = true;
  auto& link = point_in_link(e.location());
  cursor(link != link_empty_ && link.enabled() ? override_cursor() : data_->original_cursor);
  data_->mouse_hover = false;
}

void link_label::on_paint(paint_event_args& e) {
  control::on_paint(e);
  if (control_appearance() == forms::control_appearance::system) return;
  
  if (native::toolkit::is_operating_system_double_buffered() || double_buffered())
    e.graphics().clear(back_color());
  size_t line_number = 0;
  size_t index = 0;
  for (auto line : text().split({'\n'})) {
    auto text_location = get_text_location(line_number);
    size_t line_index = 0;
    drawing::size size_text;
    ustring text;
    for (auto link : data_->links) {
      drawing::color color = link_color();
      if (!link.enabled()) color = disabled_link_color();
      else if (link.data_->active) color = active_link_color();
      else if (link.visited()) color = visited_link_color();
      
      if (index < link.start()) {
        text = line.substring(line_index, link.start() - line_index);
        size_text = drawing::size::ceiling(e.graphics().measure_string(text, font(), size_f(0.0f, 0.0f), string_format(string_format_flags::measure_trailing_spaces)));
        if (enabled())
          e.graphics().draw_string(text, font(), solid_brush(fore_color()), {text_location, size_text});
        else
          e.graphics().draw_string(text, font(), solid_brush(application::style_sheet().system_colors().gray_text()), {text_location, size_text});
        text_location.x(text_location.x() + size_text.width());
        line_index += text.length();
      }
      if (index <= link.start() && line.length() + index > link.start()) {
        text = line.substring(link.start() - index, link.length());
        size_text = drawing::size::ceiling(e.graphics().measure_string(text, link_font(), size_f(0.0f, 0.0f), string_format(string_format_flags::measure_trailing_spaces)));
        if (enabled())
          e.graphics().draw_string(text, link_font(), solid_brush(color), {text_location, size_text});
        else
          e.graphics().draw_string(text, link_font(), solid_brush(application::style_sheet().system_colors().gray_text()), {text_location, size_text});
        text_location.x(text_location.x() + size_text.width());
        line_index = link.start() - index + text.length();
      }
    }
    
    if (line_index < line.length()) {
      text = line.substring(line_index, line.length());
      size_text = drawing::size::ceiling(e.graphics().measure_string(text, font(), size_f(0.0f, 0.0f), string_format(string_format_flags::measure_trailing_spaces)));
      if (enabled())
        e.graphics().draw_string(text, font(), solid_brush(fore_color()), {text_location, size_text});
      else
        e.graphics().draw_string(text, font(), solid_brush(style_sheet().system_colors().gray_text()), {text_location, size_text});
      line_index = line.length();
    }
    index += line_index + 1;
    ++line_number;
  }
  control_paint::draw_border_from_back_color(*this, e.graphics(), border_style(), border_sides(), back_color(), e.clip_rectangle());
}

void link_label::on_text_align_changed(const event_args& e) {
  label::on_text_changed(e);
  invalidate();
}

void link_label::on_text_changed(const event_args& e) {
  if (data_->links.empty()) data_->links.push_back({0, text().length()});
  label::on_text_changed(e);
  invalidate();
}

link_label::link& link_label::point_in_link(const xtd::drawing::point& point) {
  size_t link_index = 0;
  for (auto [rect, is_link] : generate_text_rects())
    if (is_link) {
      if (rect.contains(point)) return data_->links[link_index];
      ++link_index;
    }
    
  return link_empty_;
}

xtd::drawing::point link_label::get_text_location(size_t line_number) const noexcept {
  size_t line_index = 0;
  for (auto line : text().split({'\n'})) {
    point text_location;
    drawing::size text_size = drawing::size::ceiling(screen::create_graphics().measure_string(line, link_font(), size_f(0.0f, 0.0f), string_format(string_format_flags::measure_trailing_spaces)));
    switch (text_align()) {
      case content_alignment::top_left: text_location = point(0, text_size.height() * as<int32>(line_number)); break;
      case content_alignment::top_center: text_location = point(client_rectangle().width() / 2 - text_size.width() / 2, text_size.height() * as<int32>(line_number)); break;
      case content_alignment::top_right: text_location = point(client_rectangle().width() - text_size.width(), text_size.height() * as<int32>(line_number)); break;
      case content_alignment::middle_left: text_location = point(0, client_rectangle().height() / 2 - text_size.height() / 2 + text_size.height() * as<int32>(line_number)); break;
      case content_alignment::middle_center: text_location = point(client_rectangle().width() / 2 - text_size.width() / 2, client_rectangle().height() / 2 - text_size.height() / 2 + text_size.height() * as<int32>(line_number)); break;
      case content_alignment::middle_right: text_location = point(client_rectangle().width() - text_size.width(), client_rectangle().height() / 2 - text_size.height() / 2 + text_size.height() * as<int32>(line_number)); break;
      case content_alignment::bottom_left: text_location = point(0, client_rectangle().height() - text_size.height() + text_size.height() * as<int32>(line_number)); break;
      case content_alignment::bottom_center: text_location = point(client_rectangle().width() / 2 - text_size.width() / 2, client_rectangle().height() - text_size.height() + text_size.height() * as<int32>(line_number)); break;
      case content_alignment::bottom_right: text_location = point(client_rectangle().width() - text_size.width(), client_rectangle().height() - text_size.height() + text_size.height() * as<int32>(line_number)); break;
      default: break;
    }
    if (line_number == line_index) return text_location;
    ++line_index;
  }
  return {0, 0};
}

std::vector<std::tuple<xtd::drawing::rectangle, bool>> link_label::generate_text_rects() const noexcept {
  std::vector<std::tuple<xtd::drawing::rectangle, bool>> text_rects;
  size_t line_number = 0;
  size_t index = 0;
  for (auto line : text().split({'\n'})) {
    size_t line_index = 0;
    auto text_location = get_text_location(line_number);
    drawing::size size_text;
    ustring text;
    for (auto link : data_->links) {
      if (index < link.start()) {
        text = line.substring(line_index, link.start() - line_index);
        size_text = drawing::size::ceiling(screen::create_graphics().measure_string(text, font(), size_f(0.0f, 0.0f), string_format(string_format_flags::measure_trailing_spaces)));
        text_rects.push_back({{text_location, size_text}, false});
        text_location.x(text_location.x() + size_text.width());
        line_index += text.length();
      }
      if (index <= link.start() && line.length() + index > link.start()) {
        text = line.substring(link.start() - index, link.length());
        size_text = drawing::size::ceiling(screen::create_graphics().measure_string(text, link_font(), size_f(0.0f, 0.0f), string_format(string_format_flags::measure_trailing_spaces)));
        text_rects.push_back({{text_location, size_text}, true});
        text_location.x(text_location.x() + size_text.width());
        line_index = link.start() - index + text.length();
      }
    }
    
    if (line_index < line.length()) {
      text = line.substring(line_index, line.length());
      size_text = drawing::size::ceiling(screen::create_graphics().measure_string(text, font(), size_f(0.0f, 0.0f), string_format(string_format_flags::measure_trailing_spaces)));
      text_rects.push_back({{text_location, size_text}, false});
      line_index = line.length();
    }
    index += line_index + 1;
    ++line_number;
  }
  
  return text_rects;
}

xtd::drawing::font link_label::link_font() const noexcept {
  return {font(), xtd::drawing::font_style::underline};
}
