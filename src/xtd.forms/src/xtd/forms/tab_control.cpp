#include <xtd/as.h>
#include <xtd/environment.h>
#include <xtd/is.h>
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
#include "tab_control_data.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

tab_control::tab_page_collection::tab_page_collection(const tab_control::tab_page_collection::allocator_type& allocator) : tab_control::tab_page_collection::base(allocator) {
}

tab_control::tab_page_collection::tab_page_collection(const tab_control::tab_page_collection::base& collection) : tab_control::tab_page_collection::base(collection) {}
tab_control::tab_page_collection::tab_page_collection(const tab_control::tab_page_collection& collection) : tab_control::tab_page_collection::base(collection) {}
tab_control::tab_page_collection& tab_control::tab_page_collection::operator =(const tab_control::tab_page_collection& collection) {
  base::operator =(collection);
  return *this;
}

void tab_control::tab_page_collection::push_back(const xtd::ustring& text) {
  push_back(text, "");
}

void tab_control::tab_page_collection::push_back(const xtd::ustring& text, const ustring& name) {
  text_added(text, name);
}

void tab_control::tab_page_collection::push_back(const char* text) {
  push_back(text, "");
}

void tab_control::tab_page_collection::push_back(const char8* text) {
  push_back(text, "");
}

void tab_control::tab_page_collection::push_back(const char16* text) {
  push_back(text, "");
}

void tab_control::tab_page_collection::push_back(const char32* text) {
  push_back(text, "");
}

void tab_control::tab_page_collection::push_back(const wchar* text) {
  push_back(text, "");
}

optional<tab_control::tab_page_collection::value_type> tab_control::tab_page_collection::operator [](const ustring& name) const {
  for (auto item : *this)
    if (item.get().name() == name) return item;
  return {};
}

optional<tab_control::tab_page_collection::value_type> tab_control::tab_page_collection::operator [](const ustring& name) {
  for (auto item : *this)
    if (item.get().name() == name) return item;
  return {};
}

tab_control::tab_control() : data_(std::make_shared<data>()) {
  control_appearance(forms::control_appearance::system);
  set_style(control_styles::user_paint, false);
  
  data_->tab_pages.item_added += {*this, &tab_control::on_tab_pages_item_added};
  data_->tab_pages.item_removed += {*this, &tab_control::on_tab_pages_item_removed};
  data_->tab_pages.text_added += {*this, &tab_control::on_tab_pages_text_added};
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

tab_control::tab_page_collection& tab_control::tab_pages() noexcept {
  return data_->tab_pages;
}

const tab_control::tab_page_collection& tab_control::tab_pages() const noexcept {
  return data_->tab_pages;
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
  if (!is<xtd::forms::tab_page>(e.control())) throw xtd::argument_exception(ustring::format("Cannot add '{}' to tab_control.  Only tab_pages can be directly added to tab_controls.", ustring::class_name(e.control())));
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

size_t tab_control::get_child_index(intptr page) {
  for (size_t index = 0; index < controls().size(); ++index)
    if (controls()[index].get().handle() == page) return index;
  return npos;
}

void tab_control::on_tab_pages_item_added(size_t index, control_ref item) {
  controls().insert_at(index, item);
}

void tab_control::on_tab_pages_item_removed(size_t index, control_ref item) {
  controls().erase_at(index);
}

void tab_control::on_tab_pages_text_added(const ustring& text, const ustring& name) {
  auto item = std::make_unique<tab_page>();
  item->text(text);
  item->name(name);
  tab_pages().push_back(*item);
  data_->text_tab_pages.push_back(std::move(item));
}

void tab_control::wm_command_control(message& message) {
  def_wnd_proc(message);
  selected_index(native::tab_control::selected_index(handle()));
}
