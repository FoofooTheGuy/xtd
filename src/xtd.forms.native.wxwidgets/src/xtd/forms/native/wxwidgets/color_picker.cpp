#include <xtd/argument_exception.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/color_picker.h>
#include <xtd/forms/native/content_alignment.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_color_picker.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

color color_picker::color(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (reinterpret_cast<control_handler*>(control)->control() == 0) return {};
  wxColour colour = static_cast<wxColourPickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetColour();
  return color::from_argb(colour.Alpha(), colour.Red(), colour.Green(), colour.Blue());
}

void color_picker::color(intptr_t control, const drawing::color& color) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (reinterpret_cast<control_handler*>(control)->control() == 0) return;
  static_cast<wxColourPickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetColour(wxColour(color.r(), color.g(), color.b(), color.a()));
}
