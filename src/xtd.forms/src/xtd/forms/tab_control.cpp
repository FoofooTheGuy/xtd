#include <xtd/as.h>
#include <xtd/environment.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/tab_control.h>
#include <xtd/forms/native/tab_page.h>
#include <xtd/forms/native/tab_control_styles.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/tab_control.h"
#include "../../../include/xtd/forms/tab_page.h"

using namespace xtd;
using namespace xtd::forms;

tab_control::tab_control() {
  control_appearance(forms::control_appearance::system);
  set_style(control_styles::user_paint, false);
}

tab_alignment tab_control::alignment() const noexcept {
  return data_->alignment;
}

tab_control& tab_control::alignment(tab_alignment alignment) {
  if (data_->alignment != alignment) {
    data_->alignment = alignment;
    post_recreate_handle();
  }
  return *this;
}

const forms::image_list& tab_control::image_list() const noexcept {
  return data_->image_list;
}

tab_control& tab_control::image_list(const forms::image_list& value) {
  if (data_->image_list != value) {
    data_->image_list = value;
    post_recreate_handle();
  }
  return *this;
}

size_t tab_control::selected_index() const noexcept {
  return data_->selected_index;
}

tab_control& tab_control::selected_index(size_t selected_index) {
  if (data_->selected_index != selected_index) {
    data_->selected_index = selected_index;
    if (is_handle_created()) native::tab_control::selected_index(handle(), data_->selected_index);
    on_selected_index_changed(event_args::empty);
  }
  return *this;
}

tab_control::control_collection& tab_control::tab_pages() noexcept {
  return controls();
}

const tab_control::control_collection& tab_control::tab_pages() const noexcept {
  return controls();
}

forms::create_params tab_control::create_params() const noexcept {
  forms::create_params create_params = control::create_params();
  
  create_params.class_name("tabcontrol");
  create_params.style(create_params.style() | WS_CLIPSIBLINGS);
  
  switch (data_->alignment) {
    case tab_alignment::bottom: create_params.style(create_params.style() | TCS_BOTTOM); break;
    case tab_alignment::left: create_params.style(create_params.style() | TCS_VERTICAL); break;
    case tab_alignment::right: create_params.style(create_params.style() | TCS_VERTICAL | TCS_RIGHT); break;
    default: break;
  }
  
  return create_params;
}

drawing::size tab_control::measure_control() const noexcept {
  drawing::rectangle bounds;
  for (auto item : controls())
    if (item.get().visible()) bounds = drawing::rectangle::make_union(bounds, item.get().bounds());
  return drawing::size(bounds.location() + bounds.size());
}

void tab_control::on_control_added(const control_event_args& e) {
  control::on_control_added(e);
  if (data_->selected_index == npos) data_->selected_index = 0;
}

void tab_control::on_control_removed(const control_event_args& e) {
  control::on_control_removed(e);
  if (controls().size() == 0) data_->selected_index = npos;
}

void tab_control::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  native::tab_control::image_list(handle(), data_->image_list.handle());
  
  for (auto& control : controls())
    native::tab_page::image_index(as<tab_page>(control.get()).handle(), as<tab_page>(control.get()).image_index());
}

void tab_control::on_selected_index_changed(const event_args& e) {
  selected_index_changed(*this, e);
}

void tab_control::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_REFLECT + WM_COMMAND: wm_command_control(message); break;
    default: control::wnd_proc(message);
  }
}

size_t tab_control::get_child_index(intptr_t page) {
  for (size_t index = 0; index < controls().size(); ++index)
    if (controls()[index].get().handle() == page) return index;
  return npos;
}

void tab_control::wm_command_control(message& message) {
  def_wnd_proc(message);
  selected_index(native::tab_control::selected_index(handle()));
}
