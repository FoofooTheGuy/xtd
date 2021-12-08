#include <codecvt>
#include <map>
#include <stdexcept>
#include <xtd/argument_exception.h>
#include <xtd/convert_string.h>
#include <xtd/environment.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/drawing/system_fonts.h>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/hdc_wrapper.h>
#include <xtd/drawing/native/system_colors.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/control.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/dark_mode.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_button.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_check_box.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_choice.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_combo_box.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_command_link_button.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_checked_list_box.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_collapsible_panel.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_color_picker.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_combo_box.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_control.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_date_time_picker.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_domain_up_down.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_font_picker.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_form.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_group_box.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_label.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_light_button.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_list_box.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_loading_indicator.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_numeric_up_down.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_panel.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_picture_box.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_progress_bar.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_radio_button.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_scroll_bar.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_switch_button.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_tab_control.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_tab_page.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_text_box.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_toggle_button.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_track_bar.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_up_down_button.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_user_control.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <wx/dcbuffer.h>
#include <wx/dcmemory.h>
#include <wx/dcclient.h>
#include <wx/dcscreen.h>
#include <wx/font.h>
#include <wx/frame.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

extern std::vector<control_handler*> __control_handler_to_delete_items__;

namespace {
  intptr_t set_control_extra_options(intptr_t control) {
    allow_dark_mode_for_window(reinterpret_cast<intptr_t>(reinterpret_cast<xtd::forms::native::control_handler*>(control)->control()->GetHandle()));
    return control;
  }

  intptr_t set_form_extra_options(intptr_t control) {
    allow_dark_mode_for_window(reinterpret_cast<intptr_t>(reinterpret_cast<xtd::forms::native::control_handler*>(control)->control()->GetHandle()));
    refresh_title_bar_theme_color(reinterpret_cast<intptr_t>(reinterpret_cast<xtd::forms::native::control_handler*>(control)->control()->GetHandle()));
    return control;
  }
}

extern int32_t __mainloop_runnning__;

void control::back_color(intptr_t control, const color& color) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->SetBackgroundColour(wxColour(color.r(), color.g(), color.b(), color.a()));
}

void control::context_menu(intptr_t control, intptr_t context_menu) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->PopupMenu(context_menu ? reinterpret_cast<wxMenu*>(context_menu) : nullptr);
}

intptr_t control::create(const forms::create_params& create_params) {
  application::initialize(); // Must be first
  if (create_params.class_name() == "button") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_button(create_params)));
  if (create_params.class_name() == "checkbox") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_check_box(create_params)));
  if (create_params.class_name() == "checkedlistbox") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_checked_list_box(create_params)));
  if (create_params.class_name() == "choice") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_choice(create_params)));
  if (create_params.class_name() == "collapsiblepanel") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_collapsible_panel(create_params)));
  if (create_params.class_name() == "colorpicker") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_color_picker(create_params)));
  if (create_params.class_name() == "combobox") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_combo_box(create_params)));
  if (create_params.class_name() == "commandlinkbutton") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_command_link_button(create_params)));
  if (create_params.class_name() == "datetimepicker") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_date_time_picker(create_params)));
  if (create_params.class_name() == "domainupdown") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_domain_up_down(create_params)));
  if (create_params.class_name() == "fontpicker") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_font_picker(create_params)));
  if (create_params.class_name() == "form") return set_form_extra_options(reinterpret_cast<intptr_t>(new wx_form(create_params)));
  if (create_params.class_name() == "groupbox") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_group_box(create_params)));
  if (create_params.class_name() == "label") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_label(create_params)));
  if (create_params.class_name() == "lightbutton") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_light_button(create_params)));
  if (create_params.class_name() == "listbox") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_list_box(create_params)));
  if (create_params.class_name() == "loadingindicator") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_loading_indicator(create_params)));
  if (create_params.class_name() == "numericupdown") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_numeric_up_down(create_params)));
  if (create_params.class_name() == "panel") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_panel(create_params)));
  if (create_params.class_name() == "picturebox") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_picture_box(create_params)));
  if (create_params.class_name() == "progressbar") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_progress_bar(create_params)));
  if (create_params.class_name() == "radiobutton") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_radio_button(create_params)));
  if (create_params.class_name() == "scrollbar") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_scroll_bar(create_params)));
  if (create_params.class_name() == "switchbutton") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_switch_button(create_params)));
  if (create_params.class_name() == "tabcontrol") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_tab_control(create_params)));
  if (create_params.class_name() == "tabpage") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_tab_page(create_params)));
  if (create_params.class_name() == "textbox") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_text_box(create_params)));
  if (create_params.class_name() == "togglebutton") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_toggle_button(create_params)));
  if (create_params.class_name() == "trackbar") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_track_bar(create_params)));
  if (create_params.class_name() == "updownbutton") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_up_down_button(create_params)));
  if (create_params.class_name() == "usercontrol") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_user_control(create_params)));
  return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_control(create_params)));
}

intptr_t control::create_paint_graphics(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  xtd::drawing::native::hdc_wrapper* hdc_wrapper = new xtd::drawing::native::hdc_wrapper;
  hdc_wrapper->create<wxPaintDC>(reinterpret_cast<control_handler*>(control)->main_control());
  return reinterpret_cast<intptr_t>(hdc_wrapper);
}

intptr_t control::create_double_buffered_paint_graphics(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  xtd::drawing::native::hdc_wrapper* hdc_wrapper = new xtd::drawing::native::hdc_wrapper;
  //wxColour back_color = reinterpret_cast<control_handler*>(control)->main_control()->GetBackgroundColour();
  reinterpret_cast<control_handler*>(control)->main_control()->SetBackgroundStyle(wxBackgroundStyle::wxBG_STYLE_PAINT);
  //reinterpret_cast<control_handler*>(control)->graphic_control()->SetBackgroundColour(back_color);
  hdc_wrapper->create<wxAutoBufferedPaintDC>(reinterpret_cast<control_handler*>(control)->main_control());
  return reinterpret_cast<intptr_t>(hdc_wrapper);
}

intptr_t control::create_graphics(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  xtd::drawing::native::hdc_wrapper* hdc_wrapper = new xtd::drawing::native::hdc_wrapper;
  hdc_wrapper->create<wxClientDC>(reinterpret_cast<control_handler*>(control)->main_control());
  return reinterpret_cast<intptr_t>(hdc_wrapper);
}

intptr_t control::def_wnd_proc(intptr_t control, intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t presult, intptr_t handle) {
  if (!control || !handle) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return static_cast<intptr_t>(-1);
  }

  return reinterpret_cast<control_handler*>(control)->call_def_wnd_proc(hwnd, msg, wparam, lparam, presult, handle);
}

void control::destroy(intptr_t control) {
  if (!control) throw argument_exception(csf_);
  if (reinterpret_cast<control_handler*>(control)->control() == 0 || !wxTheApp) return;
  reinterpret_cast<control_handler*>(control)->control()->Destroy();
  // Do not delete control_handler here because wxwidgets defers the deletion of wxWindow in the idle event so the deletion of handler_control will also be done in the idle event.
  __control_handler_to_delete_items__.push_back(reinterpret_cast<class control_handler*>(control));
}

drawing::rectangle control::client_rectangle(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return {};
  }
  wxRect rect = reinterpret_cast<control_handler*>(control)->control()->GetClientRect();
  return {{rect.GetX(), rect.GetY()}, client_size(control)};
}

drawing::size control::client_size(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return {};
  }
  wxSize size = reinterpret_cast<control_handler*>(control)->GetClientSize();
  return {size.GetWidth(), size.GetHeight()};
}

void control::client_size(intptr_t control, const drawing::size& size) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->SetClientSize(size.width(), size.height());
}

void control::cursor(intptr_t control, intptr_t cursor) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->SetCursor(cursor ? *reinterpret_cast<wxCursor*>(cursor) : wxNullCursor);
}

bool control::enabled(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return false;
  }
  return reinterpret_cast<control_handler*>(control)->control()->IsEnabled();
}

void control::enabled(intptr_t control, bool enabled) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->Enable(enabled);
}

void control ::focus(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->SetFocus();
}

void control::fore_color(intptr_t control, const color& color) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->SetForegroundColour(wxColour(color.r(), color.g(), color.b(), color.a()));
}

void control::font(intptr_t control, const drawing::font& font) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->SetFont(*reinterpret_cast<wxFont*>(font.handle()));
}

void control::invoke_in_control_thread(intptr_t control, delegate<void(std::vector<std::any>)> invoker, const std::vector<std::any>& args, std::shared_ptr<std::shared_mutex> invoked, std::shared_ptr<bool> completed) {
  if (!control || !wxTheApp || !wxTheApp->IsMainLoopRunning() || !reinterpret_cast<control_handler*>(control)->control()->GetEvtHandlerEnabled()) {
    invoked->unlock();
  } else {
    if (!reinterpret_cast<control_handler*>(control)->control()) {
      wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
      return;
    }
    reinterpret_cast<control_handler*>(control)->control()->CallAfter([=] {
      invoker(args);
      *completed = true;
      invoked->unlock();
    });
  }
}

point control::location(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return {};
  }
  wxPoint location = reinterpret_cast<control_handler*>(control)->control()->GetPosition();
  return {location.x, location.y};
}

void control::location(intptr_t control, const point& location) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->SetPosition({location.x(), location.y()});
}

void control::maximum_client_size(intptr_t control, const drawing::size& size) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->SetMaxClientSize({size.width() != 0 ? size.width() : -1, size.height() != 0 ? size.height() : -1});
}

void control::maximum_size(intptr_t control, const drawing::size& size) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->SetMaxSize({size.width() != 0 ? size.width() : -1, size.height() != 0 ? size.height() : -1});
}

void control::minimum_client_size(intptr_t control, const drawing::size& size) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->SetMinClientSize({size.width(), size.height()});
}

void control::minimum_size(intptr_t control, const drawing::size& size) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->SetMinSize({size.width(), size.height()});
}

drawing::point control::point_to_screen(intptr_t control, const drawing::point& p) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return {};
  }
  wxPoint result = reinterpret_cast<control_handler*>(control)->control()->ClientToScreen(wxPoint(p.x(), p.y()));
  return {result.x, result.y};
}

drawing::point control::point_to_client(intptr_t control, const drawing::point& p) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return {};
  }
  wxPoint result = reinterpret_cast<control_handler*>(control)->control()->ScreenToClient(wxPoint(p.x(), p.y()));
  return {result.x, result.y};
}

drawing::size control::size(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return {};
  }
  wxSize size = reinterpret_cast<control_handler*>(control)->control()->GetSize();
  return {size.GetWidth(), size.GetHeight()};
}

void control::size(intptr_t control, const drawing::size& size) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->SetSize(size.width(), size.height());
}

ustring control::text(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return "";
  }
  return xtd::convert_string::to_string(reinterpret_cast<control_handler*>(control)->control()->GetLabel().c_str().AsWChar());
}

void control::text(intptr_t control, const ustring& text) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->SetLabel(convert_string::to_wstring(text));
}

bool control::visible(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return false;
  }
  return reinterpret_cast<control_handler*>(control)->control()->IsShown();
}

void control::visible(intptr_t control, bool visible) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->Show(visible);
}

void control::invalidate(intptr_t control, const drawing::rectangle& rect, bool erase_background) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->main_control()->RefreshRect(wxRect(rect.left(), rect.top(), rect.width(), rect.height()), erase_background);
  reinterpret_cast<control_handler*>(control)->main_control()->Update();
}

void control::refresh(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->main_control()->Refresh();
}

void control::update(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->main_control()->Update();
}

void control::register_wnd_proc(intptr_t control, const delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>& wnd_proc) {
  if (!control) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->wnd_proc = wnd_proc;
}

void control::unregister_wnd_proc(intptr_t control) {
  if (!control) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->wnd_proc = nullptr;
}

intptr_t control::send_message(intptr_t control, intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam) {
  if (!control) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return static_cast<intptr_t>(-1);
  }
  return reinterpret_cast<control_handler*>(control)->send_message(hwnd, msg, wparam, lparam, 0);
}
