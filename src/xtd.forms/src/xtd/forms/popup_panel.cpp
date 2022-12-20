#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/tab_control.h>
#include <xtd/forms/native/popup_panel.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/tab_control.h"
#include "../../../include/xtd/forms/popup_panel.h"

using namespace xtd;
using namespace xtd::forms;

struct popup_panel::data {
  bool ignore_mouse_messages = false;
};

popup_panel::popup_panel() : data_(std::make_shared<data>()) {
  visible(false);
}

bool popup_panel::ignore_mouse_messages() const noexcept {
  return data_->ignore_mouse_messages;
}

popup_panel& popup_panel::ignore_mouse_messages(bool value) {
  if (data_->ignore_mouse_messages != value) {
    data_->ignore_mouse_messages = value;
    native::popup_panel::ignore_mouse_messages(handle(), data_->ignore_mouse_messages);
  }
  return *this;
}

forms::create_params popup_panel::create_params() const noexcept {
  forms::create_params create_params = panel::create_params();
  
  create_params.class_name("popuppanel");
  
  return create_params;
}

void popup_panel::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  native::popup_panel::ignore_mouse_messages(handle(), data_->ignore_mouse_messages);
}

void popup_panel::on_layout(const event_args& e) {
  scrollable_control::on_layout(e);
  if (is_handle_created() && auto_scroll()) native::popup_panel::virtual_size(handle(), display_rectangle().size());
}

void popup_panel::on_region_changed(const event_args& e) {
  native::popup_panel::set_region(handle(), region().handle());
  control::on_region_changed(e);
}

void popup_panel::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_SHOWWINDOW: wm_show(message); break;
    default: panel::wnd_proc(message); break;
  }
}

void popup_panel::wm_show(message& message) {
  panel::wnd_proc(message);
  
  bool visible = message.lparam() != 0;
  if (get_state(state::visible) != visible) {
    set_state(state::visible, visible);
    on_visible_changed(event_args::empty);
  }
}
