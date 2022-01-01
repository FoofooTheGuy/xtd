/// @file
/// @brief Contains xtd::day_of_week enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Specifies the day of the week.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Example
  /// The following example demonstrates the xtd::date_time::day_of_week property and the xtd::day_of_week enumeration.
  /// @include date_time_day_of_week.cpp
  /// @remarks The xtd::day_of_week enumeration represents the day of the week in calendars that have seven days per week. The value of the constants in this enumeration ranges from xtd::day_of_week::sunday to xtd::day_of_week::saturday. If cast to an integer, its value ranges from zero (which indicates xtd::day_of_week::sunday) to six (which indicates xtd::day_of_week::saturday).
  /// @remarks This enumeration is useful when it is desirable to have a strongly typed specification of the day of the week. For example, this enumeration is the type of the property value for the xtd::date_time::day_of_week and xtd::date_time_offset::day_of_week properties.
  /// @remarks The members of the xtd::day_of_week enumeration are not localized. To return the localized name of the day of the week, call the xtd::date_time::to_string(ustring) method with either the "h" or "H" format strings. The former format string produces the abbreviated weekday name; the latter produces the full weekday name.
  enum class day_of_week {
    /// @brief Indicates sunday.
    sunday,
    /// @brief Indicates monday.
    monday,
    /// @brief Indicates tuesday.
    tuesday,
    /// @brief Indicates wednesday.
    wednesday,
    /// @brief Indicates thursday.
    thursday,
    /// @brief Indicates friday.
    friday,
    /// @brief Indicates saturday.
    saturday
  };

  /// @cond
  inline std::ostream& operator<<(std::ostream& os, const day_of_week value) {return os << to_string(value, { {day_of_week::sunday, "sunday"}, {day_of_week::monday, "monday"}, {day_of_week::tuesday, "tuesday"}, {day_of_week::wednesday, "wednesday"}, {day_of_week::thursday, "thursday"}, {day_of_week::friday, "friday"}, {day_of_week::saturday, "saturday"}});}
  inline std::wostream& operator<<(std::wostream& os, const day_of_week value) {return os << to_string(value, { {day_of_week::sunday, L"sunday"}, {day_of_week::monday, L"monday"}, {day_of_week::tuesday, L"tuesday"}, {day_of_week::wednesday, L"wednesday"}, {day_of_week::thursday, L"thursday"}, {day_of_week::friday, L"friday"}, {day_of_week::saturday, L"saturday"}});}
  /// @endcond
}
