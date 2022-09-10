#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/scroll_bar.h>
#include <xtd/forms/window_messages.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/scroll_bar.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

int32_t scroll_bar::large_change() const {
  return large_change_;
}

scroll_bar& scroll_bar::large_change(int32_t large_change) {
  if (large_change < 0) throw argument_out_of_range_exception(csf_);
  large_change_ = large_change;
  return *this;
}

int32_t scroll_bar::maximum() const {
  return maximum_;
}

scroll_bar& scroll_bar::maximum(int32_t maximum) {
  maximum_ = maximum;
  return *this;
}

int32_t scroll_bar::minimum() const {
  return minimum_;
}

scroll_bar& scroll_bar::minimum(int32_t minimum) {
  minimum_ = minimum;
  return *this;
}

int32_t scroll_bar::small_change() const {
  return small_change_;
}

scroll_bar& scroll_bar::small_change(int32_t small_change) {
  if (small_change < 0) throw argument_out_of_range_exception(csf_);
  small_change_ = small_change;
  return *this;
}

int32_t scroll_bar::value() const {
  return value_;
}

scroll_bar& scroll_bar::value(int32_t value) {
  if (value < minimum_ || value > maximum_) throw argument_out_of_range_exception(csf_);
  if (value_ != value) {
    value_ = value;
    if (is_handle_created()) native::scroll_bar::value(handle(), value);
    on_value_changed(event_args::empty);
  }
  return *this;
}

scroll_bar::scroll_bar() {
  set_style(control_styles::user_paint, false);
  set_style(control_styles::standard_click, false);
  set_style(control_styles::use_text_for_accessibility, false);
}

forms::create_params scroll_bar::create_params() const {
  forms::create_params create_params = control::create_params();
  
  create_params.class_name("scrollbar");
  
  return create_params;
}

void scroll_bar::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  native::scroll_bar::large_change(handle(), large_change_);
  native::scroll_bar::maximum(handle(), maximum_);
  native::scroll_bar::minimum(handle(), minimum_);
  native::scroll_bar::small_change(handle(), small_change_);
  native::scroll_bar::value(handle(), value_);
}

void scroll_bar::on_scroll(const event_args& e) {
  if (is_handle_created()) value_ = native::scroll_bar::value(handle());
  scroll(*this, e);
}

void scroll_bar::on_value_changed(const event_args& e) {
  value_changed(*this, e);
}

void scroll_bar::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_REFLECT + WM_HSCROLL:
    case WM_REFLECT + WM_VSCROLL: wm_scroll_control(message); break;
    default: control::wnd_proc(message);
  }
}

void scroll_bar::wm_scroll_control(message& message) {
  on_scroll(event_args::empty);
  on_value_changed(event_args::empty);
}
