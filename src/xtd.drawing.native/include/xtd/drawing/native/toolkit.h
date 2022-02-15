#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <xtd/static.h>
#include <xtd/drawing_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace forms {
    namespace native {
      class application;
    }
  }
  /// @cond
  
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::native namespace contains internal native API definitions to access underlying toolkits used by xtd.drawing library.
    /// @warning Internal use only
    namespace native {
      /// @cond
      class brush;
      class font;
      class font_family;
      class graphics_path;
      class icon;
      class image;
      class pen;
      class region;
      class system_colors;
      class system_fonts;
      /// @endcond
      
      /// @brief Contains toolkit native API.
      /// @par Namespace
      /// xtd::drawing::native
      /// @par Library
      /// xtd.drawing.native
      /// @ingroup xtd_drawing_native native
      /// @warning Internal use only
      class drawing_native_export_ toolkit final static_ {
        friend xtd::drawing::native::brush;
        friend xtd::drawing::native::font;
        friend xtd::drawing::native::font_family;
        friend xtd::drawing::native::graphics_path;
        friend xtd::drawing::native::icon;
        friend xtd::drawing::native::image;
        friend xtd::drawing::native::pen;
        friend xtd::drawing::native::region;
        friend xtd::drawing::native::system_colors;
        friend xtd::drawing::native::system_fonts;
        friend xtd::forms::native::application;
      protected:
        /// @name Protected methods
        
        /// @{
        static intptr_t initialize();
        static void shutdown(intptr_t handle);
        /// @}
      };
    }
  }
}
