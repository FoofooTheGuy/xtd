/// @file
/// @brief Contains xtd::forms::lcd_label control.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <codecvt>
#include <xtd/argument_out_of_range_exception.h>
#include <xtd/convert_string.h>
#include <xtd/as.h>
#include <xtd/interface.h>
#include "control.h"
#include "dot_matrix_display.h"
#include "lcd_style.h"
#include "nine_segment_display.h"
#include "seven_segment_display.h"
#include "fourteen_segment_display.h"
#include "sixteen_segment_display.h"

namespace xtd {
  namespace forms {
    /// @brief Represents a lcd label.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
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
    ///     <td>@image html control_lcd_label_w.png</td>
    ///     <td>@image html control_lcd_label_m.png</td>
    ///     <td>@image html control_lcd_label_g.png</td>
    ///   </tr>
    ///   <tr>
    ///     <th>Dark</th>
    ///     <td>@image html control_lcd_label_wd.png</td>
    ///     <td>@image html control_lcd_label_md.png</td>
    ///     <td>@image html control_lcd_label_gd.png</td>
    ///   </tr>
    /// </table>
    /// @par Examples
    /// The following code example demonstrates the use of lcd_label control.
    /// @include lcd_label.cpp
    /// @par Examples
    /// The following code example demonstrates the use of lcd_label control.
    /// @include lcd_label2.cpp
    class lcd_label : public control {
      class idigit;
      class dot_matrix_display_digit;
      class fourteen_segment_display_digit;
      class nine_segment_display_digit;
      class seven_segment_display_digit;
      class sixteen_segment_display_digit;
      
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initialise a new lcd_label class.
      lcd_label();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets background digit color.
      /// @return A xtd::drawing color that represent the background digit color.
      /// @remarks Do not confuse back_digit_color and back_color. Background digit color is the color when digit is off.
      xtd::drawing::color back_digit_color() const noexcept;
      /// @brief Sets background digit color.
      /// @param value A xtd::drawing color that represent the background digit color.
      /// @return Current lcd_label.
      /// @remarks Do not confuse back_digit_color and back_color. Background digit color is the color when digit is off.
      lcd_label& back_digit_color(const xtd::drawing::color& value);
      
      /// @brief Gets the background digit opacity.
      /// @return A double-precision value between 0.0 and 1.0 that represent the background digit opacity.
      double back_digit_opacity() const noexcept;
      /// @brief Sets the background digit opacity.
      /// @param value A double-precision value between 0.0 and 1.0 that represent the background digit opacity.
      /// @exception xtd::argument_out_of_range_exception if value less than 0.0 or greater than 1.0.
      /// @return Current lcd_label.
      lcd_label& back_digit_opacity(double value);
      
      /// @brief Gets a value indicate if background digits are shown.
      /// @return true if background digits are shown; otherwise false
      bool show_back_digit() const noexcept;
      /// @brief Sets a value indicate if background digits are shown.
      /// @param value true if background digits are shown; otherwise false
      /// @return Current lcd_label.
      lcd_label& show_back_digit(bool value);
      
      /// @brief Gets the digit spacing.
      /// @return A int32_t represent the digit spacing.
      int32_t digit_spacing() const noexcept;
      /// @brief Sets the digit spacing.
      /// @param value A int32_t represent the digit spacing.
      /// @return Current lcd_label.
      /// @exception xtd::argument_out_of_range_exception if value less than 0.
      lcd_label& digit_spacing(int32_t value);
      
      /// @brief Gets lcd style.
      /// @return One of xtd::forms::lcd_style values. The default is xtd::forms::lcd_style::seven_segment_display.
      forms::lcd_style lcd_style() const noexcept;
      /// @brief Sets lcd style.
      /// @param value One of xtd::forms::lcd_style values. The default is xtd::forms::lcd_style::seven_segment_display.
      /// @return Current lcd_label.
      lcd_label& lcd_style(forms::lcd_style value);
      
      /// @brief Gets segment style.
      /// @return One of xtd::forms::segment_style values. The default is xtd::forms::segment_style::standard.
      forms::segment_style segment_style() const noexcept;
      /// @brief Sets segment style.
      /// @param value One of xtd::forms::segment_style values. The default is xtd::forms::segment_style::standard.
      /// @return Current lcd_label.
      lcd_label& segment_style(forms::segment_style value);
      
      /// @brief Gets dot matrix style.
      /// @return One of xtd::forms::dot_matrix_style values. The default is xtd::forms::dot_matrix_style::standard.
      forms::dot_matrix_style dot_matrix_style() const noexcept;
      /// @brief Sets dot matrix style.
      /// @param value One of xtd::forms::dot_matrix_style values. The default is xtd::forms::dot_matrix_style::standard.
      /// @return Current lcd_label.
      lcd_label& dot_matrix_style(forms::dot_matrix_style value);
      
      /// @brief Gets thickness of lcd.
      /// @return A int32_t that represent the lcd thickness.
      int32_t thickness() const noexcept;
      /// @brief Sets thickness of lcd.
      /// @param value A int32_t that represent the lcd thickness.
      /// @return Current lcd_label.
      lcd_label& thickness(int32_t value);
      
      using control::text;
      /// @brief Sets the text associated with this control.
      /// @param text The text associated with this control.
      /// @return Current control.
      control& text(const xtd::ustring& value) override;
      
      /// @brief Gets valid characters.
      /// @return A std::vector<char32_t> that represent valid characters.
      /// @remarks The valid characters are different according to lcd_style.
      std::vector<char32_t> valid_characters();
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      drawing::size default_size() const noexcept override;
      /// @}

      /// @name Protected methods
      
      /// @{
      drawing::size measure_control() const noexcept override;
      void on_back_color_changed(const event_args& e) override;
      void on_fore_color_changed(const event_args& e) override;
      void on_handle_created(const event_args& e) override;
      void on_size_changed(const event_args& e) override;
      void on_resize(const event_args& e) override;
      /// @}
      
    private:
      void on_digit_click(object& sender, const event_args& e);
      void on_digit_mouse_down(object& sender, const mouse_event_args& e);
      void on_digit_mouse_move(object& sender, const mouse_event_args& e);
      void on_digit_mouse_up(object& sender, const mouse_event_args& e);
      void set_digits_params();
      
      struct data {
        bool show_back_digit = true;
        std::optional<xtd::drawing::color> back_digit_color;
        double back_digit_opacity = 0.95;
        std::optional<int32_t> digit_spacing;
        forms::lcd_style lcd_style = forms::lcd_style::seven_segment_display;
        forms::segment_style segment_style = forms::segment_style::standard;
        forms::dot_matrix_style dot_matrix_style = forms::dot_matrix_style::standard;
        std::vector<std::shared_ptr<idigit>> digits;
        std::optional<int32_t> thickness;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
