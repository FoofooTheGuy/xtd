#include <xtd/as.h>
#include "../../../include/xtd/forms/link_label.h"
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/screen.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

link_label::link_collection::link_collection(const link_label::link_collection::allocator_type& allocator) : link_label::link_collection::base(allocator) {
}

link_label::link_collection::link_collection(const link_label::link_collection::base& collection) : link_label::link_collection::base(collection) {}
link_label::link_collection::link_collection(const link_label::link_collection& collection) : link_label::link_collection::base(collection) {}
link_label::link_collection& link_label::link_collection::operator=(const link_label::link_collection& collection) {
  base::operator=(collection);
  return *this;
}

link_label::link_collection::const_reference link_label::link_collection::operator[](const ustring& name) const {
  for(auto& item : *this)
    if(item.name() == name) return item;
  return empty_;
}

link_label::link_collection::reference link_label::link_collection::operator[](const ustring& name) {
  for(auto& item : *this)
    if(item.name() == name) return item;
  return empty_;
}

link_label::link_label() {
  active_link_color_ = application::dark_mode_enabled() ? color::from_argb(0xFFD03E3D) : xtd::drawing::color::red;
  disabled_link_color_ = application::dark_mode_enabled() ? xtd::drawing::color::from_argb(0xFF858585) : xtd::drawing::color::from_argb(0xFF858585);
  link_color_ = application::dark_mode_enabled() ? xtd::drawing::color::dodger_blue : xtd::drawing::color::blue;
  visited_link_color_ = application::dark_mode_enabled() ? xtd::drawing::color::light_sky_blue : xtd::drawing::color::purple;
  override_cursor_ = xtd::forms::cursors::hand();
  
  links_.item_added += [&] {
    if (links_.size() == 2 && links_[0].start() == 0 && links_[0].length() == text().length())
      links_.erase_at(0);
    //tab_stop(true);
    invalidate();
  };
  links_.item_removed += [&] {
    invalidate();
  };
  links_.item_updated += [&] {
    invalidate();
  };
}

const xtd::drawing::color& link_label::active_link_color() const {
  return active_link_color_;
}

link_label& link_label::active_link_color(const xtd::drawing::color& color) {
  if (active_link_color_ != color) {
    active_link_color_ = color;
    invalidate();
  }
  return *this;
}

const xtd::drawing::color& link_label::disabled_link_color() const {
  return disabled_link_color_;
}

link_label& link_label::disabled_link_color(const xtd::drawing::color& color) {
  if (active_link_color_ != color) {
    disabled_link_color_ = color;
    invalidate();
  }
  return *this;
}

const xtd::drawing::color& link_label::link_color() const {
  return link_color_;
}

link_label& link_label::link_color(const xtd::drawing::color& color) {
  if (link_color_ != color) {
    link_color_ = color;
    invalidate();
  }
  return *this;
}

const link_label::link_collection& link_label::links() const {
  return links_;
}

link_label::link_collection& link_label::links() {
  return links_;
}

const xtd::drawing::color& link_label::visited_link_color() const {
  return link_color_;
}

link_label& link_label::visited_link_color(const xtd::drawing::color& color) {
  if (visited_link_color_ != color) {
    visited_link_color_ = color;
    invalidate();
  }
  return *this;
}

drawing::size link_label::measure_control() const {
  rectangle bounds;
  for (auto [rect, is_link] : generate_text_rects())
    bounds = drawing::rectangle::make_union(bounds, rect);
  return bounds.size() + drawing::size(2, 1) + drawing::size(border_style_ == border_style::none ? 0 : 4, border_style_ == border_style::none ? 0 : 4);
}

void link_label::on_cursor_changed(const event_args &e) {
  label::on_cursor_changed(e);
  if (!mouse_hover_)
    original_cursor_ = cursor();
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
    link.active_ = true;
    invalidate();
  }
}

void link_label::on_mouse_up(const mouse_event_args& e) {
  label::on_mouse_up(e);
  if (!enabled()) return;
  for (auto& link : links_)
    link.active_ = false;
  invalidate();
}

void link_label::on_mouse_move(const mouse_event_args& e) {
  label::on_mouse_move(e);
  if (!enabled()) return;
  mouse_hover_ = true;
  auto& link = point_in_link(e.location());
  cursor(link != link_empty_ && link.enabled() ? override_cursor_ : original_cursor_);
  mouse_hover_ = false;
}

void link_label::on_paint(paint_event_args& e) {
  control::on_paint(e);
  
  size_t line_number = 0;
  size_t index = 0;
  for (auto line : text().split({'\n'})) {
    auto text_location = get_text_location(line_number);
    size_t line_index = 0;
    drawing::size size_text;
    ustring text;
    for (auto link : links_) {
      drawing::color color = link_color_;
      if (!link.enabled()) color = disabled_link_color_;
      else if (link.active_) color = active_link_color_;
      else if (link.visited()) color = visited_link_color_;

      if (index < link.start()) {
        text = line.substring(line_index, link.start() - line_index);
        size_text = drawing::size::ceiling(e.graphics().measure_string(text, font()));
        if (enabled())
          e.graphics().draw_string(text, font(), solid_brush(fore_color()), {text_location, size_text});
        else
          e.graphics().draw_string(text, font(), solid_brush(application::theme().theme_colors().gray_text()), {text_location, size_text});
        text_location.x(text_location.x() + size_text.width());
        line_index += text.length();
      }
      if (index <= link.start() && line.length() + index > link.start()) {
        text = line.substring(link.start() - index, link.length());
        size_text = drawing::size::ceiling(e.graphics().measure_string(text, link_font()));
        if (enabled())
          e.graphics().draw_string(text, link_font(), solid_brush(color), {text_location, size_text});
        else
          e.graphics().draw_string(text, link_font(), solid_brush(application::theme().theme_colors().gray_text()), {text_location, size_text});
        text_location.x(text_location.x() + size_text.width());
        line_index = link.start() - index + text.length();
      }
    }
    
    if (line_index < line.length()) {
      text = line.substring(line_index, line.length());
      size_text = drawing::size::ceiling(e.graphics().measure_string(text, font()));
      if (enabled())
        e.graphics().draw_string(text, font(), solid_brush(fore_color()), {text_location, size_text});
      else
        e.graphics().draw_string(text, font(), solid_brush(application::theme().theme_colors().gray_text()), {text_location, size_text});
      line_index = line.length();
    }
    index += line_index + 1;
    ++line_number;
  }
}

void link_label::on_text_align_changed(const event_args& e) {
  label::on_text_changed(e);
  invalidate();
}

void link_label::on_text_changed(const event_args& e) {
  if (links_.empty()) links_.push_back({0, text().length()});
  label::on_text_changed(e);
  invalidate();
}

link_label::link& link_label::point_in_link(const xtd::drawing::point& point) {
  size_t link_index = 0;
  for (auto [rect, is_link] : generate_text_rects())
    if (is_link) {
      if (rect.contains(point)) return links_[link_index];
      ++link_index;
    }

  return link_empty_;
}

xtd::drawing::point link_label::get_text_location(size_t line_number) const {
  size_t line_index = 0;
  for (auto line : text().split({'\n'})) {
    std::vector<std::tuple<xtd::drawing::rectangle, bool>> text_rects;
    point text_location;
    drawing::size text_size = drawing::size::ceiling(screen::create_graphics().measure_string(line, link_font()));
    switch (text_align_) {
      case content_alignment::top_left: text_location = point(0, text_size.height() * as<int32_t>(line_number)); break;
      case content_alignment::top_center: text_location = point(client_rectangle().width() / 2 - text_size.width() / 2, text_size.height() * as<int32_t>(line_number)); break;
      case content_alignment::top_right: text_location = point(client_rectangle().width() - text_size.width(), text_size.height() * as<int32_t>(line_number)); break;
      case content_alignment::middle_left: text_location = point(0, client_rectangle().height() / 2 - text_size.height() / 2 + text_size.height() * as<int32_t>(line_number)); break;
      case content_alignment::middle_center: text_location = point(client_rectangle().width() / 2 - text_size.width() / 2, client_rectangle().height() / 2 - text_size.height() / 2 + text_size.height() * as<int32_t>(line_number)); break;
      case content_alignment::middle_right: text_location = point(client_rectangle().width() - text_size.width(), client_rectangle().height() / 2 - text_size.height() / 2 + text_size.height() * as<int32_t>(line_number)); break;
      case content_alignment::bottom_left: text_location = point(0, client_rectangle().height() - text_size.height() + text_size.height() * as<int32_t>(line_number)); break;
      case content_alignment::bottom_center: text_location = point(client_rectangle().width() / 2 - text_size.width() / 2, client_rectangle().height() - text_size.height() + text_size.height() * as<int32_t>(line_number)); break;
      case content_alignment::bottom_right: text_location = point(client_rectangle().width() - text_size.width(), client_rectangle().height() - text_size.height() + text_size.height() * as<int32_t>(line_number)); break;
      default: break;
    }
    if (line_number == line_index) return text_location;
    ++line_index;
  }
  return {0, 0};
}
std::vector<std::tuple<xtd::drawing::rectangle, bool>> link_label::generate_text_rects() const {
  std::vector<std::tuple<xtd::drawing::rectangle, bool>> text_rects;
 
  size_t line_number = 0;
  size_t index = 0;
  for (auto line : text().split({'\n'})) {
    size_t line_index = 0;
    auto text_location = get_text_location(line_number);
    drawing::size size_text;
    ustring text;
    for (auto link : links_) {
      if (index < link.start()) {
        text = line.substring(line_index, link.start() - line_index);
        size_text = drawing::size::ceiling(screen::create_graphics().measure_string(text, font()));
        text_rects.push_back({{text_location, size_text}, false});
        text_location.x(text_location.x() + size_text.width());
        line_index += text.length();
      }
      if (index <= link.start() && line.length() + index > link.start()) {
        text = line.substring(link.start() - index, link.length());
        size_text = drawing::size::ceiling(screen::create_graphics().measure_string(text, link_font()));
        text_rects.push_back({{text_location, size_text}, true});
        text_location.x(text_location.x() + size_text.width());
        line_index = link.start() - index + text.length();
      }
    }
    
    if (line_index < line.length()) {
      text = line.substring(line_index, line.length());
      size_text = drawing::size::ceiling(screen::create_graphics().measure_string(text, font()));
      text_rects.push_back({{text_location, size_text}, false});
      line_index = line.length();
    }
    index += line_index + 1;
    ++line_number;
  }

  return text_rects;
}

xtd::drawing::font link_label::link_font() const {
  return {font(), xtd::drawing::font_style::underline};
}
