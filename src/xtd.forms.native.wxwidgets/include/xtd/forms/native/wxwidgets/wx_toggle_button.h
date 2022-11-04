#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/argument_exception.h>
#include <xtd/convert_string.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/native/create_params.h>
#include <xtd/forms/native/button_styles.h>
#include <wx/platform.h>
#include <wx/radiobut.h>
#include <wx/tglbtn.h>
#include "control_handler.h"
#include "wx_user_window.h"

#if defined(__APPLE__)
void __set_button_bezel_style__(wxAnyButton* control, int32_t height);
#endif

namespace xtd {
  namespace forms {
    namespace native {
      class control;
      class toggle_button;
      class wx_toggle_button : public control_handler {
        friend xtd::forms::native::control;
        friend xtd::forms::native::toggle_button;
      private:
        explicit wx_toggle_button(const xtd::forms::native::create_params& create_params) {
          if (!create_params.parent) throw xtd::argument_exception("control must have a parent"_t, current_stack_frame_);
          owner_draw_ = (create_params.style & BS_OWNERDRAW) == BS_OWNERDRAW;
          if (owner_draw_) {
            control_handler::create<wx_user_window>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxPoint(create_params.location.x(), create_params.location.y()), wxSize(create_params.size.width(), create_params.size.height()));
            reinterpret_cast<wx_user_window*>(control())->set_accepts_focus(wxPlatformInfo::Get().GetOperatingSystemFamilyName() != "Macintosh");
          } else
            control_handler::create<wxToggleButton>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxString(xtd::convert_string::to_wstring(create_params.caption)), wxPoint(create_params.location.x(), create_params.location.y()), wxSize(create_params.size.width(), create_params.size.height()));
          SetSize(create_params.size.width(), create_params.size.height());
          SetPosition({create_params.location.x(), create_params.location.y()});
          #if defined(__WIN32__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
          #endif
        }
        
        wxSize GetClientSize() const override {
          return control()->GetSize();
        }
        
        void SetClientSize(int32_t width, int32_t height) override {
          control()->SetSize(width, height);
        }
        
        virtual void SetPosition(const wxPoint& pt) override {
          #if defined(__APPLE__)
          if (!owner_draw_) __set_button_bezel_style__((wxAnyButton*)control(), control()->GetSize().GetHeight());
          #endif
          control_handler::SetPosition(pt);
        }
        
        void SetSize(int32_t width, int32_t height) override {
          #if defined(__APPLE__)
          if (!owner_draw_) __set_button_bezel_style__((wxAnyButton*)control(), height);
          #endif
          control_handler::SetSize(width, height);
        }

        bool owner_draw_ = false;
      };
    }
  }
}
