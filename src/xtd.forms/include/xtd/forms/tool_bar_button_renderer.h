/// @file
/// @brief Contains xtd::forms::tool_bar_button_renderer class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <optional>
#include <string>
#include <xtd/drawing/color.h>
#include <xtd/drawing/font.h>
#include <xtd/drawing/graphics.h>
#include <xtd/drawing/image.h>
#include <xtd/drawing/rectangle.h>
#include "../forms_export.h"
#include "box_renderer.h"
#include "flat_button_appearance.h"
#include "flat_style.h"
#include "text_renderer.h"
#include "visual_styles/push_button_state.h"

/// @todo to remove
#include <xtd/drawing/system_fonts.h>
#include "flat_button_appearance.h"
#include "text_format_flags.h"
#include "theme_renderers.h"
#include "theme_colors.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides button control renderer methods.
    /// @code
    /// class forms_export_ tool_bar_button_renderer static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static → xtd::forms::tool_bar_button_renderer
    /// @par Namespace
    /// xtd::forms:
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms renderers
    class forms_export_ tool_bar_button_renderer final static_ {
    public:
      /// @name Methods
      
      /// @{
      /// @brief Draws a tool bar button in the specified bounds, button style, button state, background color, text, optional text flags, optional foreground color and optional font.
      /// @param style_sheet The xtd::forms::style_sheets::style_sheet used to draw a button.
      /// @param graphics The xtd::drawing::graphics used to draw a button.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the button.
      /// @param button_state The visual state of a button that is drawn with visual styles.
      /// @param back_color The background color for the button control.
      /// @param text The text of the button control.
      /// @param text_flags Contains the display and layout information for text strings.
      /// @param fore_color The foreground color for the button control.
      /// @param font The font of the text for the button control.
      /// @param image The image of the button control.
      /// @param image_align Contains the display and layout information for image .
      /// @remarks The parameter back_color is set only if they are different from its default value; otherwise std::nullopt.
      static void draw_tool_bar_button(const style_sheets::style_sheet& style_sheet, xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::push_button_state button_state, const std::optional<xtd::drawing::color>& back_color, const flat_button_appearance& appearance, const xtd::ustring& text, const std::optional<xtd::forms::content_alignment>& text_align, const std::optional<xtd::drawing::color>& fore_color, const std::optional<xtd::drawing::font>& font, const xtd::drawing::image& image, const std::optional<xtd::forms::content_alignment>& image_align);     /// @}
    };
  }
}
