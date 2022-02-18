/// @file
/// @brief Contains xtd::drawing::imaging::encoder_parameter_value_type  class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <ostream>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd.drawing.imaging namespace provides advanced GDI+ imaging functionality. Basic graphics functionality is provided by the xtd.drawing namespace.
    /// @remarks The metafile class provides methods for recording and saving metafiles. The encoder class enables users to extend GDI+ to support any image format. The property_item class provides methods for storing and retrieving metadata in image files.
    namespace imaging {
      /// @brief Specifies the data type of the xtd::drawing::imaging::encoder_parameter used with the xtd::drawing::image::save or xtd::drawing::image::save_add method of an image.
      /// @par Namespace
      /// xtd::drawing::imaging
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      enum class encoder_parameter_value_type {
        /// @brief An 8-bit unsigned integer.
        value_type_byte = 1,
        /// @brief An 8-bit ASCII value. This field specifies that the array of values is a null-terminated ASCII character string.
        value_type_ascii = 2,
        /// @brief A 16-bit, unsigned integer.
        value_type_short = 3,
        /// @brief A 32-bit unsigned integer.
        value_type_long = 4,
        /// @brief A pair of 32-bit unsigned integers. Each pair represents a fraction, the first integer being the numerator and the second integer being the denominator.
        value_type_rational = 5,
        /// @brief Two long values that specify a range of integer values. The first value specifies the lower end, and the second value specifies the higher end. All values are inclusive at both ends.
        value_type_long_range = 6,
        /// @brief A byte that has no data type defined. The variable can take any value depending on field definition.
        value_type_undefined = 7,
        /// @brief A set of four 32-bit unsigned integers. The first two integers represent one fraction, and the second two integers represent a second fraction.<br>The two fractions represent a range of rational numbers. The first fraction is the smallest rational number in the range, and the second fraction is the largest rational number in the range. The values are inclusive at both ends.
        value_type_rational_range = 8,
        /// @brief A pointer to a block of custom metadata.
        value_type_rational_pointer = 9,
      };
      
      /// @cond
      inline std::ostream& operator<<(std::ostream& os, encoder_parameter_value_type value) {return os << xtd::to_string(value, {{encoder_parameter_value_type::value_type_byte, "value_type_byte"}, {encoder_parameter_value_type::value_type_ascii, "value_type_ascii"}, {encoder_parameter_value_type::value_type_short, "value_type_short"}, {encoder_parameter_value_type::value_type_long, "value_type_long"}, {encoder_parameter_value_type::value_type_rational, "value_type_rational"}, {encoder_parameter_value_type::value_type_long_range, "value_type_long_range"}, {encoder_parameter_value_type::value_type_undefined, "value_type_undefined"}, {encoder_parameter_value_type::value_type_rational_range, "value_type_rational_range"}, {encoder_parameter_value_type::value_type_rational_pointer, "value_type_rational_pointer"}});}
      inline std::wostream& operator<<(std::wostream& os, encoder_parameter_value_type value) {return os << xtd::to_string(value, {{encoder_parameter_value_type::value_type_byte, L"value_type_byte"}, {encoder_parameter_value_type::value_type_ascii, L"value_type_ascii"}, {encoder_parameter_value_type::value_type_short, L"value_type_short"}, {encoder_parameter_value_type::value_type_long, L"value_type_long"}, {encoder_parameter_value_type::value_type_rational, L"value_type_rational"}, {encoder_parameter_value_type::value_type_long_range, L"value_type_long_range"}, {encoder_parameter_value_type::value_type_undefined, L"value_type_undefined"}, {encoder_parameter_value_type::value_type_rational_range, L"value_type_rational_range"}, {encoder_parameter_value_type::value_type_rational_pointer, L"value_type_rational_pointer"}});}
      /// @endcond
    }
  }
}
