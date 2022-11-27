#include <xtd/argument_out_of_range_exception.h>
#include <xtd/literals.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/domain_up_down.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/up_down_styles.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/domain_up_down.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

domain_up_down::item::item(const xtd::ustring& value) : value_(value) {
}

domain_up_down::item::item(const xtd::ustring& value, const std::any& tag) : value_(value), tag_(tag) {
}

domain_up_down::item::item(const char* value) : value_(value) {
}

bool domain_up_down::item::operator ==(const item& value) const noexcept {
  return value_ == value.value_;
}

bool domain_up_down::item::operator !=(const item& value) const noexcept {
  return !operator ==(value);
}

bool domain_up_down::item::operator <(const item& value) const noexcept {
  return value_ < value.value_;
}

bool domain_up_down::item::operator <=(const item& value) const noexcept {
  return value_ <= value.value_;
}

bool domain_up_down::item::operator >(const item& value) const noexcept {
  return value_ > value.value_;
}

bool domain_up_down::item::operator >=(const item& value) const noexcept {
  return value_ >= value.value_;
}

const xtd::ustring& domain_up_down::item::value() const noexcept {
  return value_;
}

std::any domain_up_down::item::tag() const noexcept {
  return tag_;
}

xtd::ustring domain_up_down::item::to_string() const noexcept {
  return value_;
}

domain_up_down::domain_up_down() {
  control_appearance(forms::control_appearance::system);
  
  data_->items.item_added += {*this, &domain_up_down::on_items_item_added};
  data_->items.item_removed += {*this, &domain_up_down::on_items_item_removed};
  data_->items.item_updated += {*this, &domain_up_down::on_items_item_updated};
}

domain_up_down::object_collection& domain_up_down::items() noexcept {
  return data_->items;
}

const domain_up_down::object_collection& domain_up_down::items() const noexcept {
  return data_->items;
}

const domain_up_down& domain_up_down::items(const object_collection& items) {
  data_->items = items;
  return *this;
}

size_t domain_up_down::selected_index() const noexcept {
  return data_->selected_index;
}

domain_up_down& domain_up_down::selected_index(size_t selected_index) {
  if (selected_index != npos && selected_index >= data_->items.size()) argument_out_of_range_exception("Selected index greater than items size");
  if (data_->selected_index != selected_index) {
    data_->selected_index = selected_index;
    if (is_handle_created()) native::domain_up_down::selected_index(handle(), data_->selected_index);
    
    item selected_item;
    if (data_->selected_index != npos) selected_item = data_->items[data_->selected_index];
    //this->selected_item(selected_item);
    data_->selected_item = selected_item;
    
    on_text_changed(event_args::empty);
  }
  return *this;
}

const domain_up_down::item& domain_up_down::selected_item() const noexcept {
  return data_->selected_item;
}

domain_up_down& domain_up_down::selected_item(const item& selected_item) {
  if (data_->selected_item != selected_item) {
    auto it = std::find(data_->items.begin(), data_->items.end(), selected_item);
    if (it == data_->items.end())
      data_->selected_item = selected_index() != npos ? items()[selected_index()] : "";
    else {
      size_t index = it - data_->items.begin();
      selected_index(index);
      data_->selected_item = *it;
      
    }
  }
  return *this;
}

bool domain_up_down::wrap() const noexcept {
  return data_->wrap;
}

domain_up_down& domain_up_down::wrap(bool value) {
  if (data_->wrap != value) {
    data_->wrap = value;
    post_recreate_handle();
  }
  return *this;
}

forms::create_params domain_up_down::create_params() const noexcept {
  forms::create_params create_params = up_down_base::create_params();
  
  create_params.class_name("domainupdown");
  
  if (data_->wrap) create_params.style(create_params.style() | UDS_WRAP);
  create_params.size(native::control::default_size(create_params.class_name()));
  
  return create_params;
}

drawing::color domain_up_down::default_back_color() const noexcept {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().window();
}

drawing::color domain_up_down::default_fore_color() const noexcept {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().window_text();
}

void domain_up_down::on_handle_created(const event_args& e) {
  scrollable_control::on_handle_created(e);
  for (size_t index = 0; index < data_->items.size(); ++index)
    native::domain_up_down::insert_item(handle(), index, data_->items[index].value());
  native::domain_up_down::selected_index(handle(), data_->selected_index);
  if (data_->selected_index != npos) data_->selected_item = data_->items[data_->selected_index];
  else native::control::text(handle(), text());
}

void domain_up_down::on_text_changed(const event_args& e) {
  if (is_handle_created()) {
    set_text(native::control::text(handle()));
    if (data_->selected_index != native::domain_up_down::selected_index(handle())) {
      data_->selected_index = native::domain_up_down::selected_index(handle());
      if (data_->selected_index == npos)
        data_->selected_item = "";
      else
        data_->selected_item = data_->items[data_->selected_index];
      on_selected_item_changed(event_args::empty);
    }
  }
  up_down_base::on_text_changed(e);
}

void domain_up_down::on_selected_item_changed(const event_args& e) {
  if (can_raise_events()) selected_item_changed(*this, e);
}

void domain_up_down::on_items_item_added(size_t pos, const item & item) {
  if (is_handle_created()) native::domain_up_down::insert_item(handle(), pos, item.value());
  domain_up_down::item selected_item;
  if (data_->selected_index != npos && data_->selected_index < data_->items.size()) selected_item = data_->items[data_->selected_index];
  this->selected_item(selected_item);
}

void domain_up_down::on_items_item_removed(size_t pos, const item & item) {
  if (is_handle_created()) native::domain_up_down::delete_item(handle(), pos);
  
  domain_up_down::item selected_item;
  if (data_->selected_index != npos && data_->selected_index < data_->items.size()) selected_item = data_->items[data_->selected_index];
  this->selected_item(selected_item);
}

void domain_up_down::on_items_item_updated(size_t pos, const item & item) {
  static bool update_disabled = false;
  if (update_disabled) return;
  if (is_handle_created()) native::domain_up_down::update_item(handle(), pos, item.value());
  domain_up_down::item selected_item;
  if (data_->selected_index != npos && data_->selected_index < data_->items.size()) selected_item = data_->items[data_->selected_index];
  this->selected_item(selected_item);
}
