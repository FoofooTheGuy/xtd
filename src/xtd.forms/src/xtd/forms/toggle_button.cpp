#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/button_states.h>
#include <xtd/forms/native/button_styles.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/toggle_button.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/window_messages.h>
#include "../../../include/xtd/forms/toggle_button.h"
#include "../../../include/xtd/forms/toggle_button_renderer.h"
#include "../../../include/xtd/forms/visual_styles/push_button_state.h"

using namespace xtd;
using namespace xtd::forms;

toggle_button& toggle_button::auto_check(bool auto_check) {
  auto_check_ = auto_check;
  return *this;
}

toggle_button& toggle_button::checked(bool checked) {
  check_state(checked ? forms::check_state::checked : forms::check_state::unchecked);
  return *this;
}

toggle_button& toggle_button::check_align(content_alignment check_align) {
  if (check_align_ != check_align) {
    check_align_ = check_align;
    post_recreate_handle();
  }
  return *this;
}

toggle_button& toggle_button::check_state(forms::check_state check_state) {
  if (check_state_ != check_state) {
    check_state_ = check_state;
    if (checked_ != (check_state_ != forms::check_state::unchecked)) {
      checked_ = check_state_ != forms::check_state::unchecked;
      on_checked_changed(event_args::empty);
    }
    if (is_handle_created() && flat_style() == flat_style::system) native::toggle_button::check_state(handle(), static_cast<int32_t>(check_state_));
    on_check_state_changed(event_args::empty);
  }
  return *this;
}

toggle_button& toggle_button::three_state(bool three_state) {
  if (three_state_ != three_state) {
    three_state_ = three_state;
    post_recreate_handle();
  }
  return *this;
}

forms::create_params toggle_button::create_params() const {
  forms::create_params create_params = button_base::create_params();
  
  create_params.class_name("togglebutton");
  if (three_state_) create_params.style(create_params.style() | (auto_check_ ? BS_AUTO3STATE : BS_3STATE));
  else if (auto_check_) create_params.style(create_params.style() | BS_AUTOCHECKBOX);
  else create_params.style(create_params.style() | BS_CHECKBOX);
  create_params.style(create_params.style() | BS_PUSHLIKE);
  
  switch (check_align_) {
    case content_alignment::top_right:
    case content_alignment::middle_right:
    case content_alignment::bottom_right: create_params.style(create_params.style() | BS_RIGHTBUTTON); break;
    default: break;
  }
  
  return create_params;
}

drawing::size toggle_button::measure_control() const {
  return button_base::measure_text() + drawing::size(18, 0);
}

void toggle_button::on_handle_created(const event_args& e) {
  button_base::on_handle_created(e);
  if (flat_style() == flat_style::system) native::toggle_button::check_state(handle(), static_cast<int32_t>(check_state_));
  if (flat_style() != xtd::forms::flat_style::system && check_state_ != xtd::forms::check_state::unchecked) invalidate();
}

void toggle_button::on_paint(paint_event_args& e) {
  auto style = style_sheet() != style_sheets::style_sheet::empty ? style_sheet() : style_sheets::style_sheet::current_style_sheet();
  if (flat_style() == xtd::forms::flat_style::standard) toggle_button_renderer::draw_toggle_button(style, e.graphics(), e.clip_rectangle(), state(), back_color() != default_back_color() ? std::optional<drawing::color> {back_color()} : std::nullopt, text(), text_align(), fore_color() != default_fore_color() ? std::optional<drawing::color> {fore_color()} : std::nullopt, font() != default_font() ? std::optional<drawing::font> {font()} : std::nullopt, image(), image_align());
  if (flat_style() == xtd::forms::flat_style::flat) toggle_button_renderer::draw_flat_toggle_button(style, e.graphics(), e.clip_rectangle(), state(), back_color() != default_back_color() ? std::optional<drawing::color> {back_color()} : std::nullopt, flat_appearance(), text(), text_align(), fore_color() != default_fore_color() ? std::optional<drawing::color> {fore_color()} : std::nullopt, font() != default_font() ? std::optional<drawing::font> {font()} : std::nullopt, image(), image_align());
  if (flat_style() == xtd::forms::flat_style::popup) toggle_button_renderer::draw_popup_toggle_button(style, e.graphics(), e.clip_rectangle(), state(), back_color() != default_back_color() ? std::optional<drawing::color> {back_color()} : std::nullopt, flat_appearance(), text(), text_align(), fore_color() != default_fore_color() ? std::optional<drawing::color> {fore_color()} : std::nullopt, font() != default_font() ? std::optional<drawing::font> {font()} : std::nullopt, image(), image_align());
  button_base::on_paint(e);
}

void toggle_button::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_LBUTTONDOWN: wm_mouse_down(message); break;
    case WM_LBUTTONUP: wm_mouse_up(message); break;
    case WM_LBUTTONDBLCLK: wm_mouse_double_click(message); break;
    default: button_base::wnd_proc(message);
  }
}

void toggle_button::wm_mouse_double_click(message& message) {
  on_double_click(event_args::empty);
}

void toggle_button::wm_mouse_down(message& message) {
  set_state(control::state::double_click_fired, message.msg() == WM_LBUTTONDBLCLK || message.msg() == WM_RBUTTONDBLCLK || message.msg() == WM_MBUTTONDBLCLK || message.msg() == WM_XBUTTONDBLCLK);
  mouse_event_args e = mouse_event_args::create(message, get_state(state::double_click_fired));
  set_mouse_buttons(mouse_buttons() | e.button());
  on_mouse_down(e);
}

void toggle_button::wm_mouse_up(message& message) {
  if (auto_check_)
    switch (check_state()) {
      case forms::check_state::unchecked: check_state(forms::check_state::checked); break;
      case forms::check_state::checked: check_state(three_state() ? forms::check_state::indeterminate : forms::check_state::unchecked); break;
      case forms::check_state::indeterminate: check_state(forms::check_state::unchecked); break;
    }
  mouse_event_args e = mouse_event_args::create(message);
  set_mouse_buttons(mouse_buttons() & ~e.button());
  if (client_rectangle().contains(e.location())) on_click(event_args::empty);
  on_mouse_click(e);
  on_mouse_up(e);
}
