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
#include <wx/panel.h>
#include <wx/statbox.h>
#include "control_handler.h"

namespace xtd {
  namespace forms {
    namespace native {
      class control;
      template<typename control_t>
      class control_wrapper;
      class group_box;
      class wx_group_box;
      class wxGroupBox : public wxStaticBox {
        template<typename control_t>
        friend class control_wrapper;
        friend xtd::forms::native::group_box;
        friend xtd::forms::native::wx_group_box;
      private:
        wxGroupBox(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxString& name = wxASCII_STR(wxStaticBoxNameStr)) : wxStaticBox(parent, id, label, pos, size, style, name) {
          //SetBackgroundColour({255, 0, 0});
          //inner_panel->SetBackgroundColour({0, 255, 0});
          Bind(wxEVT_SIZE, [&](wxSizeEvent & event) {
            inner_panel->SetPosition(get_inner_box_position());
            inner_panel->SetSize(get_inner_box_size());
            event.Skip();
          });
        }
        
        wxPoint GetClientAreaOrigin() const override {return {inner_margin, inner_margin + extra_inner_margin_up};}
        
        void DoGetClientSize(int* width, int* height) const override {
          wxStaticBox::DoGetSize(width, height);
          *width = *width - GetClientAreaOrigin().x - inner_margin;
          *height = *height - GetClientAreaOrigin().y - inner_margin;
        }
        
        //wxWindow* GetMainWindowOfCompositeControl() override {return inner_panel;}
        
      private:
        wxPoint get_inner_box_position() const {
          if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows") return {0, inner_margin + extra_inner_margin_up};
          if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh") return {inner_margin, inner_margin + extra_inner_margin_up};
          if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Unix") return {inner_margin, 0};
          return {0, 0};
        }
        
        wxSize get_inner_box_size() const {
          if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows") return {GetClientSize().GetWidth(), GetClientSize().GetHeight() - GetClientAreaOrigin().y};
          if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh") return {GetClientSize().GetWidth() - GetClientAreaOrigin().x - inner_margin, GetClientSize().GetHeight() - GetClientAreaOrigin().y - inner_margin};
          if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Unix") return {GetClientSize().GetWidth() - inner_margin, GetClientSize().GetHeight() - GetClientAreaOrigin().y - inner_margin};
          return GetClientSize();
        }
        
        static constexpr int32_t inner_margin = 3;
        static constexpr int32_t extra_inner_margin_up = 5;
        wxPanel* inner_panel = new wxPanel(this, wxID_ANY, get_inner_box_position(), get_inner_box_size());
      };
      
      class wxGroupBoxOwnerDraw : public wxPanel {
        template<typename control_t>
        friend class control_wrapper;
        friend xtd::forms::native::group_box;
        friend xtd::forms::native::wx_group_box;
      private:
        wxGroupBoxOwnerDraw(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxString& name = wxASCII_STR(wxStaticBoxNameStr)) : wxPanel(parent, id, pos, size, style, name) {
          Bind(wxEVT_SIZE, [&](wxSizeEvent&) {
          });
        }
        
        //bool AcceptsFocus() const override {return false;}
        
        //bool AcceptsFocusFromKeyboard() const override {return false;}
        
        wxPoint GetClientAreaOrigin() const override {
          return {inner_margin + (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh" ? 2 : 0), inner_margin + (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh" ? 13 : 5)};
        }
        
        void DoSetSize(int x, int y, int width, int height, int sizeFlags = wxSIZE_AUTO) override {
          wxPanel::DoSetSize(x, y, width, height, sizeFlags);
        }
        
        void DoGetClientSize(int* width, int* height) const override {
          wxPanel::DoGetSize(width, height);
          *width = *width - GetClientAreaOrigin().x - inner_margin - (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh" ? 2 : 0);
          *height = *height - GetClientAreaOrigin().y - inner_margin - (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh" ? 2 : 0);
        }
        
        void DoSetClientSize(int width, int height) override {
          DoSetSize(GetPosition().x, GetPosition().y, width + GetClientAreaOrigin().x + inner_margin + (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh" ? 2 : 0), height + GetClientAreaOrigin().y + inner_margin + (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh" ? 2 : 0));
        }
        
      private:
        static constexpr int32_t inner_margin = 3;
      };
      
      class wx_group_box : public control_handler {
        friend xtd::forms::native::control;
        friend xtd::forms::native::group_box;
      private:
        explicit wx_group_box(const xtd::forms::native::create_params& create_params) {
          if (!create_params.parent) throw xtd::argument_exception("control must have a parent"_t, current_stack_frame_);
          owner_draw_ = (create_params.style & BS_OWNERDRAW) == BS_OWNERDRAW;
          if (owner_draw_)
            control_handler::create<wxGroupBoxOwnerDraw>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxString(xtd::convert_string::to_wstring(create_params.caption)), wxPoint(create_params.location.x(), create_params.location.y()), wxSize(create_params.size.width(), create_params.size.height()), style_to_wx_style(create_params.style, create_params.ex_style));
          else {
            control_handler::create<wxGroupBox>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxString(xtd::convert_string::to_wstring(create_params.caption)), wxPoint(create_params.location.x(), create_params.location.y()), wxSize(create_params.size.width(), create_params.size.height()), style_to_wx_style(create_params.style, create_params.ex_style));
            #if defined(__WIN32__)
            if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
              control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
              control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
            }
            #endif
          }
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = 0;
          return wx_style;
        }
        
        bool owner_draw_ = false;
      };
    }
  }
}

