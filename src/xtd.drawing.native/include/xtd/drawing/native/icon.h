#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <istream>
#include <vector>
#include <xtd/static.h>
#include <xtd/ustring.h>
#include <xtd/drawing_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class icon;
    /// @endcond
    
    /// @brief The xtd::drawing::native namespace contains internal native API definitions to access underlying toolkits used by xtd.drawing library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains icon native API.
      /// @par Namespace
      /// xtd::drawing::native
      /// @par Library
      /// xtd.drawing.native
      /// @ingroup xtd_drawing_native native
      /// @warning Internal use only
      class drawing_native_export_ icon final static_ {
        friend xtd::drawing::icon;
      protected:
        /// @name Protected methods
        
        /// @{
        /// @brief Creates an icon from specified filename.
        /// @param filename The filename of the icon.
        /// @return A new icon handle.
        /// @warning Internal use only
        static intptr_t create(const xtd::ustring& filename);
        /// @brief Creates an icon from specified filename, and size.
        /// @param filename The filename of the icon.
        /// @param width The desired width of the icon.
        /// @param height The desired height of the icon.
        /// @return A new icon handle.
        /// @warning Internal use only
        static intptr_t create(const xtd::ustring& filename, int32_t width, int32_t height);
        /// @brief Creates an icon from specified std::stream.
        /// @param stream The stream containing the icon.
        /// @return A new icon handle.
        /// @warning Internal use only
        static intptr_t create(std::istream& stream);
        /// @brief Creates an icon from specified std::stream, and size.
        /// @param stream The stream containing the icon.
        /// @param width The desired width of the icon.
        /// @param height The desired height of the icon.
        /// @return A new icon handle.
        /// @warning Internal use only
        static intptr_t create(std::istream& stream, int32_t width, int32_t height);
        /// @brief Creates an icon from bits.
        /// @param bits The bits containing the icon.
        /// @return A new icon handle.
        /// @warning Internal use only
        static intptr_t create(const char* const* bits);
        /// @brief Creates an icon from specified bits, and size.
        /// @param stream The bits containing the icon.
        /// @param width The desired width of the icon.
        /// @param height The desired height of the icon.
        /// @return A new icon handle.
        /// @warning Internal use only
        static intptr_t create(const char* const* bits, int32_t width, int32_t height);
        /// @brief Creates an icon from image.
        /// @param image The image handle containing the icon.
        /// @return A new icon handle.
        /// @warning Internal use only
        static intptr_t create(intptr_t image);
        /// @brief Creates an icon from specified icon, and size.
        /// @param icon The icon handle containing the icon.
        /// @param width The desired width of the icon.
        /// @param height The desired height of the icon.
        /// @return A new icon handle.
        /// @warning Internal use only
        static intptr_t create(intptr_t icon, int32_t width, int32_t height);

        /// @brief Destroys the icon.
        /// @param icon The icon handle to destroy.
        /// @return A new icon handle.
        /// @warning Internal use only
        static void destroy(intptr_t icon);

        /// @brief Creates an icon from handle.
        /// @param handle The icon handle .
        /// @return A new icon handle.
        /// @warning Internal use only
        static intptr_t from_handle(intptr_t handle);

        /// @brief Gets the height of icon.
        /// @param icon The icon handle .
        /// @return The height of icon.
        /// @warning Internal use only
        static int32_t get_height(intptr_t icon);

        /// @brief Gets the width of icon.
        /// @param icon The icon handle .
        /// @return The width of icon.
        /// @warning Internal use only
        static int32_t get_width(intptr_t icon);

        /// @brief Saves icon to the specified output filename.
        /// @param icon The icon handle .
        /// @param filename The file to save to.
        /// @warning Internal use only
        static void save(intptr_t icon, const xtd::ustring& filename);
        /// @brief Saves icon to the specified output std::ostream.
        /// @param icon The icon handle .
        /// @param stream The std::ostream to save to.
        /// @warning Internal use only
        static void save(intptr_t icon, std::ostream& stream, size_t raw_format);

        /// @brief Converts icon to an image.
        /// @param icon The icon handle .
        /// @return A image handle that represents the converted icon.
        /// @warning Internal use only
        static intptr_t to_image(intptr_t icon);
        /// @}
      };
    }
  }
}
