#include "../../../include/xtd/forms/lcd_label.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

char32_t lcd_label::dot_matrix_display_digit::get_character() const noexcept {
  return character_;
}

std::u32string lcd_label::dot_matrix_display_digit::get_valid_characters() const noexcept {
  return U"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz=+-*/%\\_°\"'[](){}<>| .,:;!?&$€";
}

int32_t lcd_label::dot_matrix_display_digit::get_thickness() const noexcept {
  return thickness();
}

void lcd_label::dot_matrix_display_digit::set_back_digit_color(const xtd::drawing::color& value) {
  back_dot_color(value);
}

void lcd_label::dot_matrix_display_digit::set_back_digit_opacity(double value) {
  back_dot_opacity(value);
}

void lcd_label::dot_matrix_display_digit::set_character(char32_t value) {
  static std::map<char32_t, points_collection> characters {
    {U'0', {{2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {1, 2}, {4, 2}, {5, 2}, {1, 3}, {3, 3}, {5, 3}, {1, 4}, {2, 4}, {5, 4}, {1, 5}, {5, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {U'1', {{3, 0}, {2, 1}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {3, 6}}},
    {U'2', {{2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {5, 2}, {4, 3}, {3, 4}, {2, 5}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}}},
    {U'3', {{2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {5, 2}, {2, 3}, {3, 3}, {4, 3}, {5, 4}, {1, 5}, {5, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {U'4', {{1, 0}, {5, 0}, {1, 1}, {5, 1}, {1, 2}, {5, 2}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}, {5, 4}, {5, 5}, {5, 6}}},
    {U'5', {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {1, 1}, {1, 2}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 4}, {5, 5}, {1, 6}, {2, 6}, {3, 6}, {4, 6}}},
    {U'6', {{2, 0}, {3, 0}, {4, 0}, {1, 1}, {1, 2}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {U'7', {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {5, 1}, {5, 2}, {4, 3}, {4, 4}, {3, 5}, {3, 6}}},
    {U'8', {{2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {1, 2}, {5, 2}, {2, 3}, {3, 3}, {4, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {U'9', {{2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {1, 2}, {5, 2}, {2, 3}, {3, 3}, {4, 3}, {5, 4}, {5, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {U'A', {{2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {1, 2}, {5, 2}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {1, 6}, {5, 6}}},
    {U'B', {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {1, 2}, {5, 2}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {1, 6}, {2, 6}, {3, 6}, {4, 6}}},
    {U'C', {{2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {2, 6}, {3, 6}, {5, 5}, {4, 6}}},
    {U'D', {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {1, 2}, {5, 2}, {1, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {1, 6}, {2, 6}, {3, 6}, {4, 6}}},
    {U'E', {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {1, 1}, {1, 2}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {1, 4}, {1, 5}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}}},
    {U'F', {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {1, 1}, {1, 2}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {1, 4}, {1, 5}, {1, 6}}},
    {U'G', {{2, 0}, {3, 0}, {4, 0}, {1, 1}, {1, 2}, {1, 3}, {4, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {U'H', {{1, 0}, {5, 0}, {1, 1}, {5, 1}, {1, 2}, {5, 2}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {1, 6}, {5, 6}}},
    {U'I', {{3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {3, 6}}},
    {U'J', {{5, 0}, {5, 1}, {5, 2}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {U'K', {{1, 0}, {5, 0}, {1, 1}, {4, 1}, {1, 2}, {3, 2}, {1, 3}, {2, 3}, {1, 4}, {3, 4}, {1, 5}, {4, 5}, {1, 6}, {5, 6}}},
    {U'L', {{1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}}},
    {U'M', {{1, 0}, {5, 0}, {1, 1}, {2, 1}, {4, 1}, {5, 1}, {1, 2}, {3, 2}, {5, 2}, {1, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {1, 6}, {5, 6}}},
    {U'N', {{1, 0}, {5, 0}, {1, 1}, {2, 1}, {5, 1}, {1, 2}, {3, 2}, {5, 2}, {1, 3}, {4, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {1, 6}, {5, 6}}},
    {U'O', {{2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {1, 2}, {5, 2}, {1, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {U'P', {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {1, 2}, {5, 2}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {1, 4}, {1, 5}, {1, 6}}},
    {U'Q', {{2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {1, 2}, {5, 2}, {1, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {4, 5}, {2, 6}, {3, 6}, {5, 6}}},
    {U'R', {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {1, 2}, {5, 2}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {1, 4}, {3, 4}, {1, 5}, {4, 5}, {1, 6}, {5, 6}}},
    {U'S', {{2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {1, 2}, {2, 3}, {3, 3}, {4, 3}, {5, 4}, {1, 5}, {5, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {U'T', {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {3, 6}}},
    {U'U', {{1, 0}, {5, 0}, {1, 1}, {5, 1}, {1, 2}, {5, 2}, {1, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {U'V', {{1, 0}, {5, 0}, {1, 1}, {5, 1}, {1, 2}, {5, 2}, {2, 3}, {4, 3}, {2, 4}, {4, 4}, {3, 5}, {3, 6}}},
    {U'W', {{1, 0}, {5, 0}, {1, 1}, {5, 1}, {1, 2}, {3, 2}, {5, 2}, {1, 3}, {3, 3}, {5, 3}, {1, 4}, {3, 4}, {5, 4}, {1, 5}, {2, 5}, {4, 5}, {5, 5}, {1, 6}, {5, 6}}},
    {U'X', {{1, 0}, {5, 0}, {1, 1}, {5, 1}, {2, 2}, {4, 2}, {3, 3}, {2, 4}, {4, 4}, {1, 5}, {5, 5}, {1, 6}, {5, 6}}},
    {U'Y', {{1, 0}, {5, 0}, {1, 1}, {5, 1}, {2, 2}, {4, 2}, {3, 3}, {3, 4}, {3, 5}, {3, 6}}},
    {U'Z', {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {5, 1}, {4, 2}, {3, 3}, {2, 4}, {1, 5}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}}},
    {U'a', {{2, 2}, {3, 2}, {4, 2}, {5, 3}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {1, 5}, {5, 5}, {2, 6}, {3, 6}, {4, 6}, {5, 6}}},
    {U'b', {{1, 0}, {1, 1}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {1, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {1, 6}, {2, 6}, {3, 6}, {4, 6}}},
    {U'c', {{2, 2}, {3, 2}, {4, 2}, {5, 2}, {1, 3}, {1, 4}, {1, 5}, {2, 6}, {3, 6}, {4, 6}, {5, 6}}},
    {U'd', {{5, 0}, {5, 1}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {1, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {2, 6}, {3, 6}, {4, 6}, {5, 6}}},
    {U'e', {{2, 2}, {3, 2}, {4, 2}, {1, 3}, {5, 3}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {1, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {U'f', {{3, 0}, {4, 0}, {2, 1}, {2, 2}, {3, 2}, {2, 3}, {2, 4}, {2, 5}, {2, 6}}},
    {U'g', {{2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {1, 2}, {5, 2}, {1, 3}, {5, 3}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {5, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {U'h', {{1, 0}, {1, 1}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {1, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {1, 6}, {5, 6}}},
    {U'i', {{3, 0}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {3, 6}}},
    {U'j', {{4, 0}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {2, 6}, {3, 6}}},
    {U'k', {{1, 0}, {1, 1}, {1, 2}, {5, 2}, {1, 3}, {4, 3}, {1, 4}, {2, 4}, {3, 4}, {1, 5}, {4, 5}, {1, 6}, {5, 6}}},
    {U'l', {{3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {4, 6}}},
    {U'm', {{2, 2}, {4, 2}, {1, 3}, {3, 3}, {5, 3}, {1, 4}, {3, 4}, {5, 4}, {1, 5}, {3, 5}, {5, 5}, {1, 6}, {3, 6}, {5, 6}}},
    {U'n', {{2, 2}, {3, 2}, {4, 2}, {1, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {1, 6}, {5, 6}}},
    {U'o', {{2, 2}, {3, 2}, {4, 2}, {1, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {U'p', {{1, 1}, {2, 1}, {3, 1}, {4, 1}, {1, 2}, {5, 2}, {1, 3}, {5, 3}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {1, 5}, {1, 6}}},
    {U'q', {{2, 1}, {3, 1}, {4, 1}, {5, 1}, {1, 2}, {5, 2}, {1, 3}, {5, 3}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {5, 5}, {5, 6}}},
    {U'r', {{2, 2}, {3, 2}, {4, 2}, {5, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}}},
    {U's', {{2, 2}, {3, 2}, {4, 2}, {5, 2}, {1, 3}, {2, 4}, {3, 4}, {4, 4}, {5, 5}, {1, 6}, {2, 6}, {3, 6}, {4, 6}}},
    {U't', {{3, 0}, {3, 1}, {2, 2}, {3, 2}, {4, 2}, {3, 3}, {3, 4}, {3, 5}, {4, 6}, {5, 6}}},
    {U'u', {{1, 2}, {5, 2}, {1, 3}, {5, 3}, {1, 4}, {5, 4}, {1, 5}, {5, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {U'v', {{1, 2}, {5, 2}, {1, 3}, {5, 3}, {2, 4}, {4, 4}, {2, 5}, {4, 5}, {3, 6}}},
    {U'w', {{1, 2}, {3, 2}, {5, 2}, {1, 3}, {3, 3}, {5, 3}, {1, 4}, {3, 4}, {5, 4}, {1, 5}, {3, 5}, {5, 5}, {2, 6}, {4, 6}}},
    {U'x', {{1, 2}, {5, 2}, {2, 3}, {4, 3}, {3, 4}, {2, 5}, {4, 5}, {1, 6}, {5, 6}}},
    {U'y', {{1, 1}, {5, 1}, {1, 2}, {5, 2}, {1, 3}, {5, 3}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {5, 5}, {2, 6}, {3, 6}, {4, 6}}},
    {U'z', {{1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {4, 3}, {3, 4}, {2, 5}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}}},
    {U'=', {{1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}}},
    {U'+', {{3, 1}, {3, 2}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}, {3, 4}, {3, 5}}},
    {U'-', {{1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}}},
    {U'*', {{3, 0}, {1, 1}, {3, 1}, {5, 1}, {2, 2}, {3, 2}, {4, 2}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}, {2, 4}, {3, 4}, {4, 4}, {1, 5}, {3, 5}, {5, 5}, {3, 6}}},
    {U'/', {{5, 1}, {4, 2}, {3, 3}, {2, 4}, {1, 5}}},
    {U'%', {{1, 0}, {2, 0}, {1, 1}, {2, 1}, {5, 1}, {4, 2}, {3, 3}, {2, 4}, {1, 5}, {4, 5}, {5, 5}, {4, 6}, {5, 6}}},
    {U'\\', {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}}},
    {U'_', {{1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}}},
    {U'°', {{2, 0}, {3, 0}, {1, 1}, {4, 1}, {1, 2}, {4, 2}, {2, 3}, {3, 3}}},
    {U'"', {{2, 0}, {5, 0}, {2, 1}, {5, 1}, {1, 2}, {4, 2}}},
    {U'\'', {{3, 0}, {3, 1}, {2, 2}}},
    {U'[', {{3, 0}, {4, 0}, {5, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {3, 6}, {4, 6}, {5, 6}}},
    {U']', {{1, 0}, {2, 0}, {3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {1, 6}, {2, 6}, {3, 6}}},
    {U'(', {{4, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {4, 6}}},
    {U')', {{2, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {2, 6}}},
    {U'{', {{4, 0}, {5, 0}, {3, 1}, {3, 2}, {2, 3}, {3, 4}, {3, 5}, {4, 6}, {5, 6}}},
    {U'}', {{1, 0}, {2, 0}, {3, 1}, {3, 2}, {4, 3}, {3, 4}, {3, 5}, {1, 6}, {2, 6}}},
    {U'<', {{4, 1}, {3, 2}, {2, 3}, {3, 4}, {4, 5}}},
    {U'>', {{2, 1}, {3, 2}, {4, 3}, {3, 4}, {2, 5}}},
    {U'|', {{3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {3, 6}}},
    {U' ', {}},
    {U'.', {{3, 6}}},
    {U',', {{3, 5}, {2, 6}}},
    {U':', {{3, 1}, {3, 5}}},
    {U';', {{3, 2}, {3, 5}, {2, 6}}},
    {U'!', {{3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 6}}},
    {U'?', {{2, 0}, {3, 0}, {4, 0}, {1, 1}, {5, 1}, {5, 2}, {4, 3}, {3, 4}, {3, 6}}},
    {U'&', {{2, 0}, {3, 0}, {1, 1}, {4, 1}, {1, 2}, {4, 2}, {2, 3}, {3, 3}, {5, 3}, {1, 4}, {4, 4}, {1, 5}, {4, 5}, {2, 6}, {3, 6}, {5, 6}}},
    {U'$', {{3, 0}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {1, 2}, {3, 2}, {2, 3}, {3, 3}, {4, 3}, {3, 4}, {5, 4}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {3, 6}}},
    {U'€', {{3, 0}, {4, 0}, {5, 0}, {2, 1}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {2, 3}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {2, 5}, {3, 6}, {4, 6}, {5, 6}}},
  };
  if (character_ != value) {
    auto it = characters.find(value);
    if (it == characters.end()) throw argument_exception(ustring::format("Only characters : \"{}\" are valid"_t, get_valid_characters()), current_stack_frame_);
    character_ = value;
    set_dots(it->second);
  }
}

void lcd_label::dot_matrix_display_digit::set_segment_style(forms::segment_style value) {
}

void lcd_label::dot_matrix_display_digit::set_dot_matrix_style(forms::dot_matrix_style value) {
  dot_matrix_style(value);
}

void lcd_label::dot_matrix_display_digit::set_show_back_digit(bool value) {
  show_back_dot(value);
}

void lcd_label::dot_matrix_display_digit::set_thickness(int32_t value) {
  thickness(value);
}

char32_t lcd_label::fourteen_segment_display_digit::get_character() const noexcept {
  return character_;
}

std::u32string lcd_label::fourteen_segment_display_digit::get_valid_characters() const noexcept {
  return U"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz=+-*/\\_°\"'[]()| .,:";
}

int32_t lcd_label::fourteen_segment_display_digit::get_thickness() const noexcept {
  return thickness();
}

void lcd_label::fourteen_segment_display_digit::set_back_digit_color(const xtd::drawing::color& value) {
  back_segment_color(value);
}

void lcd_label::fourteen_segment_display_digit::set_back_digit_opacity(double value) {
  back_segment_opacity(value);
}

void lcd_label::fourteen_segment_display_digit::set_character(char32_t value) {
  static std::map<char32_t, forms::segments> characters {
    {U'0', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f},
    {U'1', forms::segments::b | forms::segments::c | forms::segments::j},
    {U'2', forms::segments::a | forms::segments::b | forms::segments::d | forms::segments::e | forms::segments::g1 | forms::segments::g2},
    {U'3', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::g2},
    {U'4', forms::segments::b | forms::segments::c | forms::segments::f | forms::segments::g1 | forms::segments::g2},
    {U'5', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g1 | forms::segments::g2},
    {U'6', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2},
    {U'7', forms::segments::a | forms::segments::l | forms::segments::j},
    {U'8', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g1 | segments::g2},
    {U'9', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::f | forms::segments::g1 | forms::segments::g2},
    {U'A', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2},
    {U'B', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::g2 | forms::segments::i | forms::segments::l},
    {U'C', forms::segments::a | forms::segments::d | forms::segments::e | forms::segments::f},
    {U'D', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::i | forms::segments::l},
    {U'E', forms::segments::a | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2},
    {U'F', forms::segments::a | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2},
    {U'G', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g2},
    {U'H', forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2},
    {U'I', forms::segments::a | forms::segments::d | forms::segments::i | forms::segments::l},
    {U'J', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e},
    {U'K', forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::j | forms::segments::m},
    {U'L', forms::segments::d | forms::segments::e | forms::segments::f},
    {U'M', forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::h | forms::segments::j},
    {U'N', forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::h | forms::segments::m},
    {U'O', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f},
    {U'P', forms::segments::a | forms::segments::b | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2},
    {U'Q', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::m},
    {U'R', forms::segments::a | forms::segments::b | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2 | forms::segments::m},
    {U'S', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::g2 | forms::segments::h},
    {U'T', forms::segments::a | forms::segments::i | forms::segments::l},
    {U'U', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f},
    {U'V', forms::segments::e | forms::segments::f | forms::segments::j | forms::segments::k},
    {U'W', forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::k | forms::segments::m},
    {U'X', forms::segments::h | forms::segments::j | forms::segments::k | forms::segments::m},
    {U'Y', forms::segments::h | forms::segments::j | forms::segments::l},
    {U'Z', forms::segments::a | forms::segments::d | forms::segments::j | forms::segments::k},
    {U'a', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::g1 | forms::segments::g2},
    {U'b', forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::m},
    {U'c', forms::segments::d | forms::segments::e | forms::segments::g1 | forms::segments::g2},
    {U'd', forms::segments::b | forms::segments::c | forms::segments::d | segments::g2 | segments::k},
    {U'e', forms::segments::a | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g1},
    {U'f', forms::segments::a | forms::segments::e | forms::segments::f | forms::segments::g1},
    {U'g', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::h | forms::segments::g2},
    {U'h', forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2},
    {U'i', forms::segments::l},
    {U'j', forms::segments::b | forms::segments::c | forms::segments::d},
    {U'k', forms::segments::i | forms::segments::l | forms::segments::j | forms::segments::m},
    {U'l', forms::segments::i | forms::segments::l},
    {U'm', forms::segments::c | forms::segments::e | forms::segments::g1 | forms::segments::g2 | forms::segments::l},
    {U'n', forms::segments::e | forms::segments::g1 | forms::segments::m},
    {U'o', forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::g1 | forms::segments::g2},
    {U'p', forms::segments::a | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::j},
    {U'q', forms::segments::a | forms::segments::b | forms::segments::f | forms::segments::g1 | forms::segments::g2 | forms::segments::m},
    {U'r', forms::segments::e | forms::segments::g},
    {U's', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::g2 | forms::segments::h},
    {U't', forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g1},
    {U'u', forms::segments::c | forms::segments::d | forms::segments::e},
    {U'v', forms::segments::e | forms::segments::k},
    {U'w', forms::segments::c | forms::segments::e | forms::segments::k | forms::segments::m},
    {U'x', forms::segments::h | forms::segments::j | forms::segments::k | forms::segments::m},
    {U'y', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::g2 | forms::segments::i},
    {U'z', forms::segments::a | forms::segments::d | forms::segments::j | forms::segments::k},
    {U'=', forms::segments::d | forms::segments::g1 | forms::segments::g2},
    {U'+', forms::segments::g1 | forms::segments::g2 | forms::segments::i | forms::segments::l},
    {U'-', forms::segments::g1 | forms::segments::g2},
    {U'*', forms::segments::g1 | forms::segments::g2 | forms::segments::h | forms::segments::i | forms::segments::j | forms::segments::k | forms::segments::l | forms::segments::m},
    {U'/', forms::segments::j | forms::segments::k},
    {U'\\', forms::segments::h | forms::segments::m},
    {U'_', forms::segments::d},
    {U'°', forms::segments::a | forms::segments::b | forms::segments::f | forms::segments::g1 | forms::segments::g2},
    {U'"', forms::segments::b | forms::segments::f},
    {U'\'', forms::segments::f},
    {U'[', forms::segments::a | forms::segments::d | forms::segments::e | forms::segments::f},
    {U']', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d},
    {U'(', forms::segments::j | forms::segments::m},
    {U')', forms::segments::h | forms::segments::k},
    {U'|', forms::segments::i | forms::segments::l},
    {U' ', forms::segments::none},
    {U'.', forms::segments::dp},
    {U',', forms::segments::k},
    {U':', forms::segments::pc}
  };
  if (character_ != value) {
    auto it = characters.find(value);
    if (it == characters.end()) throw argument_exception(ustring::format("Only characters : \"{}\" are valid"_t, get_valid_characters()), current_stack_frame_);
    character_ = value;
    fourteen_segment_display_digit::value(it->second);
  }
}

void lcd_label::fourteen_segment_display_digit::set_segment_style(forms::segment_style value) {
  segment_style(value);
}

void lcd_label::fourteen_segment_display_digit::set_dot_matrix_style(forms::dot_matrix_style value) {
}

void lcd_label::fourteen_segment_display_digit::set_show_back_digit(bool value) {
  show_back_segment(value);
}

void lcd_label::fourteen_segment_display_digit::set_thickness(int32_t value) {
  thickness(value);
}

char32_t lcd_label::nine_segment_display_digit::get_character() const noexcept {
  return character_;
}

std::u32string lcd_label::nine_segment_display_digit::get_valid_characters() const noexcept {
  return U"0123456789ABCDEFGHIJLNOPQRSTUYabcdefghijlnopqrstuy=-_°\"'[]| .,:";
}

int32_t lcd_label::nine_segment_display_digit::get_thickness() const noexcept {
  return thickness();
}

void lcd_label::nine_segment_display_digit::set_back_digit_color(const xtd::drawing::color& value) {
  back_segment_color(value);
}

void lcd_label::nine_segment_display_digit::set_back_digit_opacity(double value) {
  back_segment_opacity(value);
}

void lcd_label::nine_segment_display_digit::set_character(char32_t value) {
  static std::map<char32_t, forms::segments> characters {
    {U'0', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f},
    {U'1', forms::segments::b | forms::segments::c},
    {U'2', forms::segments::a | forms::segments::b | forms::segments::d | forms::segments::i},
    {U'3', forms::segments::a | forms::segments::g | forms::segments::h | forms::segments::i},
    {U'4', forms::segments::b | forms::segments::c | forms::segments::f | forms::segments::g},
    {U'5', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g},
    {U'6', forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::g | forms::segments::h},
    {U'7', forms::segments::a | forms::segments::e | forms::segments::h},
    {U'8', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g},
    {U'9', forms::segments::a | forms::segments::b | forms::segments::f | forms::segments::g | forms::segments::i},
    {U'A', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::g},
    {U'a', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::g},
    {U'B', forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g},
    {U'b', forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g},
    {U'C', forms::segments::a | forms::segments::d | forms::segments::e | forms::segments::f},
    {U'c', forms::segments::d | forms::segments::e | forms::segments::g},
    {U'D', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::g},
    {U'd', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::g},
    {U'E', forms::segments::a | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g},
    {U'e', forms::segments::a | forms::segments::b | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g},
    {U'F', forms::segments::a | forms::segments::e | forms::segments::f | forms::segments::g},
    {U'f', forms::segments::a | forms::segments::e | forms::segments::f | forms::segments::g},
    {U'G', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f},
    {U'g', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g},
    {U'H', forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::g},
    {U'h', forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::g},
    {U'I', forms::segments::b | forms::segments::c},
    {U'i', forms::segments::c},
    {U'J', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e},
    {U'j', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e},
    {U'L', forms::segments::d | forms::segments::e | forms::segments::f},
    {U'l', forms::segments::d | forms::segments::e},
    {U'N', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f},
    {U'n', forms::segments::c | forms::segments::e | forms::segments::g},
    {U'O', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f},
    {U'o', forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::g},
    {U'P', forms::segments::a | forms::segments::b | forms::segments::e | forms::segments::f | forms::segments::g},
    {U'p', forms::segments::a | forms::segments::b | forms::segments::e | forms::segments::f | forms::segments::g},
    {U'Q', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::f | forms::segments::g},
    {U'q', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::f | forms::segments::g},
    {U'R', forms::segments::a | forms::segments::e | forms::segments::f},
    {U'r', forms::segments::e | forms::segments::g},
    {U'S', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g},
    {U's', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g},
    {U'T', forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g},
    {U't', forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g},
    {U'U', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f},
    {U'u', forms::segments::c | forms::segments::d | forms::segments::e},
    {U'Y', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g},
    {U'y', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g},
    {U'=', forms::segments::d | forms::segments::g}, {'-', forms::segments::g},
    {U'_', forms::segments::d},
    {U'°', forms::segments::a | forms::segments::b | forms::segments::f | forms::segments::g},
    {U'"', forms::segments::b | forms::segments::f},
    {U'\'', forms::segments::f},
    {U'[', forms::segments::a | forms::segments::d | forms::segments::e | forms::segments::f},
    {U']', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d},
    {U'|', forms::segments::b | forms::segments::c}, {' ', forms::segments::none},
    {U'.', forms::segments::dp},
    {U',', forms::segments::dp},
    {U':', forms::segments::pc}
  };
  if (character_ != value) {
    auto it = characters.find(value);
    if (it == characters.end()) throw argument_exception(ustring::format("Only characters : \"{}\" are valid"_t, get_valid_characters()), current_stack_frame_);
    character_ = value;
    nine_segment_display_digit::value(it->second);
  }
}

void lcd_label::nine_segment_display_digit::set_segment_style(forms::segment_style value) {
  segment_style(value);
}

void lcd_label::nine_segment_display_digit::set_dot_matrix_style(forms::dot_matrix_style value) {
}

void lcd_label::nine_segment_display_digit::set_show_back_digit(bool value) {
  show_back_segment(value);
}

void lcd_label::nine_segment_display_digit::set_thickness(int32_t value) {
  thickness(value);
}

char32_t lcd_label::seven_segment_display_digit::get_character() const noexcept {
  return character_;
}

std::u32string lcd_label::seven_segment_display_digit::get_valid_characters() const noexcept {
  return U"0123456789ABCDEFGHIJLNOPQRSTUYabcdefghijlnopqrstuy=-_°\"'[]| .,:";
}

int32_t lcd_label::seven_segment_display_digit::get_thickness() const noexcept {
  return thickness();
}

void lcd_label::seven_segment_display_digit::set_back_digit_color(const xtd::drawing::color& value) {
  back_segment_color(value);
}

void lcd_label::seven_segment_display_digit::set_back_digit_opacity(double value) {
  back_segment_opacity(value);
}

void lcd_label::seven_segment_display_digit::set_character(char32_t value) {
  static std::map<char32_t, forms::segments> characters {
    {U'0', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f},
    {U'1', forms::segments::b | forms::segments::c},
    {U'2', forms::segments::a | forms::segments::b | forms::segments::d | forms::segments::e | forms::segments::g},
    {U'3', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::g},
    {U'4', forms::segments::b | forms::segments::c | forms::segments::f | forms::segments::g},
    {U'5', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g},
    {U'6', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g},
    {U'7', forms::segments::a | forms::segments::b | forms::segments::c},
    {U'8', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g},
    {U'9', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g},
    {U'A', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::g},
    {U'a', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::g},
    {U'B', forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g},
    {U'b', forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g},
    {U'C', forms::segments::a | forms::segments::d | forms::segments::e | forms::segments::f},
    {U'c', forms::segments::d | forms::segments::e | forms::segments::g},
    {U'D', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::g},
    {U'd', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::g},
    {U'E', forms::segments::a | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g},
    {U'e', forms::segments::a | forms::segments::b | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g},
    {U'F', forms::segments::a | forms::segments::e | forms::segments::f | forms::segments::g},
    {U'f', forms::segments::a | forms::segments::e | forms::segments::f | forms::segments::g},
    {U'G', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f},
    {U'g', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g},
    {U'H', forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::g},
    {U'h', forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::g},
    {U'I', forms::segments::b | forms::segments::c},
    {U'i', forms::segments::c},
    {U'J', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e},
    {U'j', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e},
    {U'L', forms::segments::d | forms::segments::e | forms::segments::f},
    {U'l', forms::segments::d | forms::segments::e},
    {U'N', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f},
    {U'n', forms::segments::c | forms::segments::e | forms::segments::g},
    {U'O', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f},
    {U'o', forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::g},
    {U'P', forms::segments::a | forms::segments::b | forms::segments::e | forms::segments::f | forms::segments::g},
    {U'p', forms::segments::a | forms::segments::b | forms::segments::e | forms::segments::f | forms::segments::g},
    {U'Q', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::f | forms::segments::g},
    {U'q', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::f | forms::segments::g},
    {U'R', forms::segments::a | forms::segments::e | forms::segments::f},
    {U'r', forms::segments::e | forms::segments::g},
    {U'S', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g},
    {U's', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g},
    {U'T', forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g},
    {U't', forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g},
    {U'U', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f},
    {U'u', forms::segments::c | forms::segments::d | forms::segments::e},
    {U'Y', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g},
    {U'y', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g},
    {U'=', forms::segments::d | forms::segments::g},
    {U'-', forms::segments::g},
    {U'_', forms::segments::d},
    {U'°', forms::segments::a | forms::segments::b | forms::segments::f | forms::segments::g},
    {U'"', forms::segments::b | forms::segments::f},
    {U'\'', forms::segments::f},
    {U'[', forms::segments::a | forms::segments::d | forms::segments::e | forms::segments::f},
    {U']', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d},
    {U'|', forms::segments::b | forms::segments::c}, {' ', forms::segments::none},
    {U'.', forms::segments::dp},
    {U',', forms::segments::dp},
    {U':', forms::segments::pc}};
  if (character_ != value) {
    auto it = characters.find(value);
    if (it == characters.end()) throw argument_exception(ustring::format("Only characters : \"{}\" are valid"_t, get_valid_characters()), current_stack_frame_);
    character_ = value;
    seven_segment_display::value(it->second);
  }
}

void lcd_label::seven_segment_display_digit::set_segment_style(forms::segment_style value) {
  segment_style(value);
}

void lcd_label::seven_segment_display_digit::set_dot_matrix_style(forms::dot_matrix_style value) {
}

void lcd_label::seven_segment_display_digit::set_show_back_digit(bool value) {
  show_back_segment(value);
}

void lcd_label::seven_segment_display_digit::set_thickness(int32_t value) {
  thickness(value);
}

char32_t lcd_label::sixteen_segment_display_digit::get_character() const noexcept {
  return character_;
}

std::u32string lcd_label::sixteen_segment_display_digit::get_valid_characters() const noexcept {
  return U"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz=+-*/\\_°\"'[]()| .,:";
}

int32_t lcd_label::sixteen_segment_display_digit::get_thickness() const noexcept {
  return sixteen_segment_display::thickness();
}

void lcd_label::sixteen_segment_display_digit::set_back_digit_color(const xtd::drawing::color& value) {sixteen_segment_display::back_segment_color(value);}
void lcd_label::sixteen_segment_display_digit::set_back_digit_opacity(double value) {sixteen_segment_display::back_segment_opacity(value);}
void lcd_label::sixteen_segment_display_digit::set_character(char32_t value) {
  static std::map<char32_t, forms::segments> characters {
    {U'0', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::f},
    {U'1', forms::segments::b | forms::segments::c | forms::segments::j},
    {U'2', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::g1 | forms::segments::g2},
    {U'3', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::g2},
    {U'4', forms::segments::b | forms::segments::c | forms::segments::f | forms::segments::g1 | forms::segments::g2},
    {U'5', forms::segments::a1 | forms::segments::a2 | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::f | forms::segments::g1 | forms::segments::g2},
    {U'6', forms::segments::a1 | forms::segments::a2 | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2},
    {U'7', forms::segments::a1 | forms::segments::a2 | forms::segments::l | forms::segments::j},
    {U'8', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::f | forms::segments::g1 | segments::g2},
    {U'9', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::c | forms::segments::f | forms::segments::g1 | forms::segments::g2},
    {U'A', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2},
    {U'B', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::g2 | forms::segments::i | forms::segments::l},
    {U'C', forms::segments::a1 | forms::segments::a2 | forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::f},
    {U'D', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::i | forms::segments::l},
    {U'E', forms::segments::a1 | forms::segments::a2 | forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2},
    {U'F', forms::segments::a1 | forms::segments::a2 | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2},
    {U'G', forms::segments::a1 | forms::segments::a2 | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::f | forms::segments::g2},
    {U'H', forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2},
    {U'I', forms::segments::a1 | forms::segments::a2 | forms::segments::d1 | forms::segments::d2 | forms::segments::i | forms::segments::l},
    {U'J', forms::segments::b | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::e},
    {U'K', forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::j | forms::segments::m},
    {U'L', forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::f},
    {U'M', forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::h | forms::segments::j},
    {U'N', forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::h | forms::segments::m},
    {U'O', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::f},
    {U'P', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2},
    {U'Q', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::f | forms::segments::m},
    {U'q', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::f | forms::segments::g1 | forms::segments::g2 | forms::segments::m},
    {U'R', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2 | forms::segments::m},
    {U'S', forms::segments::a1 | forms::segments::a2 | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::g2 | forms::segments::h},
    {U'T', forms::segments::a1 | forms::segments::a2 | forms::segments::i | forms::segments::l},
    {U'U', forms::segments::b | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::f},
    {U'V', forms::segments::e | forms::segments::f | forms::segments::j | forms::segments::k},
    {U'W', forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::k | forms::segments::m},
    {U'X', forms::segments::h | forms::segments::j | forms::segments::k | forms::segments::m},
    {U'Y', forms::segments::h | forms::segments::j | forms::segments::l},
    {U'Z', forms::segments::a1 | forms::segments::a2 | forms::segments::d1 | forms::segments::d2 | forms::segments::j | forms::segments::k},
    {U'a', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::g1 | forms::segments::g2},
    {U'b', forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::m},
    {U'c', forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::g1 | forms::segments::g2},
    {U'd', forms::segments::b | forms::segments::c | forms::segments::d1 | forms::segments::d2 | segments::g2 | segments::k},
    {U'e', forms::segments::a1 | forms::segments::a2 | forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::f | forms::segments::g1},
    {U'f', forms::segments::a1 | forms::segments::a2 | forms::segments::e | forms::segments::f | forms::segments::g1},
    {U'g', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::h | forms::segments::g2},
    {U'h', forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2},
    {U'i', forms::segments::l},
    {U'j', forms::segments::b | forms::segments::c | forms::segments::d1 | forms::segments::d2},
    {U'k', forms::segments::i | forms::segments::l | forms::segments::j | forms::segments::m},
    {U'l', forms::segments::i | forms::segments::l},
    {U'm', forms::segments::c | forms::segments::e | forms::segments::g1 | forms::segments::g2 | forms::segments::l},
    {U'n', forms::segments::e | forms::segments::g1 | forms::segments::m},
    {U'o', forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::g1 | forms::segments::g2},
    {U'p', forms::segments::a1 | forms::segments::a2 | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::j},
    {U'r', forms::segments::e | forms::segments::g},
    {U's', forms::segments::a1 | forms::segments::a2 | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::g2 | forms::segments::h},
    {U't', forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::f | forms::segments::g1},
    {U'u', forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::e},
    {U'v', forms::segments::e | forms::segments::k},
    {U'w', forms::segments::c | forms::segments::e | forms::segments::k | forms::segments::m},
    {U'x', forms::segments::h | forms::segments::j | forms::segments::k | forms::segments::m},
    {U'y', forms::segments::b | forms::segments::c | forms::segments::d2 | forms::segments::g2 | forms::segments::i},
    {U'z', forms::segments::g1 | forms::segments::d1 | forms::segments::k},
    {U'=', forms::segments::d1 | forms::segments::d2 | forms::segments::g1 | forms::segments::g2},
    {U'+', forms::segments::g1 | forms::segments::g2 | forms::segments::i | forms::segments::l},
    {U'-', forms::segments::g1 | forms::segments::g2},
    {U'*', forms::segments::g1 | forms::segments::g2 | forms::segments::h | forms::segments::i | forms::segments::j | forms::segments::k | forms::segments::l | forms::segments::m},
    {U'/', forms::segments::j | forms::segments::k},
    {U'\\', forms::segments::h | forms::segments::m},
    {U'_', forms::segments::d1 | forms::segments::d2},
    {U'°', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::f | forms::segments::g1 | forms::segments::g2},
    {U'"', forms::segments::b | forms::segments::f},
    {U'\'', forms::segments::f},
    {U'[', forms::segments::a1 | forms::segments::a2 | forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::f},
    {U']', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::c | forms::segments::d1 | forms::segments::d2},
    {U'(', forms::segments::j | forms::segments::m},
    {U')', forms::segments::h | forms::segments::k},
    {U'|', forms::segments::i | forms::segments::l},
    {U' ', forms::segments::none},
    {U'.', forms::segments::dp},
    {U',', forms::segments::k},
    {U':', forms::segments::pc}
  };
  if (character_ != value) {
    auto it = characters.find(value);
    if (it == characters.end()) throw argument_exception(ustring::format("Only characters : \"{}\" are valid"_t, get_valid_characters()), current_stack_frame_);
    character_ = value;
    sixteen_segment_display::value(it->second);
  }
}

void lcd_label::sixteen_segment_display_digit::set_segment_style(forms::segment_style value) {
  segment_style(value);
}

void lcd_label::sixteen_segment_display_digit::set_dot_matrix_style(forms::dot_matrix_style value) {
}

void lcd_label::sixteen_segment_display_digit::set_show_back_digit(bool value) {
  show_back_segment(value);
}

void lcd_label::sixteen_segment_display_digit::set_thickness(int32_t value) {
  thickness(value);
}

lcd_label::lcd_label() {
  set_auto_size_mode(forms::auto_size_mode::grow_and_shrink);
  set_can_focus(false);
  set_style(control_styles::user_paint | control_styles::supports_transparent_back_color | control_styles::optimized_double_buffer, control::control_appearance() == forms::control_appearance::standard);
  set_style(control_styles::fixed_height | control_styles::selectable, false);
  set_style(control_styles::resize_redraw, true);
}

xtd::drawing::color lcd_label::back_digit_color() const noexcept {
  return back_digit_color_.value_or(fore_color());
}

lcd_label& lcd_label::back_digit_color(const xtd::drawing::color& value) {
  if (!back_digit_color_.has_value() || back_digit_color_.value() != value) {
    back_digit_color_ = value;
    set_digits_params();
  }
  return *this;
}

double lcd_label::back_digit_opacity() const noexcept {
  return back_digit_opacity_;
}

lcd_label& lcd_label::back_digit_opacity(double value) {
  if (value < 0.0 || value > 1.0) throw argument_out_of_range_exception("value must be between 0.0 and 1.0."_t, current_stack_frame_);
  if (back_digit_opacity_ != value) {
    back_digit_opacity_ = value;
    set_digits_params();
  }
  return *this;
}

bool lcd_label::show_back_digit() const noexcept {
  return show_back_digit_;
}

lcd_label& lcd_label::show_back_digit(bool value) {
  if (show_back_digit_ != value) {
    show_back_digit_ = value;
    set_digits_params();
  }
  return *this;
}

int32_t lcd_label::digit_spacing() const noexcept {
  return digit_spacing_.value_or(lcd_style_ == lcd_style::dot_matrix_display ? 0 : thickness());
}

lcd_label& lcd_label::digit_spacing(int32_t value) {
  if (value < 0) throw argument_out_of_range_exception("value must be positive"_t, current_stack_frame_);
  if (digit_spacing_ != value) {
    digit_spacing_ = value;
    set_digits_params();
  }
  return *this;
}

forms::lcd_style lcd_label::lcd_style() const noexcept {
  return lcd_style_;
}

lcd_label& lcd_label::lcd_style(forms::lcd_style value) {
  if (lcd_style_ != value) {
    lcd_style_ = value;
    xtd::ustring current_text = text();
    text("");
    text(current_text);
  }
  return *this;
}

forms::segment_style lcd_label::segment_style() const noexcept {
  return segment_style_;
}

lcd_label& lcd_label::segment_style(forms::segment_style value) {
  if (segment_style_ != value) {
    segment_style_ = value;
    for (auto& digit : digits_)
      digit->set_segment_style(value);
  }
  return *this;
}

forms::dot_matrix_style lcd_label::dot_matrix_style() const noexcept {
  return dot_matrix_style_;
}

lcd_label& lcd_label::dot_matrix_style(forms::dot_matrix_style value) {
  if (dot_matrix_style_ != value) {
    dot_matrix_style_ = value;
    for (auto& digit : digits_)
      digit->set_dot_matrix_style(value);
  }
  return *this;
}

int32_t lcd_label::thickness() const noexcept {
  return thickness_.value_or(digits_.size() ? digits_[0]->get_thickness() : 1);
}

lcd_label& lcd_label::thickness(int32_t value) {
  if (thickness_ != value) {
    thickness_ = value;
    set_digits_params();
  }
  return *this;
}

control& lcd_label::text(const xtd::ustring& value) {
  if (text() != value) {
    if (is_handle_created()) suspend_layout();
    std::wstring str = convert_string::to_wstring(value);
    if (str.size() < digits_.size()) {
      for (size_t index = digits_.size(); index < str.size(); index++) {
        dynamic_cast<control*>(digits_[index].get())->mouse_down -= {*this, &lcd_label::on_digit_mouse_down};
        dynamic_cast<control*>(digits_[index].get())->mouse_move -= {*this, &lcd_label::on_digit_mouse_move};
        dynamic_cast<control*>(digits_[index].get())->mouse_up -= {*this, &lcd_label::on_digit_mouse_up};
      }
      digits_.erase(digits_.begin() + str.size(), digits_.end());
    }
    if (str.size() > digits_.size())
      for (size_t index = digits_.size(); index < str.size(); index++) {
        switch (lcd_style_) {
          case lcd_style::seven_segment_display: digits_.push_back(std::make_shared<seven_segment_display_digit>()); break;
          case lcd_style::nine_segment_display: digits_.push_back(std::make_shared<nine_segment_display_digit>()); break;
          case lcd_style::fourteen_segment_display: digits_.push_back(std::make_shared<fourteen_segment_display_digit>()); break;
          case lcd_style::sixteen_segment_display: digits_.push_back(std::make_shared<sixteen_segment_display_digit>()); break;
          case lcd_style::dot_matrix_display: digits_.push_back(std::make_shared<dot_matrix_display_digit>()); break;
          default: throw argument_exception("lcd_style invalid", current_stack_frame_);
        }
        dynamic_cast<control*>(digits_[digits_.size() - 1].get())->parent(*this);
        dynamic_cast<control*>(digits_[digits_.size() - 1].get())->click += {*this, &lcd_label::on_digit_click};
        dynamic_cast<control*>(digits_[digits_.size() - 1].get())->mouse_down += {*this, &lcd_label::on_digit_mouse_down};
        dynamic_cast<control*>(digits_[digits_.size() - 1].get())->mouse_move += {*this, &lcd_label::on_digit_mouse_move};
        dynamic_cast<control*>(digits_[digits_.size() - 1].get())->mouse_up += {*this, &lcd_label::on_digit_mouse_up};
      }
    for (size_t index = 0; index < str.size(); index++)
      digits_[index]->set_character(str[index]);
    set_digits_params();
    set_text(value);
    if (is_handle_created()) resume_layout();
  }
  return *this;
}

std::vector<char32_t> lcd_label::valid_characters() {
  std::shared_ptr<idigit> digit;
  switch (lcd_style_) {
    case lcd_style::seven_segment_display: digit = std::make_shared<seven_segment_display_digit>(); break;
    case lcd_style::nine_segment_display: digit = std::make_shared<nine_segment_display_digit>(); break;
    case lcd_style::fourteen_segment_display: digit = std::make_shared<fourteen_segment_display_digit>(); break;
    case lcd_style::sixteen_segment_display: digit = std::make_shared<sixteen_segment_display_digit>(); break;
    case lcd_style::dot_matrix_display: digit = std::make_shared<dot_matrix_display_digit>(); break;
    default: throw argument_exception("lcd_style invalid", current_stack_frame_);
  }
  auto vc = digit->get_valid_characters();
  return {vc.begin(), vc.end()};
}

drawing::size lcd_label::default_size() const noexcept {
  return {100, 25};
}

void lcd_label::on_back_color_changed(const event_args& e) {
  control::on_back_color_changed(e);
  invalidate();
}

void lcd_label::on_fore_color_changed(const event_args& e) {
  control::on_fore_color_changed(e);
  invalidate();
}

void lcd_label::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  set_digits_params();
}

void lcd_label::on_size_changed(const event_args& e) {
  set_digits_params();
  control::on_size_changed(e);
}

void lcd_label::on_resize(const event_args& e) {
  set_digits_params();
  control::on_resize(e);
}

drawing::size lcd_label::measure_control() const noexcept {
  if (digits_.size() == 0) return {0, size().height()};
  return drawing::size((dynamic_cast<control*>(digits_[0].get())->width() - 2 + digit_spacing()) * static_cast<int32_t>(digits_.size()) - digit_spacing() + 2, size().height());
}

void lcd_label::on_digit_click(object& sender, const event_args& e) {
  on_click(e);
}

void lcd_label::on_digit_mouse_down(object& sender, const mouse_event_args& e) {
  on_mouse_down(mouse_event_args(e.button(), e.clicks(), e.location() + drawing::size(as<control>(sender).location()), e.delta()));
}

void lcd_label::on_digit_mouse_move(object& sender, const mouse_event_args& e) {
  on_mouse_move(mouse_event_args(e.button(), e.clicks(), e.location() + drawing::size(as<control>(sender).location()), e.delta()));
}

void lcd_label::on_digit_mouse_up(object& sender, const mouse_event_args& e) {
  on_mouse_up(mouse_event_args(e.button(), e.clicks(), e.location() + drawing::size(as<control>(sender).location()), e.delta()));
}

void lcd_label::set_digits_params() {
  int32_t offset_left = 0;
  for (auto& digit : digits_) {
    dynamic_cast<control*>(digit.get())->height(size().height());
    dynamic_cast<control*>(digit.get())->left(offset_left);
    digit->set_back_digit_color(back_digit_color());
    digit->set_back_digit_opacity(back_digit_opacity_);
    digit->set_show_back_digit(show_back_digit_);
    digit->set_segment_style(segment_style_);
    digit->set_dot_matrix_style(dot_matrix_style_);
    if (thickness_.has_value()) digit->set_thickness(thickness());
    offset_left += dynamic_cast<control*>(digit.get())->width() - 2 + digit_spacing();
  }
}
