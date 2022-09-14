#include <xtd/argument_out_of_range_exception.h>
#include <xtd/literals.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/choice.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/choice.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

choice::choice() {
  control_appearance(forms::control_appearance::system);
  set_style(control_styles::user_paint | control_styles::use_text_for_accessibility | control_styles::standard_click, false);
  items_.item_added += [&](size_t pos, const item & item) {
    if (is_handle_created()) native::choice::insert_item(handle(), pos, item.value());
    size_t selected_index = npos;
    if (this->selected_index() != npos && this->selected_index() < items_.size()) selected_index = this->selected_index();
    this->selected_index(selected_index);
  };
  
  items_.item_removed += [&](size_t pos, const item & item) {
    if (is_handle_created()) native::choice::delete_item(handle(), pos);
    
    size_t selected_index = npos;
    if (this->selected_index() != npos && this->selected_index() < items_.size()) selected_index = this->selected_index();
    this->selected_index(selected_index);
  };
  
  items_.item_updated += [&](size_t pos, const item & item) {
    if (is_handle_created()) native::choice::update_item(handle(), pos, item.value());
    size_t selected_index = npos;
    if (this->selected_index() != npos && this->selected_index() < items_.size()) selected_index = this->selected_index();
    this->selected_index(selected_index);
  };
}

list_control& choice::selected_index(size_t selected_index) {
  if (this->selected_index() != selected_index) {
    if (selected_index != npos && selected_index >= items_.size()) throw argument_out_of_range_exception("Selected index greater than items size"_t, current_stack_frame_);
    set_selected_index(selected_index);
    if (is_handle_created()) native::choice::selected_index(handle(), this->selected_index());
    
    item selected_item;
    if (this->selected_index() != npos) selected_item = items_[this->selected_index()];
    //this->selected_item(selected_item);
    selected_item_ = selected_item;
    on_selected_value_changed(event_args::empty);
    
    on_selected_index_changed(event_args::empty);
  }
  return *this;
}

choice& choice::selected_item(const item& selected_item) {
  if (selected_item_ != selected_item) {
    auto it = std::find(items_.begin(), items_.end(), selected_item);
    if (it == items_.end())
      selected_item_ = selected_index() != npos ? items()[selected_index()] : item {""};
    else {
      size_t index = it - items_.begin();
      selected_index(index);
      selected_item_ = *it;
      on_selected_value_changed(event_args::empty);
    }
  }
  return *this;
}

choice& choice::sorted(bool sorted) {
  if (sorted_ != sorted) {
    sorted_ = sorted;
    items_.sorted(sorted_);
  }
  return *this;
}

void choice::begin_update() {
  if (is_handle_created()) native::choice::begin_update(handle());
}

void choice::end_update() {
  if (is_handle_created()) native::choice::end_update(handle());
}

forms::create_params choice::create_params() const {
  forms::create_params create_params = list_control::create_params();
  
  create_params.class_name("choice");
  
  // Do not use native control sort
  //if (sorted_) create_params.style(create_params.style() | CBS_SORT);
  
  return create_params;
}

void choice::on_handle_created(const event_args& e) {
  list_control::on_handle_created(e);
  items_.sorted(sorted_);
  for (size_t index = 0; index < items_.size(); ++index)
    native::choice::insert_item(handle(), index, items_[index].value());
  native::choice::selected_index(handle(), selected_index());
  if (selected_index() != npos) selected_item_ = items_[selected_index()];
}

void choice::on_selected_value_changed(const event_args& e) {
  list_control::text(selected_item_.value());
  list_control::on_selected_value_changed(e);
}

void choice::set_bounds_core(int32_t x, int32_t y, int32_t width, int32_t height, bounds_specified specified) {
  drawing::size current_size = size();
  list_control::set_bounds_core(x, y, width, height, specified);
  if (size() != current_size)
    post_recreate_handle();
}

void choice::set_client_size_core(int32_t width, int32_t height) {
  drawing::size current_size = size();
  list_control::set_client_size_core(width, height);
  if (size() != current_size)
    post_recreate_handle();
}

void choice::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_LBUTTONDOWN: wm_mouse_down(message); break;
    case WM_LBUTTONUP: wm_mouse_up(message); break;
    case WM_LBUTTONDBLCLK: wm_mouse_double_click(message); break;
    case WM_REFLECT + WM_COMMAND: wm_command_control(message); break;
    default: list_control::wnd_proc(message);
  }
}

void choice::wm_command_control(message& message) {
  def_wnd_proc(message);
  if (HIWORD(message.wparam()) == LBN_SELCHANGE) {
    selected_index(native::choice::selected_index(handle()));
    if (selected_index() != npos) selected_item(items_[selected_index()]);
    on_click(event_args::empty);
  }
}

void choice::wm_mouse_double_click(message& message) {
  selected_index(native::choice::selected_index(handle()));
  if (selected_index() != npos) selected_item(items_[selected_index()]);
  if (allow_selection())
    list_control::wnd_proc(message);
}

void choice::wm_mouse_down(message& message) {
  if (allow_selection())
    list_control::wnd_proc(message);
}

void choice::wm_mouse_up(message& message) {
  selected_index(native::choice::selected_index(handle()));
  if (selected_index() != npos) selected_item(items_[selected_index()]);
  if (allow_selection())
    list_control::wnd_proc(message);
}
