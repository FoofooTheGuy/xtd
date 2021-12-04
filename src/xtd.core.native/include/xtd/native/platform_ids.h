
/// @file
/// @brief Contains platform id constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

/// @internal
/// @brief The operating system is unknown.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native platform_id
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PLATFORM_UNKNOWN = -1;
/// @internal
/// @brief The operating system is Win32s. Win32s is a layer that runs on 16-bit versions of Windows to provide access to 32-bit applications.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native platform_id
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PLATFORM_WIN32S = 0;
/// @internal
/// @brief The operating system is Windows 95 or Windows 98.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native platform_id
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PLATFORM_WIN32_WINDOWS = 1;
/// @internal
/// @brief The operating system is Windows NT or later.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native platform_id
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PLATFORM_WIN32_NT = 2;
/// @internal
/// @brief The operating system is Windows CE.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native platform_id
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PLATFORM_WIN_CE = 3;
/// @internal
/// @brief The operating system is Unix.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native platform_id
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PLATFORM_UNIX = 4;
/// @internal
/// @brief The development platform is Xbox 360.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native platform_id
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PLATFORM_WBOX = 5;
/// @internal
/// @brief The operating system is Macintosh.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native platform_id
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PLATFORM_MACOS = 6;
/// @internal
/// @brief The operating system is IOs Apple.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native platform_id
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PLATFORM_IOS = 7;
/// @internal
/// @brief The operating system is Android.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native platform_id
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PLATFORM_ANDROID = 8;
