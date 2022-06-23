#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "control_wrapper.h"

namespace xtd {
  namespace forms {
    namespace native {
      class control_handler : xtd::object {
      public:
        control_handler() = default;
        
        template<typename control_type, typename ...args_type>
        void create(args_type&& ...args) {
          control_ = new control_wrapper<control_type>(this, args...);
          control_->SetClientData(this);
          def_wnd_proc = std::bind(&control_wrapper<control_type>::def_wnd_proc, static_cast<control_wrapper<control_type>*>(control_), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6);
        }
        
        intptr_t send_message(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t handle) {
          if (xtd::drawing::native::wx_application::message_filter(hwnd, msg, wparam, lparam, handle)) return call_def_wnd_proc(hwnd, msg, wparam, lparam, 1, handle);
          if (!wnd_proc) return call_def_wnd_proc(hwnd, msg, wparam, lparam, 0, handle);
          return wnd_proc(hwnd, msg, wparam, lparam, handle);
        }
        
        virtual bool Destroy() {
          if (!control_) return false;
          return control_->Destroy();
        }
        
        virtual wxRect GetClientRect() const {
          if (!control_) return {};
          return control_->GetClientRect();
        }
        
        virtual wxSize GetClientSize() const {
          if (!control_) return {};
          return control_->GetClientSize();
        }
        
        virtual wxPoint GetPosition() const {
          if (!control_) return {};
          return control_->GetPosition();
        }
        
        virtual wxSize GetSize() const {
          if (!control_) return {};
          return control_->GetSize();
        }
        
        virtual void SetBackgroundColour(const wxColour& colour) {
          if (!control_) return;
          control_->SetBackgroundColour(colour);
        }
        
        virtual void SetCursor(const wxCursor& cursor) {
          if (!control_) return;
          control_->SetCursor(cursor);
        }
        
        virtual void SetLabel(const wxString& label) {
          if (!control_) return;
          control_->SetLabel(label);
        }
        
        virtual void SetForegroundColour(const wxColour& colour) {
          if (!control_) return;
          control_->SetForegroundColour(colour);
        }
        
        virtual void SetPosition(const wxPoint& location) {
          if (!control_) return;
          control_->SetPosition(location);
        }
        
        virtual void SetClientSize(int32_t width, int32_t height) {
          if (!control_) return;
          control_->SetClientSize(width, height);
        }
        
        virtual void SetSize(int32_t width, int32_t height) {
          if (!control_) return;
          control_->SetSize(width, height);
        }
        
        virtual void Show(bool visible) {
          if (!control_) return;
          control_->Show(visible);
        }
        
        static long common_window_style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = 0;
          
          if ((style & WS_BORDER) == WS_BORDER) wx_style |= wxBORDER_SIMPLE;
          else if ((ex_style & WS_EX_CLIENTEDGE) == WS_EX_CLIENTEDGE) wx_style |= wxBORDER_SUNKEN;
          else wx_style |= wxBORDER_NONE;
          
          return wx_style;
        }
        
        wxWindow* control() const { return control_; }
        virtual wxWindow* main_control() const { return !control_ ? nullptr : control_->GetMainWindowOfCompositeControl(); }
        
        void reset_control() { control_ = nullptr; }
        
        virtual bool enable_send_paint_event() const { return control() && control() == main_control(); }
        
        void clear_control() { control_ = nullptr; }
        
        intptr_t call_def_wnd_proc(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t result, intptr_t handle) { return def_wnd_proc ? def_wnd_proc(hwnd, msg, wparam, lparam, result, handle) : 0; }
        
        std::function<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)> wnd_proc;
        std::function<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t, intptr_t)> def_wnd_proc;
        
      private:
        wxWindow* control_ = nullptr;
      };
    }
  }
}

#include "control_wrapper_code.h"
