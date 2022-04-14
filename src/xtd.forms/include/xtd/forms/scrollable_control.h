/// @file
/// @brief Contains xtd::forms::scrollable_control control.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "control.h"
#include "system_information.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Defines a base class for controls that support auto-scrolling behavior.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class forms_export_ scrollable_control : public control {
    public:
      /// @name Properties
      
      /// @{
      /// @brief Gets a value indicating whether the container enables the user to scroll to any controls placed outside of its visible boundaries.
      /// @return true if the container enables auto-scrolling; otherwise, false. The default value is false.
      virtual bool auto_scroll() const {return auto_scroll_;}
      /// @brief Sets a value indicating whether the container enables the user to scroll to any controls placed outside of its visible boundaries.
      /// @param auto_scroll true if the container enables auto-scrolling; otherwise, false. The default value is false.
      /// @return Current scrollable_control instance.
      virtual scrollable_control& auto_scroll(bool auto_scroll) {
        if (auto_scroll_ != auto_scroll) {
          auto_scroll_ = auto_scroll;
          post_recreate_handle();
        }
        return *this;
      }
      
      /// @brief Gets the size of the auto-scroll margin.
      /// @return A size that represents the height and width of the auto-scroll margin in pixels.
      drawing::size auto_scroll_margin() const {return auto_scroll_margin_;}
      /// @brief Sets the size of the auto-scroll margin.
      /// @param value A size that represents the height and width of the auto-scroll margin in pixels.
      /// @return Current scrollable_control instance.
      scrollable_control& auto_scroll_margin(const drawing::size& value) {
        if (auto_scroll_margin_ != value) {
          auto_scroll_margin_ = value;
          perform_layout();
        }
        return *this;
      }
      
      /// @brief Gets the rectangle that represents the virtual display area of the control.
      /// @return A rectangle that represents the display area of the control.
      drawing::rectangle display_rectangle() const override {return display_rectangle_;}
      
      /// @brief Gets a value indicating whether the horizontal scroll bar is visible.
      /// @return true if the horizontal scroll bar is visible; otherwise, false.
      virtual bool h_scroll() const {return h_scroll_;}
      /// @brief Sets a value indicating whether the horizontal scroll bar is visible.
      /// @param hscrooll true if the horizontal scroll bar is visible; otherwise, false.
      /// @return Current scrollable_control instance.
      virtual scrollable_control& h_scroll(bool h_scroll) {
        if (h_scroll_ != h_scroll) {
          h_scroll_ = h_scroll;
          post_recreate_handle();
        }
        return *this;
      }
      
      /// @brief Gets a value indicating whether the vertical scroll bar is visible.
      /// @return true if the vertical scroll bar is visible; otherwise, false.
      virtual bool v_scroll() const {return v_scroll_;}
      /// @brief Sets a value indicating whether the vertical scroll bar is visible.
      /// @param vscroll true if the vertical scroll bar is visible; otherwise, false.
      /// @return Current scrollable_control instance.
      virtual scrollable_control& v_scroll(bool v_scroll) {
        if (v_scroll_ != v_scroll) {
          v_scroll_ = v_scroll;
          post_recreate_handle();
        }
        return *this;
      }
      /// @}
      
    protected:
      /// @name Protected constructors
      
      /// @{
      /// @brief Initialize a new instance of scrollable_control class.
      scrollable_control();
      /// @}
      
      /// @name Protected methods
      
      /// @{
      forms::create_params create_params() const override;
      
      void on_layout(const event_args& e) override {
        control::on_layout(e);
        if (auto_scroll_) {
          display_rectangle_ = control::client_rectangle();
          display_rectangle_.height(display_rectangle_.height() - system_information::horizontal_scroll_bar_height());
          display_rectangle_.width(display_rectangle_.width() - system_information::vertical_scroll_bar_width());
          for (auto item : controls()) {
            if (item.get().visible())
              display_rectangle_ = drawing::rectangle::make_union(display_rectangle_, item.get().bounds());
          }
          display_rectangle_.width(display_rectangle_.width() + auto_scroll_margin_.width());
          display_rectangle_.height(display_rectangle_.height() + auto_scroll_margin_.height());
        }
      }
      /// @}
      
    private:
      /// @cond
      bool auto_scroll_ = false;
      bool h_scroll_ = false;
      bool v_scroll_ = false;
      drawing::rectangle display_rectangle_;
      drawing::size auto_scroll_margin_;
      /// @endcond
    };
  }
}
