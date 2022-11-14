/// @file
/// @brief Contains xtd::drawing::drawing2d::flush_intention enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::drawing2d namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing2d {
      /// @brief Specifies whether commands in the graphics stack are terminated (flushed) immediately or executed as soon as possible.
      /// @par Namespace
      /// xtd::drawing::drawing2d
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      enum class flush_intention {
        /// @brief Specifies that the stack of all graphics operations is flushed immediately.
        flush = 0,
        /// @brief Specifies that all graphics operations on the stack are executed as soon as possible. This synchronizes the graphics state.
        sync = 1,
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::drawing::drawing2d::flush_intention> {
  void operator()(xtd::enum_collection<xtd::drawing::drawing2d::flush_intention>& values, xtd::enum_type& type) {values = {{xtd::drawing::drawing2d::flush_intention::flush, "flush"}, {xtd::drawing::drawing2d::flush_intention::sync, "sync"}};}
};
/// @endcond
