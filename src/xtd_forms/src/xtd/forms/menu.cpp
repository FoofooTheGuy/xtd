#include <xtd/strings.hpp>
#include "../../../include/xtd/forms/menu.hpp"
#include "../../../include/xtd/forms/context_menu.hpp"
#include "../../../include/xtd/forms/main_menu.hpp"
#include "../../../include/xtd/forms/menu_item.hpp"

using namespace xtd;
using namespace xtd::forms;

menu::menu() {
  data_ = std::make_shared<data>();
  data_->mdi_list_item_ = std::make_unique<menu_item>();
}

menu::menu(const menu_item_collection& items) {
  data_ = std::make_shared<data>();
  //data_->mdi_list_item_ = std::make_unique<menu_item>();
  menu_items(items);
}

menu::~menu() {
}

bool menu::is_parent() const {
  return data_->menu_items_.size() != 0;
}

const menu_item& menu::mdi_list_item() const {
  return *data_->mdi_list_item_;
}

menu& menu::menu_items(const menu_item_collection& value) {
  if (&data_->menu_items_ != &value) {
    data_->menu_items_.clear();
    data_->menu_items_ = value;
  }
  return *this;
}

std::optional<context_menu> menu::get_context_menu() const {
  const menu* item = this;
  while (item)
    if (dynamic_cast<const context_menu*>(item)) return static_cast<const context_menu&>(*item);
  return {};
}

std::optional<main_menu> menu::get_main_menu() const {
  const menu* item = this;
  while (item)
    if (dynamic_cast<const main_menu*>(item)) return static_cast<const main_menu&>(*item);
  return {};
}

std::string menu::to_string() const {
  return strings::format("{}, items.size(): {}", strings::full_class_name(*this), data_->menu_items_.size());
}

void menu::clone_menu(const menu& menu_src) {
  *data_->mdi_list_item_ = *menu_src.data_->mdi_list_item_;
  data_->menu_items_ = menu_src.data_->menu_items_;
  data_->name_ = menu_src.data_->name_;
  data_->tag_ = menu_src.data_->tag_;
}

void menu::merge_menu(const menu& menu_src) {
  if (data_.get() == menu_src.data_.get()) throw std::invalid_argument("It was attempted to merge the menu with itself");
  data_->menu_items_.push_back_range(menu_src.data_->menu_items_);
}
