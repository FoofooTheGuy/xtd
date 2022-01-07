#include <xtd/drawing/pens.h>
#include <xtd/drawing/solid_brush.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/drawing/string_format.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/label.h>
#include <xtd/forms/native/static_styles.h>
#include <xtd/forms/native/toolkit.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/control_paint.h"
#include "../../../include/xtd/forms/label.h"
#include "../../../include/xtd/forms/screen.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

label::label() {
  set_can_focus(false);
}

label& label::border_sides(forms::border_sides border_sides) {
  if (border_sides_ != border_sides) {
    border_sides_ = border_sides;
    if (control_appearance() == forms::control_appearance::standard) invalidate();
  }
  return *this;
}

label& label::border_style(xtd::forms::border_style border_style) {
  if (border_style_ != border_style) {
    border_style_ = border_style;
    recreate_handle();
  }
  return *this;
}

label& label::flat_style(xtd::forms::flat_style flat_style) {
  if (flat_style_ != flat_style) {
    flat_style_ = flat_style;
    recreate_handle();
  }
  return *this;
}

label& label::shadow(bool value) {
  if (shadow_ != value) {
    shadow_ = value;
    if (control_appearance() == forms::control_appearance::standard) invalidate();
  }
  return *this;
}

label& label::text_align(content_alignment text_align) {
  if (text_align_ != text_align) {
    text_align_ = text_align;
    recreate_handle();
    on_text_align_changed(event_args::empty);
  }
  return *this;
}

forms::create_params label::create_params() const {
  forms::create_params create_params = control::create_params();
  
  create_params.class_name("label");
  create_params.style(create_params.style() | SS_LEFT);
  
  if (flat_style_ == xtd::forms::flat_style::system) {
    if (border_style_ == xtd::forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
    else if (border_style_ != xtd::forms::border_style::none) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
  } else create_params.style(create_params.style() | SS_OWNERDRAW);
  
  switch (text_align_) {
    case content_alignment::top_left: create_params.style(create_params.style() | SS_TOP | SS_LEFT); break;
    case content_alignment::top_center: create_params.style(create_params.style() | SS_TOP  | SS_CENTER); break;
    case content_alignment::top_right: create_params.style(create_params.style() | SS_TOP  | SS_RIGHT); break;
    case content_alignment::middle_left: create_params.style(create_params.style() | SS_VCENTER  | SS_LEFT); break;
    case content_alignment::middle_center: create_params.style(create_params.style() | SS_VCENTER | SS_CENTER); break;
    case content_alignment::middle_right: create_params.style(create_params.style() | SS_VCENTER | SS_RIGHT); break;
    case content_alignment::bottom_left: create_params.style(create_params.style() | SS_BOTTOM | SS_LEFT); break;
    case content_alignment::bottom_center: create_params.style(create_params.style() | SS_BOTTOM | SS_CENTER); break;
    case content_alignment::bottom_right: create_params.style(create_params.style() | SS_BOTTOM | SS_RIGHT); break;
    default: break;
  }
  
  return create_params;
}

drawing::size label::measure_control() const {
  return control::measure_text() + drawing::size(border_style_ == border_style::none ? 0 : 4, border_style_ == border_style::none ? 0 : 4);
}

void label::on_font_changed(const xtd::event_args& e) {
  control::on_font_changed(e);
  if (flat_style_ != xtd::forms::flat_style::system) invalidate();
}

void label::on_paint(paint_event_args& e) {
  control::on_paint(e);
  if (flat_style_ != xtd::forms::flat_style::system) {
    control_paint::draw_border_from_back_color(*this, e.graphics(), border_style(), border_sides(), back_color(), e.clip_rectangle());
    xtd::drawing::string_format string_format;
    switch (text_align_) {
      case content_alignment::top_left: string_format.line_alignment(xtd::drawing::string_alignment::near); string_format.alignment(xtd::drawing::string_alignment::near); break;
      case content_alignment::top_center: string_format.line_alignment(xtd::drawing::string_alignment::near); string_format.alignment(xtd::drawing::string_alignment::center); break;
      case content_alignment::top_right: string_format.line_alignment(xtd::drawing::string_alignment::near); string_format.alignment(xtd::drawing::string_alignment::far); break;
      case content_alignment::middle_left: string_format.line_alignment(xtd::drawing::string_alignment::center); string_format.alignment(xtd::drawing::string_alignment::near); break;
      case content_alignment::middle_center: string_format.line_alignment(xtd::drawing::string_alignment::center); string_format.alignment(xtd::drawing::string_alignment::center); break;
      case content_alignment::middle_right: string_format.line_alignment(xtd::drawing::string_alignment::center); string_format.alignment(xtd::drawing::string_alignment::far); break;
      case content_alignment::bottom_left: string_format.line_alignment(xtd::drawing::string_alignment::far); string_format.alignment(xtd::drawing::string_alignment::near); break;
      case content_alignment::bottom_center: string_format.line_alignment(xtd::drawing::string_alignment::far); string_format.alignment(xtd::drawing::string_alignment::center); break;
      case content_alignment::bottom_right: string_format.line_alignment(xtd::drawing::string_alignment::far); string_format.alignment(xtd::drawing::string_alignment::far); break;
      default: break;
    }
    auto rect = xtd::drawing::rectangle(0, 0, client_size().width(), client_size().height());
    if (shadow()) {
      e.graphics().draw_string(text(), font(), xtd::drawing::solid_brush(enabled() ? control_paint::dark(back_color()) : control_paint::dark(application::theme().theme_colors().gray_text())), rectangle::offset(rect, {1, 1}), string_format);
      e.graphics().draw_string(text(), font(), xtd::drawing::solid_brush(enabled() ? fore_color() : application::theme().theme_colors().gray_text()), rectangle::offset(rect, {-1, -1}), string_format);
    } else
      e.graphics().draw_string(text(), font(), xtd::drawing::solid_brush(enabled() ? fore_color() : application::theme().theme_colors().gray_text()), rect, string_format);
  }
}

void label::on_text_align_changed(const xtd::event_args& e) {
  text_align_changed(*this, e);
}

void label::on_text_changed(const xtd::event_args& e) {
  control::on_text_changed(e);
  if (flat_style_ != xtd::forms::flat_style::system) invalidate();
}

void label::on_resize(const xtd::event_args& e) {
  control::on_resize(e);
  if (flat_style_ != xtd::forms::flat_style::system) invalidate();
}
