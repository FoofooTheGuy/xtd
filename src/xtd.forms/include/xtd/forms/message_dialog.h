/// @file
/// @brief Contains xtd::forms::message_dialog dialog.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <string>
#include "component.h"
#include "dialog_style.h"
#include "dialog_closed_event_handler.h"
#include "dialog_result.h"
#include "help_event_handler.h"
#include "iwin32_window.h"
#include "message_dialog_buttons.h"
#include "message_dialog_default_button.h"
#include "message_dialog_icon.h"
#include "message_dialog_options.h"

/// @cond
struct __xtd_forms_message_dialog_closed_caller__;
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Displays a message window, also known as a dialog box, which presents a message to the user. It is a modal window, blocking other actions in the application until the user closes it. A message_dialog can contain text, buttons, and symbols that inform and instruct the user.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
    ///   <tr>
    ///     <th style="width:100px"></th>
    ///     <th><b>Windows</b></th>
    ///     <th><b>macOS</b></th>
    ///     <th><b>Gnome</b></th>
    ///   </tr>
    ///   <tr>
    ///     <th>Light</th>
    ///     <td>@image html dialog_message_box_w.png</td>
    ///     <td>@image html dialog_message_box_m.png</td>
    ///     <td>@image html dialog_message_box_g.png</td>
    ///   </tr>
    ///   <tr>
    ///     <th>Dark</th>
    ///     <td>@image html dialog_message_box_wd.png</td>
    ///     <td>@image html dialog_message_box_md.png</td>
    ///     <td>@image html dialog_message_box_gd.png</td>
    ///   </tr>
    /// </table>
    /// @par Examples
    /// The following code example demonstrates the use of message_dialog dialog.
    /// @include message_dialog.cpp
    class forms_export_ message_dialog final : public component {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the message_dialog class.
      message_dialog() = default;
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets buttons to display in the message dialog.
      /// @return One of the xtd::forms::message_dialog_buttons values that specifies which buttons to display in the message dialog.
      xtd::forms::message_dialog_buttons buttons() const noexcept;
      /// @brief Sets buttons to display in the message dialog.
      /// @param buttons One of the xtd::forms::message_dialog_buttons values that specifies which buttons to display in the message dialog.
      /// @return Current message dialog.
      message_dialog& buttons(xtd::forms::message_dialog_buttons buttons);
      
      /// @brief Gets default button for the message dialog.
      /// @return One of the xtd::forms::message_dialog_default_button values that specifies the default button for the message dialog.
      xtd::forms::message_dialog_default_button default_button() const noexcept;
      /// @brief Sets default button for the message dialog.
      /// @param default_button One of the xtd::forms::message_dialog_default_button values that specifies the default button for the message dialog.
      /// @return Current message dialog.
      message_dialog& default_button(xtd::forms::message_dialog_default_button default_button);
      
      /// @brief Gets a value indicate if help button is shown.
      /// @return true to show the Help button; otherwise, false. The default is false.
      bool display_help_button() const noexcept;
      /// @brief Sets a value indicate if help button is shown.
      /// @param display_help_button true to show the Help button; otherwise, false. The default is false.
      /// @return Current message dialog.
      message_dialog& display_help_button(bool display_help_button);
      
      /// @brief Gets async dialog_result result after dialog box is closing.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      xtd::forms::dialog_result dialog_result() const noexcept;
      
      /// @brief Gets the dialog style.
      /// @return One of the xtd::forms::dialog_style values. The default value is xtd::forms::dialog_style::standard.
      xtd::forms::dialog_style dialog_style() const noexcept;
      /// @brief Sets the dialog style.
      /// @param dialog_style One of the xtd::forms::dialog_style values. The default value is xtd::forms::dialog_style::standard.
      /// @return Current message dialog.
      message_dialog& dialog_style(xtd::forms::dialog_style dialog_style);
      
      /// @brief Gets icon to display in the message dialog.
      /// @return One of the xtd::forms::message_dialog_icon values that specifies which icon to display in the message dialog.
      xtd::forms::message_dialog_icon icon() const noexcept;
      /// @brief Sets icon to display in the message dialog.
      /// @param icon One of the xtd::forms::message_dialog_icon values that specifies which icon to display in the message dialog.
      /// @return Current message dialog.
      message_dialog& icon(xtd::forms::message_dialog_icon icon);
      
      /// @brief Gets options will be used for the message box.
      /// @return One of the xtd::forms::message_dialog_options values that specifies which display and association options will be used for the message box. You may pass in 0 if you wish to use the defaults.
      xtd::forms::message_dialog_options options() const noexcept;
      /// @brief Sets options will be used for the message box.
      /// @param options One of the xtd::forms::message_dialog_options values that specifies which display and association options will be used for the message box. You may pass in 0 if you wish to use the defaults.
      /// @return Current message dialog.
      message_dialog& options(xtd::forms::message_dialog_options options);
      
      /// @brief Gets the text message.
      /// @return The text message.
      xtd::ustring message() const noexcept;
      /// @brief Sets the text message.
      /// @param message The text message.
      /// @return Current message_dialog instance.
      message_dialog& message(const xtd::ustring& message);
      
      /// @brief Gets the dialog caption text.
      /// @return The current dialog caption text.
      xtd::ustring text() const noexcept;
      /// @brief Sets the dialog caption text.
      /// @param text The new dialog caption text.
      /// @return Current message_dialog instance.
      message_dialog& text(const xtd::ustring& text);
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Resets all properties to empty string.
      void reset();
      
      /// @brief Runs message dialog box.
      xtd::forms::dialog_result show_dialog();
      /// @brief Runs message dialog box.
      xtd::forms::dialog_result show_dialog(const iwin32_window& owner);
      /// @brief Runs message dialog box.
      void show_sheet(const iwin32_window& owner);
      /// @brief Runs message dialog box.
      xtd::forms::dialog_result show_sheet_dialog(const iwin32_window& owner);
      /// @}
      
      /// @name Events
      
      /// @{
      /// @brief Occurs when the user clicks the Help button on a common dialog box.
      /// @ingroup events
      /// @remarks For more information about handling events, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_handle_and_raise_events.md">Handling and Raising Events</a>.
      event<message_dialog, help_event_handler> help_request;
      
      /// @brief Occurs when the user close a message dialog box with dialog close button or other dialog buttons.
      /// @ingroup events
      /// @remarks For more information about handling events, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_handle_and_raise_events.md">Handling and Raising Events</a>.
      event<message_dialog, dialog_closed_event_handler> dialog_closed;
      /// @}
      
    private:
      /// @cond
      friend struct ::__xtd_forms_message_dialog_closed_caller__;
      /// @endcond
      
      /// @brief Raises the message_dialog::dialog_close event.
      /// @param e An message_dialog_close_event_args that provides the event data.
      /// @remarks This method is invoked when the message dialog box is closed.
      virtual void on_dialog_closed(const dialog_closed_event_args& e);
      
      struct data {
        xtd::forms::message_dialog_buttons buttons = xtd::forms::message_dialog_buttons::ok;
        xtd::forms::message_dialog_default_button default_button = xtd::forms::message_dialog_default_button::button1;
        xtd::forms::dialog_result dialog_result = xtd::forms::dialog_result::none;
        xtd::forms::dialog_style dialog_style = xtd::forms::dialog_style::system;
        bool display_help_button = false;
        xtd::forms::message_dialog_icon icon = xtd::forms::message_dialog_icon::none;
        xtd::forms::message_dialog_options options = static_cast<xtd::forms::message_dialog_options>(0);
        xtd::ustring message;
        xtd::ustring text;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
