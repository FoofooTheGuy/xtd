/// @file
/// @brief Contains xtd::forms::panel container.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <optional>
#include "scrollable_control.h"
#include "border_sides.h"
#include "border_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Used to group collections of controls.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
    /// @par Examples
    /// The following code example demonstrates the use of panel container.
    /// @include panel.cpp
    class forms_export_ panel : public scrollable_control {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initialises a new instance of panel class.
      panel();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the mode by which the panel automatically resizes itself.
      /// @return An auto_size_mode enumerated value. The default is grow_only.
      virtual forms::auto_size_mode auto_size_mode() const {return get_auto_size_mode();}
      /// @brief Sets the mode by which the panel automatically resizes itself.
      /// @param value An auto_size_mode enumerated value. The default is grow_only.
      /// @return Current panel instance.
      virtual panel& auto_size_mode(forms::auto_size_mode value);
      
      /// @brief Gets the border sides for the control.
      /// @return A bitwise combination of the A bitwise combination values. The default is border_style::all.
      virtual forms::border_sides border_sides() const {return border_sides_;}
      /// @brief Sets the border sides for the control.
      /// @param border_style A bitwise combination of the border_sides values. The default is border_style::all.
      virtual panel& border_sides(forms::border_sides border_sides);
      
      /// @brief Gets the border style for the control.
      /// @return One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual forms::border_style border_style() const {return border_style_.value_or(forms::border_style::none);}
      /// @brief Sets the border style for the control.
      /// @param border_style One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @return Current panel instance.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual panel& border_style(forms::border_style border_style);
      /// @brief Resets the border style for the control.
      /// @param border_style nullptr.
      /// @return Current panel instance.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual panel& border_style(std::nullptr_t border_style);
      /// @}
      
    protected:
      /// @name Protetced properties
      
      /// @{
      forms::create_params create_params() const override;
      /// @}

      /// @name Protetced methods
      
      /// @{
      drawing::size measure_control() const override;
      void on_layout(const event_args& e) override;
      void on_paint(paint_event_args& e) override;
      /// @}
      
      /// @cond
      forms::border_sides border_sides_ = forms::border_sides::all;
      std::optional<forms::border_style> border_style_;
      /// @endcond
    };
  }
}
