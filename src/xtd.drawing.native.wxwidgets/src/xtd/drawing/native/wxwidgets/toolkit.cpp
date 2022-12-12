#include <xtd/delegate.h>
#include <xtd/event.h>
#include <xtd/diagnostics/boolean_switch.h>
#include <xtd/diagnostics/debug.h>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/toolkit.h>
#include <xtd/drawing/native/wx_application.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <wx/app.h>
#include <wx/image.h>
#include <wx/memory.h>
#include <wx/sysopt.h>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing::native;

namespace {
  wxAssertHandler_t original_assert_handler = nullptr;
  boolean_switch show_wx_assert("wx_assert", "Shows wxAssert log", "true");
  
  void xtd_assert_handler(const wxString& file, int32 line, const wxString& func, const wxString& cond, const wxString& msg) {
    // Workaround: wxWidgets generates an unknown assertion when there is a double mouse click event on an empty area of wxCalendarCtrl.
    if (func == "wxCalendarCtrl::HitTest" && cond == "\"Assert failure\"" && msg == "unexpected") return;
    // Workaround: wxWidgets generates an assert if wxApp is not running when call exit.
    if (func == "wxEventLoopBase::Exit" && cond == "\"IsRunning()\"" && msg == "Use ScheduleExit() on not running loop") return;
    // Workaround: wxWidgets generates an assert if bitmap is empty.
    if (func.Contains("GetHeight") && cond == "\"IsOk()\"" && msg == "invalid bitmap") return;
    // Workaround: wxWidgets generates an assert if bitmap is empty.
    if (func.Contains("GetWidth") && cond == "\"IsOk()\"" && msg == "invalid bitmap") return;
    // Workaround: wxWidgets generates an assert if wxPaintDC is not call in paint event.
    if (func.Contains("wxPaintDCImpl::wxPaintDCImpl") && cond == "\"paintStack.top().window == window\"" && msg == "wxPaintDC must be associated with the window being repainted") return;
    // Workaround: wxWidgets generates an assert if wxPaintDC is not call in paint event.
    if (func.Contains("wxClientDCImpl::DoGetSize") && cond == "\"m_window\"" && msg == "wxClientDCImpl without a window?") return;
    // Workaround: wxWidgets generates an assert if wxPaintDC is not call in paint event.
    if (func.Contains("wxTextMeasure::BeginMeasuring") && cond == "m_hdc" && msg == "Must not be used with non-native wxDCs") return;

    debug::write_line_if(show_wx_assert.enabled(), "wxAssert");
    debug::write_line_if(show_wx_assert.enabled(), "--------");
    debug::write_line_if(show_wx_assert.enabled(), ustring::format("cond={}, msg={}", cond, msg));
    debug::write_line_if(show_wx_assert.enabled(), ustring::format("  at {} in {}:line {}", func, file, line));
    assert_(false);
  }
}

intptr toolkit::initialize() {
  if (wxTheApp) return 0;
  #ifdef _MSC_VER
  // Workaround : Dump memory leak : Remove temporary memory check...
  _CrtSetDbgFlag(_CRTDBG_CHECK_DEFAULT_DF);
  #endif
  wxDISABLE_DEBUG_SUPPORT();
  original_assert_handler = wxSetAssertHandler(&xtd_assert_handler);
  wxLog::SetLogLevel(wxLOG_Info);
  wxSystemOptions::SetOption("gtk.tlw.can-set-transparent", 1);
  wxSystemOptions::SetOption("osx.openfiledialog.always-show-types", 1);
  wxApp::SetInstance(new wx_application());
  int32 argc = 0;
  wxEntryStart(argc, (wxChar**)nullptr);
  wxTheApp->CallOnInit();
  wxTheApp->SetExitOnFrameDelete(false);
  wxInitAllImageHandlers();
  return 0;
}

void toolkit::shutdown(intptr handle) {
  if (!wxTheApp) return;
  
  wxImage::CleanUpHandlers();
  wxTheApp->OnExit();
  wxApp::SetInstance(nullptr);
  delete wxTheApp;
}
