/// @file
/// @brief Contains xtd::forms::native::form API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/drawing/icon.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class form;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains form native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native native
      /// @ingroup xtd_forms_native
      /// @warning Internal use only
      class forms_native_export_ form final static_ {
        friend xtd::forms::form;
      protected:
        /// @name Protected methods
        
        /// @{
        /// @brief Activates the form and gives it focus.
        /// @param control Control window handle.
        /// @warning Internal use only
        static void activate(intptr_t control);
        /// @brief Closes the form.
        /// @param control Control window handle.
        /// @warning Internal use only
        static void close(intptr_t control);
        /// @brief Force end dialog with specified result
        /// @param control Control window handle.
        /// @param result A dialog box id.
        /// @warning Internal use only
        static void end_dialog(intptr_t control, int32_t result);
        /// @brief Get a value indicates whether full screen window.
        /// @param control Control window handle.
        /// @return true if form is full screen; otherwise false.
        /// @warning Internal use only
        static bool full_screen(intptr_t control);
        /// @brief Set a value indicates whether full screen window.
        /// @param control Control window handle.
        /// @param full_screen true if form is full screen; otherwise false.
        /// @warning Internal use only
        static void full_screen(intptr_t control, bool full_screen);
        /// @brief Sets the icon for the form.
        /// @param control Control window handle.
        /// @param icon An icon that represents the icon for the form.
        /// @warning Internal use only
        static void icon(intptr_t control, const xtd::drawing::icon& icon);
        /// @brief Gets a value indicate whether maximized windows.
        /// @param control Control window handle.
        /// @return true if form is full screen; otherwise false.
        /// @warning Internal use only
        static bool maximize(intptr_t control);
        /// @brief Sets a value indicate whether maximized windows.
        /// @param control Control window handle.
        /// @param maximize true if form is maximized; otherwise false.
        /// @warning Internal use only
        static void maximize(intptr_t control, bool maximize);
        /// @brief Gets a value indicate whether minimized windows.
        /// @param control Control window handle.
        /// @return true if form is full screen; otherwise false.
        /// @warning Internal use only
        static bool minimize(intptr_t control);
        /// @brief Sets a value indicate whether minimized windows.
        /// @param control Control window handle.
        /// @param minimize true if form is full screen; otherwise false.
        /// @warning Internal use only
        static void minimize(intptr_t control, bool minimize);
        /// @brief Sets the main_menu that is displayed in the form.
        /// @param control Control window handle.
        /// @param menu A menu handle that represents the menu to display in the form.
        /// @warning Internal use only
        static void menu(intptr_t control, intptr_t menu);
        /// @brief Sets form opacity.
        /// @param control Control window handle.
        /// @param opacity A double-precision value between 0.0 and 1.0 that represent the form opacity.
        /// @warning Internal use only
        static void opacity(intptr_t control, double opacity);
        /// @brief Restore form in normal state (not minimized, not maximized and not full screen).
        /// @param control Control window handle.
        /// @warning Internal use only
        static void restore(intptr_t control);
        /// @brief Show dialog.
        /// @param control Control window handle.
        /// @warning Internal use only
        static int32_t show_dialog(intptr_t control);
        /// @brief Show async dialog as sheet.
        /// @param control Control window handle.
        /// @warning Internal use only
        static void show_sheet(intptr_t control);
        /// @brief Show dialog as sheet.
        /// @param control Control window handle.
        /// @warning Internal use only
        static int32_t show_sheet_dialog(intptr_t control);
        /// @brief Sets the tool_bar that is displayed in the form.
        /// @param control Control window handle.
        /// @param tool_bar A tool bar handle that represents the tool bar to display in the form.
        /// @warning Internal use only
        static void tool_bar(intptr_t control, intptr_t tool_bar);
        /// @brief Set virtual size
        /// @param control Control window handle.
        /// @param size A virtual xtd::drawing::size.
        /// @warning Internal use only
        static void virtual_size(intptr_t control, const drawing::size& size);
        /// @}
      };
    }
  }
}
