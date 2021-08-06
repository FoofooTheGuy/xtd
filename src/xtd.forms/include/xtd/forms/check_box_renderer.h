/// @file
/// @brief Contains xtd::forms::check_box_renderer class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <optional>
#include <string>
#include <xtd/drawing/color.h>
#include <xtd/drawing/font.h>
#include <xtd/drawing/graphics.h>
#include <xtd/drawing/image.h>
#include <xtd/drawing/rectangle.h>
#include <xtd/drawing/system_fonts.h>
#include "../forms_export.h"
#include "text_format_flags.h"
#include "theme_renderers.h"
#include "theme_colors.h"
#include "visual_styles/check_box_state.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides check box renderer methods.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms renderers
    class forms_export_ check_box_renderer final static_ {
    public:
      static void draw_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::check_box_state& state) {draw_check_box(default_theme(), g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), false, state, xtd::forms::theme_colors::current_theme().control(), xtd::forms::theme_colors::current_theme().control_text());}
      static void draw_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, bool focused, xtd::forms::visual_styles::check_box_state& state) {draw_check_box(default_theme(), g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), true, state, xtd::forms::theme_colors::current_theme().control(), xtd::forms::theme_colors::current_theme().control_text());}
      static void draw_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state) {draw_check_box(default_theme(), g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, image, image_bounds, focused, state, xtd::forms::theme_colors::current_theme().control(), xtd::forms::theme_colors::current_theme().control_text());}
      static void draw_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, bool focused, xtd::forms::visual_styles::check_box_state state) {draw_check_box(default_theme(), g, bounds, text, font, xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), focused, state, xtd::forms::theme_colors::current_theme().control(), xtd::forms::theme_colors::current_theme().control_text());}
      static void draw_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, bool focused, xtd::forms::visual_styles::check_box_state state) {draw_check_box(default_theme(), g, bounds, text, font, flags, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), false, state, xtd::forms::theme_colors::current_theme().control(), xtd::forms::theme_colors::current_theme().control_text());}
      static void draw_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state) {draw_check_box(default_theme(), g, bounds, text, font, xtd::forms::text_format_flags::default_format, image, image_bounds, focused, state, xtd::forms::theme_colors::current_theme().control(), xtd::forms::theme_colors::current_theme().control_text());}
      static void draw_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state) {draw_check_box(default_theme(), g, bounds, text, font, flags, image, image_bounds, focused, state, xtd::forms::theme_colors::current_theme().control(), xtd::forms::theme_colors::current_theme().control_text());}
      static void draw_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {draw_check_box(default_theme(), g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);}
      static void draw_check_box(const xtd::ustring& theme, xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::check_box_state& state) {draw_check_box(theme, g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), false, state, xtd::forms::theme_colors::current_theme().control(), xtd::forms::theme_colors::current_theme().control_text());}
      static void draw_check_box(const xtd::ustring& theme, xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, bool focused, xtd::forms::visual_styles::check_box_state& state) {draw_check_box(theme, g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), true, state, xtd::forms::theme_colors::current_theme().control(), xtd::forms::theme_colors::current_theme().control_text());}
      static void draw_check_box(const xtd::ustring& theme, xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state) {draw_check_box(theme, g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, image, image_bounds, focused, state, xtd::forms::theme_colors::current_theme().control(), xtd::forms::theme_colors::current_theme().control_text());}
      static void draw_check_box(const xtd::ustring& theme, xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, bool focused, xtd::forms::visual_styles::check_box_state state) {draw_check_box(theme, g, bounds, text, font, xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), focused, state, xtd::forms::theme_colors::current_theme().control(), xtd::forms::theme_colors::current_theme().control_text());}
      static void draw_check_box(const xtd::ustring& theme, xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, bool focused, xtd::forms::visual_styles::check_box_state state) {draw_check_box(theme, g, bounds, text, font, flags, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), false, state, xtd::forms::theme_colors::current_theme().control(), xtd::forms::theme_colors::current_theme().control_text());}
      static void draw_check_box(const xtd::ustring& theme, xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state) {draw_check_box(theme, g, bounds, text, font, xtd::forms::text_format_flags::default_format, image, image_bounds, focused, state, xtd::forms::theme_colors::current_theme().control(), xtd::forms::theme_colors::current_theme().control_text());}
      static void draw_check_box(const xtd::ustring& theme, xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state) {draw_check_box(theme, g, bounds, text, font, flags, image, image_bounds, focused, state, xtd::forms::theme_colors::current_theme().control(), xtd::forms::theme_colors::current_theme().control_text());}
      static void draw_check_box(const xtd::ustring& theme, xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      
      static void draw_flat_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::check_box_state& state) {draw_flat_check_box(g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), false, state, xtd::forms::theme_colors::current_theme().control(), xtd::forms::theme_colors::current_theme().control_text());}
      static void draw_flat_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, bool focused, xtd::forms::visual_styles::check_box_state& state) {draw_flat_check_box(g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), true, state, xtd::forms::theme_colors::current_theme().control(), xtd::forms::theme_colors::current_theme().control_text());}
      static void draw_flat_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state) {draw_flat_check_box(g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, image, image_bounds, focused, state, xtd::forms::theme_colors::current_theme().control(), xtd::forms::theme_colors::current_theme().control_text());}
      static void draw_flat_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, bool focused, xtd::forms::visual_styles::check_box_state state) {draw_flat_check_box(g, bounds, text, font, xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), focused, state, xtd::forms::theme_colors::current_theme().control(), xtd::forms::theme_colors::current_theme().control_text());}
      static void draw_flat_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, bool focused, xtd::forms::visual_styles::check_box_state state) {draw_flat_check_box(g, bounds, text, font, flags, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), false, state, xtd::forms::theme_colors::current_theme().control(), xtd::forms::theme_colors::current_theme().control_text());}
      static void draw_flat_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state) {draw_flat_check_box(g, bounds, text, font, xtd::forms::text_format_flags::default_format, image, image_bounds, focused, state, xtd::forms::theme_colors::current_theme().control(), xtd::forms::theme_colors::current_theme().control_text());}
      static void draw_flat_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state) {draw_flat_check_box(g, bounds, text, font, flags, image, image_bounds, focused, state, xtd::forms::theme_colors::current_theme().control(), xtd::forms::theme_colors::current_theme().control_text());}
      static void draw_flat_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      
      static void draw_popup_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::check_box_state& state) {draw_popup_check_box(g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), false, state, xtd::forms::theme_colors::current_theme().control(), xtd::forms::theme_colors::current_theme().control_text());}
      static void draw_popup_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, bool focused, xtd::forms::visual_styles::check_box_state& state) {draw_popup_check_box(g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), true, state, xtd::forms::theme_colors::current_theme().control(), xtd::forms::theme_colors::current_theme().control_text());}
      static void draw_popup_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state) {draw_popup_check_box(g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, image, image_bounds, focused, state, xtd::forms::theme_colors::current_theme().control(), xtd::forms::theme_colors::current_theme().control_text());}
      static void draw_popup_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, bool focused, xtd::forms::visual_styles::check_box_state state) {draw_popup_check_box(g, bounds, text, font, xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), focused, state, xtd::forms::theme_colors::current_theme().control(), xtd::forms::theme_colors::current_theme().control_text());}
      static void draw_popup_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, bool focused, xtd::forms::visual_styles::check_box_state state) {draw_popup_check_box(g, bounds, text, font, flags, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), false, state, xtd::forms::theme_colors::current_theme().control(), xtd::forms::theme_colors::current_theme().control_text());}
      static void draw_popup_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state) {draw_popup_check_box(g, bounds, text, font, xtd::forms::text_format_flags::default_format, image, image_bounds, focused, state, xtd::forms::theme_colors::current_theme().control(), xtd::forms::theme_colors::current_theme().control_text());}
      static void draw_popup_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state) {draw_popup_check_box(g, bounds, text, font, flags, image, image_bounds, focused, state, xtd::forms::theme_colors::current_theme().control(), xtd::forms::theme_colors::current_theme().control_text());}
      static void draw_popup_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);

    private:
      static xtd::ustring default_theme() {return theme_renderers::current_theme().name();}
      static void draw_check_box_kde(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_check_box_kde_dark(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_check_box_kde_light(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_check_box_gnome(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_check_box_gnome_dark(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_check_box_gnome_light(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_check_box_macos(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_check_box_macos_dark(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_check_box_macos_light(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_check_box_symbolic(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_check_box_symbolic_dark(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_check_box_symbolic_light(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_check_box_windows(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_check_box_windows_dark(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_check_box_windows_light(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_check_box_xtd(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_check_box_xtd_dark(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_check_box_xtd_light(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_flat_check_box_dark(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_flat_check_box_light(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_popup_check_box_dark(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_popup_check_box_light(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
    };
  }
}
