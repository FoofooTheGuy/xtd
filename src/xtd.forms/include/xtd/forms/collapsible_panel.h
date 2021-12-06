/// @file
/// @brief Contains xtd::forms::collapsible_panel container.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "control.h"
#include "border_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Used to group collections of controls in a collapsible panel.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
    /// @par Examples
    /// The following code example demonstrate the use of collapsible_panel container.
    /// @include collapsible_panel.cpp
    class forms_export_ collapsible_panel : public control {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the collapsible_panel class.
      collapsible_panel();
      /// @}

      /// @name Properties
      
      /// @{
      virtual bool auto_size() const override {return true;}

      /// @brief Get the border style for the control.
      /// @return One of the border_style values. The default is border_style::none.
      /// @remarks By default, the collapsible_panel control is displayed without a border. You can use this property to distinguish the boundaries of the collapsible_panel control from other areas on the form.
      virtual forms::border_style border_style() const {return border_style_;}
      /// @brief Set the border style for the control.
      /// @param border_style One of the border_style values. The default is border_style::none.
      /// @remarks By default, the collapsible_panel control is displayed without a border. You can use this property to distinguish the boundaries of the collapsible_panel control from other areas on the form.
      virtual collapsible_panel& border_style(forms::border_style border_style);

      drawing::size default_size() const override {return {0, 0};}
      
      /// @brief Gets a value indicating whether the collapsible_panel is in the expanded.
      /// @return true if collapsible_panel is expanded; otherwise false.
      bool expanded() const {return expanded_;}
      /// @brief Sets a value indicating whether the collapsible_panel is in the expanded.
      /// @param expanded true if collapsible_panel is expanded; otherwise false.
      collapsible_panel& expanded(bool expanded);

      /// @cond
      const xtd::drawing::size& client_size() const override {return control::client_size();}
      const xtd::drawing::size& size() const override {return control::size();}
      /// @endcond
      /// @}

      /// @name Methods
      
      /// @{
      /// @brief Collapse the collapsible_panel.
      /// @remarks Collapsing the collapsible_panel is equivalent to setting the expanded property to false. After the collapse method is called, the expanded property returns a value of false until the expand method is called.
      void collapse() {expanded(false);}

      /// @brief Expand the collapsible_panel.
      /// @remarks Expanding the collapsible_panel is equivalent to setting the expanded property to true. After the expand method is called, the expanded property returns a value of true until the collapse method is called.
      void expand() {expanded(true);}
      /// @}
      
      /// @name Events
      
      /// @{
      /// @brief Occurs when the expanded property changes.
      /// @ingroup events
      xtd::event<collapsible_panel, xtd::event_handler> expanded_changed;
      /// @}

    protected:
      /// @name Protected methods
      
      /// @{
      forms::create_params create_params() const override;
      
      drawing::size measure_control() const override;
      
      void on_control_added(const control_event_args& e) override;
      
      void on_control_removed(const control_event_args& e) override;
      
      /// @brief Raises the collapsible_panel::expanded_changed event.
      virtual void on_expanded_changed(const xtd::event_args& e);

      void on_handle_created(const event_args& e) override;

      void wnd_proc(message& message) override;
      /// @}

    private:
      control& auto_size(bool auto_size) override {return control::auto_size(auto_size);}
      control& client_size(const xtd::drawing::size& client_size) override {return control::size(client_size);}
      control& size(const xtd::drawing::size& size) override {return control::size(size);}
      void wm_command(message& message);

      forms::border_style border_style_ = forms::border_style::none;
      bool expanded_ = false;
    };
  }
}
