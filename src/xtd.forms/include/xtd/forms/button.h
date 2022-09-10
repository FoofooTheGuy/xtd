/// @file
/// @brief Contains xtd::forms::button control.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/environment.h>
#include "button_base.h"
#include "dialog_result.h"
#include "ibutton_control.h"
#include "timer.h"
#include "visual_styles/push_button_state.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a Windows button control.
    /// @code
    /// class forms_export_ button : public xtd::forms::ibutton_control, public xtd::forms::button_base
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::forms::component → xtd::forms::control → xtd::forms::button_base → xtd::forms::button
    /// @par Implements
    /// xtd::forms::ibutton_control
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @remarks A Button can be clicked by using the mouse, ENTER key, or SPACEBAR if the button has focus.
    /// @remarks Set the accept_button or cancel_button property of a form to allow users to click a button by pressing the ENTER or ESC keys even if the button does not have focus. This gives the form the behavior of a dialog box.
    /// @remarks When you display a form using the show_dialog method, you can use the dialog_result property of a button to specify the return value of show_dialog.
    /// @remarks You can change the button's appearance. For example, to make it appear flat for a Web look, set the flat_style property to flat_style::flat. The flat_style property can also be set to flat_style::popup, which appears flat until the mouse pointer passes over the button; then the button takes on the standard Windows button appearance.
    /// @note If the control that has focus accepts and processes the ENTER key press, the button does not process it. For example, if a multiline text_box or another button has focus, that control processes the ENTER key press instead of the accept button.
    /// @par Appearance
    /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
    ///   <tr>
    ///     <th style="width:100px"></th>
    ///     <th><b>Windows</b></th>
    ///     <th><b>macOS</b></th>
    ///     <th><b>Gnome</b></th>
    ///   </tr>
    ///   <tr>
    ///     <th>Light</th>
    ///     <td>@image html control_button_w.png</td>
    ///     <td>@image html control_button_m.png</td>
    ///     <td>@image html control_button_g.png</td>
    ///   </tr>
    ///   <tr>
    ///     <th>Dark</th>
    ///     <td>@image html control_button_wd.png</td>
    ///     <td>@image html control_button_md.png</td>
    ///     <td>@image html control_button_gd.png</td>
    ///   </tr>
    /// </table>
    /// @par Examples
    /// The following code example demonstrates the use of button control.
    /// @include button.cpp
    /// @par Examples
    /// The following code example demonstrates the use of button control with bitmap.
    /// @include bitmap_button.cpp
    class forms_export_ button : public ibutton_control, public button_base {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the button class.
      /// @remarks By default the button displays no caption. To specify the caption text, set the text property.
      button();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets if this button instance is auto repeat.
      /// @return true, if is auto repeat; otherwise false. Default is false.
      virtual bool auto_repeat() const {return data_->auto_repeat;}
      /// @brief Sets if this button instance is auto repeat.
      /// @param auto_repeat true, if is auto repeat; otherwise false. Default is false.
      /// @return This button.
      virtual button& auto_repeat(bool auto_repeat) {
        if (data_->auto_repeat != auto_repeat) {
          data_->auto_repeat = auto_repeat;
          if (!data_->auto_repeat) data_->auto_repeat_timer.enabled(false);
        }
        return *this;
      }
      
      /// @brief Gets the auto repeat delay.
      /// @return Auto repeat delay in milliseconds. Default is 300 ms.
      virtual int32_t auto_repeat_delay() const {return data_->auto_repeat_delay;}
      /// @brief Gets the auto repeat delay.
      /// @param auto_repeat_delay Auto repeat delay in milliseconds. Default is 300 ms.
      /// @return This button.
      virtual button& auto_repeat_delay(int32_t auto_repeat_delay) {
        data_->auto_repeat_delay = auto_repeat_delay;
        return *this;
      }
      
      /// @brief Gets the auto repeat interval.
      /// @return Auto repeat interval in milliseconds. Default is 100 ms.
      virtual int32_t auto_repeat_interval() const {return data_->auto_repeat_interval;}
      /// @brief Gets the auto repeat interval.
      /// @param auto_repeat_delay Auto repeat interval in milliseconds. Default is 100 ms.
      /// @return This button.
      virtual button& auto_repeat_interval(int32_t auto_repeat_interval) {
        data_->auto_repeat_interval = auto_repeat_interval;
        return *this;
      }
      
      /// @brief Gets the mode by which the button automatically resizes itself.
      /// @return One of the AutoSizeMode values. The default value is grow_only.
      virtual forms::auto_size_mode auto_size_mode() const {return get_auto_size_mode();}
      /// @brief Sets the mode by which the button automatically resizes itself.
      /// @param value One of the AutoSizeMode values. The default value is grow only.
      virtual button& auto_size_mode(forms::auto_size_mode value);

      /// @brief Gets is default button.
      /// @return true is default button; otherwise false.
      bool default_button() const {return data_->default_button;}
      
      forms::dialog_result dialog_result() const override {return data_->dialog_result;}
      control& dialog_result(forms::dialog_result dialog_result) override;
      /// @}
      
      /// @name Methods
      
      /// @{
      void notify_default(bool value) override;
      
      void perform_click() override;
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      forms::create_params create_params() const override;

      /// @brief Gets state.
      /// @return One of xtd::forms::visual_styles::push_button_state values.
      xtd::forms::visual_styles::push_button_state state() const noexcept {return data_->state;}
      /// @}
      
      /// @name Protected methods
      
      /// @{
      drawing::size measure_control() const override;
      
      void on_click(const event_args& e) override;
      
      void on_enabled_changed(const event_args& e) override {
        if (flat_style() != xtd::forms::flat_style::system) data_->state = enabled() ? (data_->default_button ? xtd::forms::visual_styles::push_button_state::default_state : xtd::forms::visual_styles::push_button_state::normal) : xtd::forms::visual_styles::push_button_state::disabled;
        button_base::on_enabled_changed(e);
      }
      
      void on_handle_created(const event_args& e) override;
      
      void on_image_changed(const xtd::event_args& e) override;
      
      void on_mouse_down(const mouse_event_args& e) override {
        data_->auto_repeat_timer.interval_milliseconds(data_->auto_repeat_delay);
        data_->auto_repeat_timer.enabled(data_->auto_repeat);
        if (flat_style() != xtd::forms::flat_style::system && enabled()) data_->state = xtd::forms::visual_styles::push_button_state::pressed;
        button_base::on_mouse_down(e);
      }
      
      void on_mouse_enter(const event_args& e) override {
        if (flat_style() != xtd::forms::flat_style::system && enabled()) data_->state = (mouse_buttons() & mouse_buttons::left) == mouse_buttons::left ? xtd::forms::visual_styles::push_button_state::pressed : xtd::forms::visual_styles::push_button_state::hot;
        button_base::on_mouse_enter(e);
      }
      
      void on_mouse_leave(const event_args& e) override {
        if (flat_style() != xtd::forms::flat_style::system && enabled()) data_->state = data_->default_button ? xtd::forms::visual_styles::push_button_state::default_state : xtd::forms::visual_styles::push_button_state::normal;;
        button_base::on_mouse_leave(e);
      }
      
      void on_mouse_up(const mouse_event_args& e) override {
        data_->auto_repeat_timer.enabled(false);
        if (flat_style() != xtd::forms::flat_style::system && enabled() && data_->state == xtd::forms::visual_styles::push_button_state::pressed) data_->state = xtd::forms::visual_styles::push_button_state::hot;
        button_base::on_mouse_up(e);
      }
      
      void on_paint(paint_event_args& e) override;
      
    private:
      struct data {
        bool auto_repeat = false;
        timer auto_repeat_timer;
        int32_t auto_repeat_delay = 300;
        int32_t auto_repeat_interval = 100;
        bool default_button = false;
        forms::dialog_result dialog_result = forms::dialog_result::none;
        xtd::forms::visual_styles::push_button_state state = xtd::forms::visual_styles::push_button_state::normal;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
