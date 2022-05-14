#include "../../../include/xtd/drawing/system_fonts.h"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/system_fonts.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;

font system_fonts::caption_font() {
  return font(native::system_fonts::caption_font());
}

font system_fonts::default_font() {
  return font(native::system_fonts::default_font());
}

font system_fonts::dialog_font() {
  return font(native::system_fonts::dialog_font());
}

font system_fonts::icon_title_font() {
  return font(native::system_fonts::icon_title_font());
}

font system_fonts::menu_font() {
  return font(native::system_fonts::menu_font());
}

font system_fonts::message_box_font() {
  return font(native::system_fonts::message_box_font());
}

font system_fonts::small_caption_font() {
  return font(native::system_fonts::small_caption_font());
}

font system_fonts::status_font() {
  return font(native::system_fonts::status_font());
}

font system_fonts::toolbar_font() {
  return font(native::system_fonts::toolbar_font());
}
