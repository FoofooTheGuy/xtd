/// @file
/// @brief Contains xtd::forms::group_box container.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "control.h"
#include "border_style.h"
#include "flat_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a Windows control that displays a frame around a group of controls with an optional caption.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
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
    ///     <td>@image html containers_group_box_w.png</td>
    ///     <td>@image html containers_group_box_m.png</td>
    ///     <td>@image html containers_group_box_g.png</td>
    ///   </tr>
    ///   <tr>
    ///     <td>Dark</td>
    ///     <td>@image html containers_group_box_wd.png</td>
    ///     <td>@image html containers_group_box_md.png</td>
    ///     <td>@image html containers_group_box_gd.png</td>
    ///   </tr>
    /// </table>
    /// @par Examples
    /// The following code example demonstrates the use of group_box container.
    /// @include group_box.cpp
    /// @par Examples
    /// The following code example demonstrates the use of group_box container and check_box controls.
    /// @include group_box_and_check_box.cpp
    /// @par Examples
    /// The following code example demonstrates the use of group_box container and radio_button controls.
    /// @include group_box_and_radio_button.cpp
    class forms_export_ group_box : public control {
      struct data;
      
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the group_box class.
      group_box();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets how the group_box behaves when its auto_size property is enabled
      /// @return One of the xtd::forms::auto_size_mode values. The default is xtd::forms::auto_size_mode::grow_only.
      virtual forms::auto_size_mode auto_size_mode() const noexcept;
      /// @brief Sets how the group_box behaves when its auto_size property is enabled
      /// @param value One of the xtd::forms::auto_size_mode values. The default is xtd::forms::auto_size_mode::grow_only.
      /// @return Current group_box.
      virtual group_box& auto_size_mode(forms::auto_size_mode value);
      
      using control::control_appearance;
      control& control_appearance(forms::control_appearance value) override;
      
      /// @brief Gets the flat style appearance of the xtd::forms::group_box control.
      /// @return One of the xtd::forms::flat_style values. The default value is xtd::forms::flat_style::standard.
      virtual xtd::forms::flat_style flat_style() const noexcept;
      /// @brief Sets the flat style appearance of the xtd::forms::group_box control.
      /// @param flat_style One of the xtd::forms::flat_style values. The default value is xtd::forms::flat_style::standard.
      virtual xtd::forms::group_box& flat_style(xtd::forms::flat_style flat_style);
      /// @}
      
    protected:
      /// @name Protectd properties
      
      /// @{
      forms::create_params create_params() const noexcept override;
      /// @}
      
      /// @name Protectd methods
      
      /// @{
      drawing::size measure_control() const noexcept override;
      void on_font_changed(const xtd::event_args& e) override;
      void on_resize(const xtd::event_args& e) override;
      void on_text_changed(const xtd::event_args& e) override;
      /// @}
      
    private:
      std::shared_ptr<data> data_;
    };
  }
}
