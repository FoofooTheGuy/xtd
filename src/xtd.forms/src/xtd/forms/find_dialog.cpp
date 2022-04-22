#include <chrono>
#include <memory>
#include <thread>
#include <vector>
#include <xtd/literals.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/find_dialog.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/diagnostics/process.h>
#include <xtd/drawing/system_icons.h>
#include "../../../include/xtd/forms/find_dialog.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

const xtd::ustring& find_dialog::find_string() const {
  return data_->find_string;
}

find_dialog& find_dialog::find_string(const xtd::ustring& value) {
  if (value != data_->find_string) {
    data_->find_string = value;
    recreate_handle();
  }
  return *this;
}

xtd::drawing::point find_dialog::location() const {
  return data_->location.value_or(point(0, 0));
}

find_dialog& find_dialog::location(const xtd::drawing::point& value) {
  if (value != data_->location) {
    data_->location = value;
    recreate_handle();
  }
  return *this;
}

bool find_dialog::match_case() const {
  return data_->match_case;
}

find_dialog& find_dialog::match_case(bool value) {
  if (value != data_->match_case) {
    data_->match_case = value;
    recreate_handle();
  }
  return *this;
}

xtd::forms::search_direction find_dialog::search_direction() const {
  return data_->search_direction;
}

find_dialog& find_dialog::search_direction(xtd::forms::search_direction value) {
  if (value != data_->search_direction) {
    data_->search_direction = value;
    recreate_handle();
  }
  return *this;
}

bool find_dialog::show_match_case() const {
  return data_->show_match_case;
}

find_dialog& find_dialog::show_match_case(bool value) {
  if (value != data_->show_match_case) {
    data_->show_match_case = value;
    recreate_handle();
  }
  return *this;
}

bool find_dialog::show_up_down() const {
  return data_->show_up_down;
}

find_dialog& find_dialog::show_up_down(bool value) {
  if (value != data_->show_up_down) {
    data_->show_up_down = value;
    recreate_handle();
  }
  return *this;
}

bool find_dialog::show_whole_word() const {
  return data_->show_whole_word;
}

find_dialog& find_dialog::show_whole_word(bool value) {
  if (value != data_->show_whole_word) {
    data_->show_whole_word = value;
    recreate_handle();
  }
  return *this;
}

const xtd::ustring& find_dialog::title() const {
  return data_->title;
}

find_dialog& find_dialog::title(const xtd::ustring& value) {
  if (value != data_->title) {
    data_->title = value;
    recreate_handle();
  }
  return *this;
}

bool find_dialog::whole_word() const {
  return data_->whole_word;
}

find_dialog& find_dialog::whole_word(bool value) {
  if (value != data_->whole_word) {
    data_->whole_word = value;
    recreate_handle();
  }
  return *this;
}

void find_dialog::close() {
  if (data_->handle)
    native::find_dialog::close(data_->handle);
  data_->handle = 0;
}

void find_dialog::reset() {
  auto reopen = false;
  if ((reopen = data_->handle)) close();
  data_->dialog_style = xtd::forms::dialog_style::standard;
  data_->location.reset();
  data_->title = "";
  data_->find_string = "";
  data_->show_up_down = true;
  data_->show_match_case = true;
  data_->show_whole_word = true;
  data_->search_direction = xtd::forms::search_direction::down;
  data_->match_case = false;
  data_->whole_word = false;
  if (reopen) show(*data_->owner);
}

void find_dialog::show(const iwin32_window& owner) {
  if (data_->handle) return;
  data_->owner = &owner;
  //if (data_->dialog_style == xtd::forms::dialog_style::system)
    data_->handle = native::find_dialog::show(owner.handle(), data_->location, data_->title, data_->find_string, data_->show_up_down, data_->show_whole_word, data_->show_match_case, data_->search_direction == xtd::forms::search_direction::down, data_->whole_word, data_->match_case, {*this, &find_dialog::on_native_dialog_find}, {*this, &find_dialog::on_native_dialog_closed});
}

void find_dialog::on_native_dialog_closed(const xtd::drawing::point& location, const ustring& find_string, bool downwards, bool whole_word, bool match_case) {
  data_->handle = 0;
  data_->location = location;
  data_->find_string = find_string;
  data_->search_direction = downwards ? xtd::forms::search_direction::down : xtd::forms::search_direction::up;
  data_->whole_word = whole_word;
  data_->match_case = match_case;
  dialog_closed(*this, dialog_closed_event_args(forms::dialog_result::cancel));
}

void find_dialog::on_native_dialog_find(const xtd::drawing::point& location, const ustring& find_string, bool downwards, bool whole_word, bool match_case) {
  data_->location = location;
  data_->find_string = find_string;
  data_->search_direction = downwards ? xtd::forms::search_direction::down : xtd::forms::search_direction::up;
  data_->whole_word = whole_word;
  data_->match_case = match_case;
  find_next(*this, find_event_args(data_->find_string, data_->match_case, data_->search_direction, data_->whole_word));
}

void find_dialog::recreate_handle() {
  if (data_->handle) {
    close();
    show(*data_->owner);
  }
}
