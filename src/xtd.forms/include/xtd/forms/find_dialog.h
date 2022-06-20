/// @file
/// @brief Contains xtd::forms::find_dialog dialog.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/event.h>
#include <xtd/ustring.h>
#include <xtd/drawing/point.h>
#include "component.h"
#include "dialog_closed_event_handler.h"
#include "dialog_style.h"
#include "find_event_handler.h"
#include "search_direction.h"
#include "iwin32_window.h"
#include "layout/arranged_element_collection.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a dialog box that displays find dialog.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Examples
    /// The following code example demonstrates the use of find_dialog dialog.
    /// @include find_dialog.cpp
    class forms_export_ find_dialog final : public component {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the find_dialog class.
      find_dialog() = default;
      /// @}
      
      /// @cond
      ~find_dialog();
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the string to find.
      /// @return The string to find.
      const xtd::ustring& find_string() const;
      /// @brief Sets the string to find.
      /// @param value The string to find.
      /// @return Current find_dialog instance.
      find_dialog& find_string(const xtd::ustring& value);
      
      /// @brief Gets the coordinates of the upper-left corner of the dialog relative to the upper-left corner of the screen.
      /// @return The point that represents the upper-left corner of the dialog relative to the upper-left corner of its screen.
      xtd::drawing::point location() const;
      /// @brief Sets the coordinates of the upper-left corner of the dialog relative to the upper-left corner of the screen.
      /// @param value The point that represents the upper-left corner of the dialog relative to the upper-left corner of its screen.
      /// @return Current find_dialog instance.
      find_dialog& location(const xtd::drawing::point& value);
      
      /// @brief Gets the match case value.
      /// @return true if match case option selected; otherwise false. The default is false.
      bool match_case() const;
      /// @brief Sets the match case value.
      /// @param value true if match case option selected; otherwise false. The default is false.
      /// @return Current find_dialog instance.
      find_dialog& match_case(bool value);
      
      /// @brief Gets the search direction value.
      /// @return One of xtd::forms::search_direction values. The default is xtd::forms::search_direction::down.
      xtd::forms::search_direction search_direction() const;
      /// @brief Gets the search direction value.
      /// @param value One of xtd::forms::search_direction values. The default is xtd::forms::search_direction::down.
      /// @return Current find_dialog instance.
      find_dialog& search_direction(xtd::forms::search_direction value);
      
      /// @brief Gets a value that indicates whether match case option is shown.
      /// @return true if match case option is shown; otherwise false. The default is true.
      bool show_match_case() const;
      /// @brief Sets a value that indicates whether match case option is shown.
      /// @param value true if match case option is shown; otherwise false. The default is true.
      /// @return Current find_dialog instance.
      find_dialog& show_match_case(bool value);
      
      /// @brief Gets a value that indicates whether up down option is shown.
      /// @return true if up down option is shown; otherwise false. The default is true.
      bool show_up_down() const;
      /// @brief Sets a value that indicates whether up down option is shown.
      /// @param value true if up down option is shown; otherwise false. The default is true.
      /// @return Current find_dialog instance.
      find_dialog& show_up_down(bool value);
      
      /// @brief Gets a value that indicates whether whole word option is shown.
      /// @return true if whole word option is shown; otherwise false. The default is true.
      bool show_whole_word() const;
      /// @brief Sets a value that indicates whether whole word option is shown.
      /// @param value true if whole word option is shown; otherwise false. The default is true.
      /// @return Current find_dialog instance.
      find_dialog& show_whole_word(bool value);
      
      /// @brief Gets the find dialog title.
      /// @return The find dialog title.
      const xtd::ustring& title() const;
      /// @brief Sets the find dialog title.
      /// @param value The find dialog title.
      /// @return Current find_dialog instance.
      find_dialog& title(const xtd::ustring& value);
      
      /// @brief Gets the whole word value.
      /// @return true if whole word option selected; otherwise false. The default is false.
      bool whole_word() const;
      /// @brief Sets the whole word value.
      /// @param value true if whole word option selected; otherwise false. The default is false.
      /// @return Current find_dialog instance.
      find_dialog& whole_word(bool value);
      /// @}
      
      /// @name Events
      
      /// @{
      /// @brief Occurs when the user click the find button.
      /// @ingroup events
      /// @remarks For more information about handling events, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_handle_and_raise_events.md">Handling and Raising Events</a>.
      xtd::event<find_dialog, xtd::forms::find_event_handler> find_next;
      
      /// @brief Occurs when the user close the find dialog box with dialog close button or cancel button.
      /// @ingroup events
      /// @remarks The xtd::forms::dialog_closed_event_args::dialog_result is always set to xtd::forms::dialog_result::cancel
      /// @remarks For more information about handling events, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_handle_and_raise_events.md">Handling and Raising Events</a>.
      xtd::event<find_dialog, xtd::forms::dialog_closed_event_handler> dialog_closed;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Closes the find dialog box.
      /// @remarks If the find dialog box is already closed, this method does nothing.
      void close();
      
      /// @brief Resets all properties to default values.
      /// @remarks When you reset the xtd::forms::find::dialog, the following read/write properties are set to initial values.
      /// | Property         | Value                              |
      /// |------------------|------------------------------------|
      /// | title            | ""                                 |
      /// | find_string      | ""                                 |
      /// | show_up_down     | true                               |
      /// | show_whole_word  | true                               |
      /// | show_match_case  | true                               |
      /// | search_direction | xtd::forms::search_direction::down |
      /// | whole_word       | false                              |
      /// | match_case       | false                              |
      void reset();
      
      /// @brief Runs find dialog box.
      /// @remarks If the find dialog box is already displayed, this method does nothing.
      void show(const iwin32_window& owner);
      /// @}
      
    private:
      struct data {
        xtd::forms::dialog_style dialog_style = xtd::forms::dialog_style::standard;
        xtd::ustring find_string;
        intptr_t handle = 0;
        std::optional<xtd::drawing::point> location;
        bool match_case = false;
        const iwin32_window* owner;
        bool show_match_case = true;
        bool show_up_down = true;
        bool show_whole_word = true;
        xtd::forms::search_direction search_direction = xtd::forms::search_direction::down;
        xtd::ustring title;
        bool visible = false;
        bool whole_word = false;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
      void create_handle();
      void destroy_handle();
      void recreate_handle();
      void on_dialog_closed();
      void on_dialog_find(const xtd::drawing::point& location, const ustring& find_string, bool downwards, bool whole_word, bool match_case);
    };
  }
}
