#include <memory>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/busy_dialog.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/drawing/system_icons.h>
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/busy_box.h"
#include "../../../include/xtd/forms/busy_dialog.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

namespace {
}

busy_dialog* busy_box::dialog_ = nullptr;

busy_dialog::~busy_dialog() {hide();}

xtd::drawing::color busy_dialog::back_color() const noexcept {
  return data_->back_color;
}

busy_dialog& busy_dialog::back_color(const xtd::drawing::color& color) {
  data_->back_color = color;
  return *this;
}

xtd::forms::dialog_style busy_dialog::dialog_style() const noexcept {
  return data_->dialog_style;
}

busy_dialog& busy_dialog::dialog_style(xtd::forms::dialog_style dialog_style) {
  data_->dialog_style = dialog_style;
  return *this;
}

const xtd::ustring& busy_dialog::description() const noexcept {
  return data_->description;
}

busy_dialog& busy_dialog::description(const xtd::ustring& description) {
  data_->description = description;
  return *this;
}

/// @brief Gets the foreground color for the dialog.
/// @return A xtd::drawing::color that represents the foreground color of the dialog.
xtd::drawing::color busy_dialog::fore_color() const noexcept {
  return data_->fore_color;
}

busy_dialog& busy_dialog::fore_color(const xtd::drawing::color& color) {
  data_->fore_color = color;
  return *this;
}

xtd::drawing::icon busy_dialog::icon() const noexcept {
  return xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(data_->icon));
}

busy_dialog& busy_dialog::icon(const xtd::drawing::icon& icon) {
  data_->icon = icon.to_bitmap();
  return *this;
}

busy_dialog& busy_dialog::icon(const xtd::drawing::image& image) {
  data_->icon = image;
  return *this;
}

busy_dialog& busy_dialog::icon(const xtd::drawing::bitmap& bitmap) {
  data_->icon = bitmap;
  return *this;
}

double busy_dialog::opacity() const noexcept {
  return data_->opacity;
}

busy_dialog& busy_dialog::opacity(double opacity) {
  data_->opacity = opacity;
  return *this;
}

/// @brief Gets the dialog title.
/// @return The dialog title.
const xtd::ustring& busy_dialog::text() const noexcept {
  return data_->text;
}

busy_dialog& busy_dialog::text(const xtd::ustring& text) {
  data_->text = text;
  return *this;
}

void busy_dialog::reset() {
  data_->dialog_style = xtd::forms::dialog_style::standard;
  data_->icon = xtd::drawing::image::empty;
  data_->text = "";
  data_->description = "";
}

void busy_dialog::show() {
  data_->native = data_->dialog_style == xtd::forms::dialog_style::system;
  if (data_->native)
    data_->handle = native::busy_dialog::create(0, xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(data_->icon)), data_->text, data_->description, data_->back_color, data_->fore_color, data_->opacity);
  application::do_events();
}

void busy_dialog::show(const iwin32_window& owner) {
  data_->native = data_->dialog_style == xtd::forms::dialog_style::system;
  if (data_->native)
    data_->handle = native::busy_dialog::create(owner.handle(), xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(data_->icon)), data_->text, data_->description, data_->back_color, data_->fore_color, data_->opacity);
  application::do_events();
}

void busy_dialog::hide() {
  if (!data_->handle) return;
  if (data_->native) native::busy_dialog::destroy(data_->handle);
  data_->native = false;
  data_->handle = 0;
}
