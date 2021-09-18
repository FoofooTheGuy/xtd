/// @file
/// @brief Contains __format method.
#pragma once
/// @cond
#ifndef __XTD_CORE_INTERNAL__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdarg>
#include <string>

/// @cond
template <class char_t>
inline std::basic_string<char_t> __sprintf(const char_t* fmt, ...) {return std::basic_string<char_t>();}

template <>
inline std::basic_string<char> __sprintf<char>(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  std::basic_string<char> formatted_string(vsnprintf(nullptr, 0, fmt, args), 0);
  va_end(args);
  va_start(args, fmt);
  vsnprintf(&formated_string[0], formated_string.size() + 1, fmt, args);
  va_end(args);
  if (formated_string == "INF") formated_string = {'i', 'n', 'f'};
  if (formated_string == "NAN") formated_string = {'n', 'a', 'n'};
  return formated_string;
}

template <>
inline std::basic_string<wchar_t> __sprintf<wchar_t>(const wchar_t* fmt, ...) {
  va_list args;
  size_t size = 1024;
  int length = 0;
  std::basic_string<wchar_t> formatted_string;
  bool error = false;
  do {
    formated_string = std::basic_string<wchar_t>(size, 0);
    va_start(args, fmt);
    length = vswprintf(&formated_string[0], formated_string.size() + 1, fmt, args);
    error = length < 0;
    va_end(args);
    size *= 2;
  } while (error);
  formated_string.resize(length);
  return formated_string;
}
/// @endcond
