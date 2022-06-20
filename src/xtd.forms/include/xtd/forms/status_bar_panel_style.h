/// @file
/// @brief Contains xtd::forms::status_bar_panel_style enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies whether a xtd::forms::status_bar_panel object on a xtd::forms::status_bar control is owner-drawn or system-drawn.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by members such as xtd::forms::tool_bar_button::style.
    /// @remarks The toolbar button appearance is determined by the xtd::forms::tool_bar::appearance property of the toolbar. Setting the xtd::forms::tool_bar::appearance property to xtd::forms::tool_bar_appearance::flat will give the toolbar and its buttons a flat appearance. As the mouse pointer moves over the buttons, they take on a three-dimensional appearance. Also, when the toolbar has a flat appearance, button separators appear as a line rather than as a space between the buttons.
    enum class status_bar_panel_style {
      /// @brief The xtd::forms::status_bar_panel displays text in the standard font.
      text = 1,
      /// @brief The xtd::forms::status_bar_panel is drawn by the owner.
      owner_draw = 2,
      /// @brief The xtd::forms::status_bar_panel contains a xtd::forms::control.
      control = 3,
    };
    
    /// @cond
    inline std::ostream& operator<<(std::ostream& os, status_bar_panel_style value) {return os << to_string(value, {{status_bar_panel_style::text, "text"}, {status_bar_panel_style::owner_draw, "owner_draw"}, {status_bar_panel_style::control, "control"}});}
    inline std::wostream& operator<<(std::wostream& os, status_bar_panel_style value) {return os << to_string(value, {{status_bar_panel_style::text, L"text"}, {status_bar_panel_style::owner_draw, L"owner_draw"}, {status_bar_panel_style::control, L"control"}});}
    /// @endcond
  }
}
