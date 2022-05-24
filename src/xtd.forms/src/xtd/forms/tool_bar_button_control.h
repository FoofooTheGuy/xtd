#pragma once
#include "../../../include/xtd/forms/tool_bar.h"

class xtd::forms::tool_bar::tool_bar_button_control : public xtd::forms::button {
public:
  tool_bar_button_control() {
    set_can_focus(false);
    flat_style(xtd::forms::flat_style::flat);
  }
  
  void control(const xtd::forms::control* value){
    if (data_->control != value) {
      data_->control = value;
      update_size();
      update_layout();
    }
  }
  
  xtd::drawing::font default_font() const override {return xtd::drawing::system_fonts::toolbar_font();}
  
  void drop_down_menu(xtd::forms::context_menu* value) {
    if (data_->drop_down_menu != value) {
      data_->drop_down_menu = value;
      update_size();
      update_layout();
    }
  }
  
  void flat(bool value) {
    if (data_->flat != value) {
      data_->flat = value;
      update_size();
      update_layout();
    }
  }
  
  using xtd::forms::button_base::image;
  button_base& image(const xtd::drawing::image& value) override {
    if (image() != value) {
      button_base::image(value);
      update_size();
      update_layout();
    }
    return *this;
  }
  
  const xtd::drawing::size& image_size() const {return data_->image_size;}
  
  void image_size(const xtd::drawing::size& value) {
    if (data_->image_size != value) {
      data_->image_size = value;
      update_size();
      update_layout();
    }
  }
  
  bool is_horizontal() const {return dock() == dock_style::left || dock() == dock_style::right;}
  
  void pushed(bool value) {
    if (data_->pushed != value) {
      data_->pushed = value;
      update_size();
      update_layout();
    }
  }
  
  void show_icon(bool value) {
    if (data_->show_icon != value) {
      data_->show_icon = value;
      update_size();
      update_layout();
    }
  }
  
  void show_text(bool value) {
    if (data_->show_text != value) {
      data_->show_text = value;
      update_size();
      update_layout();
    }
  }
  
  xtd::drawing::size size() const override {return control::size();}
  
  xtd::forms::control& size(const xtd::drawing::size& value) override {
    if (size() != value) {
      control::size(value);
      update_size();
      update_layout();
    }
    return *this;
  }
  
  xtd::forms::tool_bar_button_style style() const {return data_->style;}
  
  void style(xtd::forms::tool_bar_button_style value) {
    if (data_->style != value) {
      data_->style = value;
      update_size();
      update_layout();
    }
  }
  
  using xtd::forms::control::text;
  xtd::forms::control& text(const xtd::ustring& value) override {
    if (text() != value) {
      button_base::text(value);
      update_size();
      update_layout();
    }
    return *this;
  }
  
  void tool_bar_text_align(xtd::forms::tool_bar_text_align value) {
    if (data_->tool_bar_text_align != value) {
      data_->tool_bar_text_align = value;
      update_size();
      update_layout();
    }
  }
  
  void tool_bar_button(tool_bar_button_ref value) {data_->tool_bar_button = value;}
  
protected:
  void on_click(const xtd::event_args& e) override {
    button::on_click(e);
    if (data_->style == tool_bar_button_style::drop_down_button && drop_down_rectangle().contains(point_to_client(mouse_position()))) {
      if (data_->drop_down_menu) data_->drop_down_menu->show(parent().value().get(), xtd::drawing::point(left(), bottom() + 2));
      data_->mouse_on_drop_down_menu = false;
      data_->mouse_down_on_drop_down_menu = false;
      invalidate();
    } else {
      if (data_->tool_bar_button.has_value()) {
        if (data_->style == tool_bar_button_style::toggle_button) {
          data_->pushed = !data_->pushed;
          data_->tool_bar_button.value().get().pushed(data_->pushed);
        }
        if (data_->style != tool_bar_button_style::separator && data_->style != tool_bar_button_style::stretchable_separator && data_->style != tool_bar_button_style::control && parent().has_value())
          as<tool_bar>(parent().value().get()).on_button_click(xtd::forms::tool_bar_button_click_event_args(data_->tool_bar_button.value().get()));
      }
    }
  }
  
  void on_mouse_down(const mouse_event_args& e) override {
    if (e.button() == mouse_buttons::left && data_->style == tool_bar_button_style::drop_down_button && drop_down_rectangle().contains(e.location())) {
      data_->mouse_down_on_drop_down_menu = true;
      invalidate();
    } else
      button::on_mouse_down(e);
  }
  
  void on_mouse_enter(const event_args& e) override {
    data_->mouse_on_drop_down_menu = data_->style == tool_bar_button_style::drop_down_button && drop_down_rectangle().contains(point_to_client(mouse_position()));
    button::on_mouse_enter(e);
  }
  
  void on_mouse_leave(const event_args& e) override {
    data_->mouse_on_drop_down_menu = false;
    data_->mouse_down_on_drop_down_menu = false;
    button::on_mouse_leave(e);
  }
  
  void on_mouse_move(const mouse_event_args& e) override {
    auto mouse_on_drop_down_menu = data_->style == tool_bar_button_style::drop_down_button && drop_down_rectangle().contains(e.location());
    if (data_->mouse_on_drop_down_menu != mouse_on_drop_down_menu) {
      data_->mouse_on_drop_down_menu = mouse_on_drop_down_menu;
      invalidate();
    }
    xtd::forms::button::on_mouse_move(e);
  }
  
  void on_mouse_up(const mouse_event_args& e) override {
    if (e.button() == mouse_buttons::left && data_->style == tool_bar_button_style::drop_down_button) {
      data_->mouse_down_on_drop_down_menu = false;
      invalidate();
    }
    button::on_mouse_up(e);
  }
  
  void on_paint(paint_event_args& e) override {
    if (data_->style == tool_bar_button_style::push_button) draw_push_button(e);
    else if (data_->style == tool_bar_button_style::toggle_button) draw_toggle_button(e);
    else if (data_->style == tool_bar_button_style::separator) draw_separator(e);
    else if (data_->style == tool_bar_button_style::drop_down_button) draw_drop_down_button(e);
    else if (data_->style == tool_bar_button_style::stretchable_separator) draw_stretchable_separator(e);
    else if (data_->style == tool_bar_button_style::control) draw_control(e);
    control::on_paint(e);
  }
  
private:
  friend tool_bar;
  
  void draw_push_button(xtd::forms::paint_event_args& e) {
    auto style = style_sheet() != style_sheets::style_sheet::empty ? style_sheet() : style_sheets::style_sheet::current_style_sheet();
    tool_bar_button_renderer::draw_tool_bar_button(style, e.graphics(), e.clip_rectangle(), state(), back_color() != default_back_color() ? std::optional<drawing::color> {back_color()} : std::nullopt, flat_appearance(), text(), text_align(), fore_color() != default_fore_color() ? std::optional<drawing::color> {fore_color()} : std::nullopt, font(), image(), image_align());
  }
  
  void draw_toggle_button(xtd::forms::paint_event_args& e) {
    auto style = style_sheet() != style_sheets::style_sheet::empty ? style_sheet() : style_sheets::style_sheet::current_style_sheet();
    tool_bar_button_renderer::draw_tool_bar_button(style, e.graphics(), e.clip_rectangle(), data_->pushed ? visual_styles::push_button_state::checked : state(), back_color() != default_back_color() ? std::optional<drawing::color> {back_color()} : std::nullopt, flat_appearance(), text(), text_align(), fore_color() != default_fore_color() ? std::optional<drawing::color> {fore_color()} : std::nullopt, font(), image(), image_align());
  }
  
  void draw_drop_down_button(xtd::forms::paint_event_args& e) {
    auto style = style_sheet() != style_sheets::style_sheet::empty ? style_sheet() : style_sheets::style_sheet::current_style_sheet();
    auto button_rect = e.clip_rectangle();
    button_rect.width(button_rect.width() - drop_down_rectangle().width());
    visual_styles::push_button_state current_state = state();
    if (data_->mouse_on_drop_down_menu) current_state = visual_styles::push_button_state::normal;
    tool_bar_button_renderer::draw_tool_bar_button(style, e.graphics(), button_rect, current_state, back_color() != default_back_color() ? std::optional<drawing::color> {back_color()} : std::nullopt, flat_appearance(), text(), text_align(), fore_color() != default_fore_color() ? std::optional<drawing::color> {fore_color()} : std::nullopt, font(), image(), image_align());
    xtd::forms::style_sheets::tool_bar_button current_style_sheet = style.tool_bar_button(xtd::forms::style_sheets::pseudo_state::standard);
    if (data_->mouse_on_drop_down_menu) current_style_sheet = style.tool_bar_button(xtd::forms::style_sheets::pseudo_state::hover);
    if (data_->mouse_down_on_drop_down_menu) current_style_sheet = style.tool_bar_button(xtd::forms::style_sheets::pseudo_state::pressed);
    auto center_drop_down = xtd::drawing::point(e.clip_rectangle().right() - drop_down_rectangle().width() / 2, e.clip_rectangle().top() + drop_down_rectangle().height() / 2);
    auto drop_down_size = drawing::size(drop_down_rectangle().width() - 4, (drop_down_rectangle().width() - 4) / 2);
    box_renderer::draw_box(e.graphics(), drop_down_rectangle(), current_style_sheet);
    e.graphics().fill_polygon(xtd::drawing::solid_brush(current_style_sheet.color()), std::vector<xtd::drawing::point> {xtd::drawing::point {center_drop_down.x() - drop_down_size.width() / 2, center_drop_down.y() - drop_down_size.height() / 2}, xtd::drawing::point {center_drop_down.x() + drop_down_size.width() / 2, center_drop_down.y() - drop_down_size.height() / 2}, xtd::drawing::point {center_drop_down.x(), center_drop_down.y() + drop_down_size.height() / 2} });
  }
  
  void draw_separator(xtd::forms::paint_event_args& e) {
    if (data_->flat) {
      auto percent_of_color = 1.0 / 6;
      auto color = back_color().get_lightness() < 0.5 ? xtd::forms::control_paint::light(back_color(), percent_of_color) : xtd::forms::control_paint::dark(back_color(), percent_of_color);
      if (is_horizontal()) {
        auto left = image_size().width() / 4;
        auto top = 4;
        auto right = left;
        auto bottom = e.clip_rectangle().height() - 4;
        e.graphics().draw_line(xtd::drawing::pen {color}, xtd::drawing::point {left, top}, xtd::drawing::point {right, bottom});
      } else {
        auto left = 4;
        auto top = image_size().height() / 4;
        auto right = e.clip_rectangle().width() - 4;
        auto bottom = top;
        e.graphics().draw_line(xtd::drawing::pen {color}, xtd::drawing::point {left, top}, xtd::drawing::point {right, bottom});
      }
    }
  }
  
  void draw_stretchable_separator(xtd::forms::paint_event_args& e) {
    draw_separator(e);
  }
  
  void draw_control(xtd::forms::paint_event_args& e) {
    auto style = style_sheet() != style_sheets::style_sheet::empty ? style_sheet() : style_sheets::style_sheet::current_style_sheet();
    xtd::forms::style_sheets::tool_bar_button current_style_sheet = style.tool_bar_button(xtd::forms::style_sheets::pseudo_state::standard);
    current_style_sheet.font(font());
    xtd::drawing::rectangle text_rect = current_style_sheet.get_content_rectangle(e.clip_rectangle());
    if (data_->show_text == true && data_->tool_bar_text_align == tool_bar_text_align::right) {
      if (data_->control) text_rect.width(text_rect.width() - data_->control->width() - 4);
      if (data_->control) text_rect.x(text_rect.x() + data_->control->width() + 4);
    } else {
      text_rect.height(measure_text().height());
      text_rect.y(height() - measure_text().height() - 3);
    }
    text_renderer::draw_text(e.graphics(), text_rect, text(), current_style_sheet);
  }
  
  xtd::drawing::rectangle drop_down_rectangle() const {
    if (data_->style != tool_bar_button_style::drop_down_button) return {};
    return {width() - 16, 0, 16, height()};
  }
  
  void update_layout() {
    if (data_->show_text == false) {
      image_align(content_alignment::middle_center);
    } else if (data_->show_text == true && data_->show_icon == false) {
      text_align(content_alignment::middle_center);
    } else if (data_->show_text == true && data_->show_icon == true && data_->tool_bar_text_align == tool_bar_text_align::right) {
      image_align(content_alignment::middle_left);
      text_align(content_alignment::middle_left);
    }  else {
      image_align(content_alignment::top_center);
      text_align(content_alignment::bottom_center);
    }
  }
  
  void update_size() {
    auto size = this->size();
    auto text_size = measure_text();
    auto drop_down_size = drop_down_rectangle().size();
    
    if (data_->style == tool_bar_button_style::control && data_->control) {
      if (size.height() < data_->control->height()) size.height(data_->control->height());
      if (size.width() < data_->control->width()) size.width(data_->control->width());
      
      if (data_->show_text == true && data_->tool_bar_text_align == tool_bar_text_align::right) {
        if (size.width() < (data_->control->size().width() + text_size.width() + 6)) size.width(data_->control->size().width() + text_size.width() + 6);
        if (size.height() < text_size.height()) size.height(text_size.height());
        const_cast<xtd::forms::control*>(data_->control)->location({(size.width() - data_->control->width() - text_size.width()) / 2, (size.height() - data_->control->height()) / 2});
      } else if (data_->show_text == true && data_->tool_bar_text_align == tool_bar_text_align::underneath) {
        if (size.width() < text_size.width()) size.width(text_size.width());
        if (size.height() < (data_->control->size().height() + text_size.height() + 6)) size.height(data_->control->size().height() + text_size.height() + 6);
        const_cast<xtd::forms::control*>(data_->control)->location({(size.width() - data_->control->width()) / 2, (size.height() - data_->control->height() - text_size.height()) / 2});
      } else
        const_cast<xtd::forms::control*>(data_->control)->location({(size.width() - data_->control->width()) / 2, (size.height() - data_->control->height()) / 2});
    } else if (data_->style != tool_bar_button_style::separator && data_->style != tool_bar_button_style::stretchable_separator) {
      if (data_->show_text == false) {
        if (size.width() < image_size().width() + drop_down_size.width()) size.width(image_size().width() + drop_down_size.width() + 12);
        if (size.height() < image_size().height()) size.height(image_size().height() + 12);
      } else if (data_->show_text == true && data_->show_icon == false) {
        if (size.width() < text_size.width() + drop_down_size.width()) size.width(text_size.width() + drop_down_size.width());
        if (size.height() < text_size.height()) size.height(text_size.height());
      } else if (data_->show_text == true && data_->show_icon == true && data_->tool_bar_text_align == tool_bar_text_align::right) {
        if (size.width() < (image_size().width() + text_size.width() + drop_down_size.width() + 4)) size.width(image_size().width() + text_size.width() + drop_down_size.width() + 4);
        if (size.height() < text_size.height()) size.height(text_size.height());
      }  else {
        if (size.width() < text_size.width() + drop_down_size.width()) size.width(text_size.width() + drop_down_size.width());
        if (size.height() < (image_size().height() + text_size.height() + 6)) size.height(image_size().height() + text_size.height() + 6);
      }
    }
    this->size(size);
  }
  
  struct data {
    const xtd::forms::control* control = nullptr;
    xtd::forms::context_menu* drop_down_menu = nullptr;
    xtd::drawing::size image_size;
    std::optional<tool_bar_button_ref> tool_bar_button;
    bool mouse_on_drop_down_menu = false;
    bool mouse_down_on_drop_down_menu = false;
    bool flat = false;
    bool show_icon = true;
    bool show_text = false;
    bool pushed = false;
    xtd::forms::tool_bar_button_style style = xtd::forms::tool_bar_button_style::push_button;
    xtd::forms::tool_bar_text_align tool_bar_text_align = xtd::forms::tool_bar_text_align::underneath;
  };
  
  std::shared_ptr<data> data_ = std::make_shared<data>();
};
