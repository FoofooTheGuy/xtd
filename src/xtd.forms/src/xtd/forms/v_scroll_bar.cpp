#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/scroll_bar.h>
#include <xtd/forms/native/scroll_bar_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/v_scroll_bar.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

v_scroll_bar::v_scroll_bar() {
  set_can_focus(false);
  size(default_size());
}

forms::create_params v_scroll_bar::create_params() const {
  forms::create_params create_params = scroll_bar::create_params();

  create_params.style(create_params.style() | SBS_VERT);

  return create_params;
}
