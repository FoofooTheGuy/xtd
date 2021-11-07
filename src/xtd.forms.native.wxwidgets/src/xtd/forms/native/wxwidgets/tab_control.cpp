#include <limits>
#include <xtd/invalid_operation_exception.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/tab_control.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_tab_control.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void tab_control::delete_page(intptr_t control, intptr_t page) {
  if (control == 0) return;
  auto ctrl = static_cast<wxNotebookBase*>(reinterpret_cast<control_handler*>(control)->control());
  if (ctrl != nullptr) {
    int index = ctrl->FindPage(reinterpret_cast<control_handler*>(page)->control());
    if (index != wxNOT_FOUND)
      static_cast<wxNotebookBase*>(reinterpret_cast<control_handler*>(control)->control())->RemovePage(index);
  }
}

void tab_control::image_list(intptr_t control, intptr_t image_list) {
  if (control == 0) return;
  static_cast<wxNotebookBase*>(reinterpret_cast<control_handler*>(control)->control())->SetImageList(reinterpret_cast<wxImageList*>(image_list));
}

void tab_control::insert_page(intptr_t control, size_t index, intptr_t page) {
  if (control == 0 || page == 0) return;
  static_cast<wxNotebookBase*>(reinterpret_cast<control_handler*>(control)->control())->InsertPage(index, reinterpret_cast<control_handler*>(page)->control(), wxEmptyString);
}

size_t tab_control::selected_index(intptr_t control) {
  if (control == 0) return std::numeric_limits<size_t>::max();
  return static_cast<wxNotebookBase*>(reinterpret_cast<control_handler*>(control)->control())->GetSelection();
}

void tab_control::selected_index(intptr_t control, size_t index) {
  if (control == 0) return;
  if (index != std::numeric_limits<size_t>::max()) static_cast<wxNotebookBase*>(reinterpret_cast<control_handler*>(control)->control())->SetSelection(index);
}
