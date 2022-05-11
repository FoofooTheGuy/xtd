#include <chrono>
#include <thread>
#include <xtd/argument_exception.h>
#include <xtd/not_implemented_exception.h>
#ifdef WIN32
#include <winsock2.h>
#include <Windows.h>
#include <Commctrl.h>
#undef max
#undef min
#endif
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/form.h>
#include <xtd/forms/native/screen.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_form.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <wx/apptrait.h>

using namespace std::literals;
using namespace std::this_thread;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void __toggle_full_screen_frame__(wxTopLevelWindow* control, bool full_screen);

static void __on_command_menu__(wxCommandEvent& event) {
  if (event.GetId() == wxID_EXIT) {
    for (auto window : wxTopLevelWindows)
      if (!window->Close())
        return;
    wxTheApp->ExitMainLoop();
  } else event.Skip();
}

wxMenuBar* __create_default_menu_bar__() {
  wxMenuBar* default_menu_bar = new wxMenuBar;
  default_menu_bar->Bind(wxEVT_MENU, &__on_command_menu__);
  return default_menu_bar;
}

void form::activate(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->Raise();
}

void form::close(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->Close();
}

bool form::full_screen(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return false;
  }
  #if defined(__APPLE__)
  return __toggle_full_screen_frame__(static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control()));
  #else
  return static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control())->IsFullScreen();
  #endif
}

void form::full_screen(intptr_t control, bool full_screen) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  #if defined(__APPLE__)
  __toggle_full_screen_frame__(static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control()), full_screen);
  #else
  static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control())->ShowFullScreen(full_screen, wxFULLSCREEN_NOMENUBAR | wxFULLSCREEN_NOBORDER | wxFULLSCREEN_NOCAPTION);
  #endif
}

void form::icon(intptr_t control, const xtd::drawing::icon& icon) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  if (icon == drawing::icon::empty) static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control())->SetIcon(wxIcon());
  else static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control())->SetIcon(reinterpret_cast<wxIconBundle*>(icon.handle())->GetIcon());
}

bool form::maximize(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return false;
  }
  #if defined(__WXGTK__)
  xtd::drawing::size form_size = control::size(control);
  xtd::drawing::size screen_size = screen::working_area(screen::from_handle(control)).size();
  return form_size.width() == screen_size.width() && form_size.height() == screen_size.height();
  #else
  return static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control())->IsMaximized();
  #endif
}

void form::maximize(intptr_t control, bool maximize) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control())->Maximize(maximize);
}

void form::menu(intptr_t control, intptr_t menu) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (menu != 0 && !dynamic_cast<wxFrame*>(reinterpret_cast<control_handler*>(control)->control())) throw argument_exception("dialog can't have menu"_t, current_stack_frame_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  
  static_cast<wxFrame*>(reinterpret_cast<control_handler*>(control)->control())->SetMenuBar(menu != 0 ? reinterpret_cast<wxMenuBar*>(menu) : __create_default_menu_bar__());
}

bool form::minimize(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return false;
  }
  return static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control())->IsIconized();
}

void form::minimize(intptr_t control, bool minimize) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control())->Iconize(minimize);
}

void form::restore(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  full_screen(control, false);
  static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control())->Restore();
  #if defined(__WXGTK__)
  maximize(control, false);
  minimize(control, false);
  #endif
}

void form::set_region(intptr_t control, intptr_t region) {
  if (!control || !region || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxNonOwnedWindow*>(reinterpret_cast<control_handler*>(control)->control())->SetShape(*reinterpret_cast<wxRegion*>(region));
}

int32_t form::show_dialog(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  if (!dynamic_cast<wxDialog*>(reinterpret_cast<control_handler*>(control)->control())) throw argument_exception("show_dialog work only with dialog"_t, current_stack_frame_);
  auto dialog = static_cast<wxDialog*>(reinterpret_cast<control_handler*>(control)->control());
  return dialog->ShowModal();
}

void form::show_sheet(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  if (!dynamic_cast<wxDialog*>(reinterpret_cast<control_handler*>(control)->control())) throw argument_exception("show_sheet work only with dialog"_t, current_stack_frame_);
  #if defined(__APPLE__)
  static_cast<wxDialog*>(reinterpret_cast<control_handler*>(control)->control())->ShowWindowModal();
  #else
  static_cast<wxDialog*>(reinterpret_cast<control_handler*>(control)->control())->ShowModal();
  #endif
}

int32_t form::show_sheet_dialog(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  if (!dynamic_cast<wxDialog*>(reinterpret_cast<control_handler*>(control)->control())) throw argument_exception("show_sheet_dialog work only with dialog"_t, current_stack_frame_);
  auto dialog = static_cast<wxDialog*>(reinterpret_cast<control_handler*>(control)->control());
  #if defined(__APPLE__)
  if (!dialog->GetParent()) return dialog->ShowModal();
  int32_t result = wxID_ANY;
  dialog->ShowWindowModal();
  dialog->Bind(wxEVT_WINDOW_MODAL_DIALOG_CLOSED, [&](wxWindowModalDialogEvent & event) {
    result = event.GetReturnCode();
  });
  while (result == wxID_ANY) {
    wxYield();
    sleep_for(100ms);
  }
  return result;
  #else
  return dialog->ShowModal();
  #endif
}

void form::end_dialog(intptr_t control, int32_t result) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  if (!dynamic_cast<wxDialog*>(reinterpret_cast<control_handler*>(control)->control())) throw argument_exception("end_dialog work only with dialog"_t, current_stack_frame_);
  static_cast<wxDialog*>(reinterpret_cast<control_handler*>(control)->control())->EndModal(result);
}

void form::opacity(intptr_t control, double opacity) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control())->SetTransparent(static_cast<uint8_t>(255 * (1.0 - opacity)));
}

void form::virtual_size(intptr_t control, const drawing::size& size) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->main_control()->SetVirtualSize(wxSize(size.width(), size.height()));
  if (dynamic_cast<wxMainPanel*>(reinterpret_cast<control_handler*>(control)->main_control())) static_cast<wxMainPanel*>(reinterpret_cast<control_handler*>(control)->main_control())->SetScrollRate(10, 10);
}
