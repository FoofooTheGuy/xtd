#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/argument_exception.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/native/create_params.h>
#include <xtd/forms/choose_color_flags.h>
#include <wx/clrpicker.h>
#include "control_handler.h"

namespace xtd {
  namespace forms {
    namespace native {
      class color_picker;
      class control;
      class wx_color_picker : public control_handler {
        friend xtd::forms::native::color_picker;
        friend xtd::forms::native::control;
      private:
        explicit wx_color_picker(const xtd::forms::native::create_params& create_params) {
          if (!create_params.parent) throw xtd::argument_exception("control must have a parent"_t, current_stack_frame_);
          int32_t style = wxCLRP_DEFAULT_STYLE;
          if ((create_params.style & CC_ALPHACOLOR) == CC_ALPHACOLOR) style |= wxCLRP_SHOW_ALPHA;
          control_handler::create<wxColourPickerCtrl>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxColour(0, 0, 0), wxPoint(create_params.location.x(), create_params.location.y()), wxSize(create_params.size.width(), create_params.size.height()), style);
          #if defined(__WIN32__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            static_cast<wxColourPickerCtrl*>(control())->GetPickerCtrl()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::button_face().r(), xtd::drawing::system_colors::button_face().g(), xtd::drawing::system_colors::button_face().b(), xtd::drawing::system_colors::button_face().a()));
            static_cast<wxColourPickerCtrl*>(control())->GetPickerCtrl()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
          #endif
        }
        
        void SetBackgroundColour(const wxColour& colour) override {
          control_handler::SetBackgroundColour(colour);
          static_cast<wxColourPickerCtrl*>(control())->GetPickerCtrl()->SetBackgroundColour(colour);
        }
        
        void SetPosition(const wxPoint& pt) override {
          control_handler::SetPosition(pt);
        }
        
        wxSize GetClientSize() const override {
          return control()->GetSize();
        }
        
        void SetClientSize(int32_t width, int32_t height) override {
          SetSize(width, height);
        }
      };
    }
  }
}
