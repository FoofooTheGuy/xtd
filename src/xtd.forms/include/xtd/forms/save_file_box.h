/// @file
/// @brief Contains xtd::forms::save_file_box control.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/static.h>
#include "save_file_dialog.h"
#include "save_file_box_options.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays a file save dialog to the user to select a location for saving a file.
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
    ///     <td>@image html dialog_save_file_dialog_w.png</td>
    ///     <td>@image html dialog_save_file_dialog_m.png</td>
    ///     <td>@image html dialog_save_file_dialog_g.png</td>
    ///   </tr>
    ///   <tr>
    ///     <th>Dark</th>
    ///     <td>@image html dialog_save_file_dialog_wd.png</td>
    ///     <td>@image html dialog_save_file_dialog_md.png</td>
    ///     <td>@image html dialog_save_file_dialog_gd.png</td>
    ///   </tr>
    /// </table>
    /// @par Examples
    /// The following code example demonstrates the use of xtd::forms::save_file_box dialog.
    /// @include save_file_box.cpp
    class save_file_box final static_ {
    public:
      /// @name Methods
      
      /// @{
      /// @brief Displays a save file dialog box in front of a specified window.
      /// @param file_name An output xtd::ustring that will store the selected file name.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& file_name, const xtd::forms::iwin32_window& owner) { return show_save_file_box(file_name, "", "", "", save_file_box_options::none, &owner); }
      
      /// @brief Displays a save file dialog box in front of a specified window.
      /// @param file_name An output xtd::ustring that will store the selected file name.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::ustring that specifies the caption title of the file dialog box.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& file_name, const xtd::forms::iwin32_window& owner, const xtd::ustring& title) { return show_save_file_box(file_name, title, "", "", save_file_box_options::none, &owner); }
      
      /// @brief Displays a save file dialog box in front of a specified window.
      /// @param file_name An output xtd::ustring that will store the selected file name.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::ustring that specifies the caption title of the file dialog box.
      /// @param options A bitwise combination of enum xtd::forms::save_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& file_name, const xtd::forms::iwin32_window& owner, const xtd::ustring& title, const save_file_box_options options) { return show_save_file_box(file_name, title, "", "", options, &owner); }
      
      /// @brief Displays a save file dialog box in front of a specified window.
      /// @param file_name An output xtd::ustring that will store the selected file name.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::ustring that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::ustring that specifies the initial directory displayed by the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& file_name, const xtd::forms::iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& initial_directory) { return show_save_file_box(file_name, title, initial_directory, "", save_file_box_options::none, &owner); }
      
      /// @brief Displays a save file dialog box in front of a specified window.
      /// @param file_name An output xtd::ustring that will store the selected file name.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::ustring that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::ustring that specifies the initial directory displayed by the file dialog box
      /// @param options A bitwise combination of enum xtd::forms::save_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& file_name, const xtd::forms::iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& initial_directory, const save_file_box_options options) { return show_save_file_box(file_name, title, initial_directory, "", options, &owner); }
      
      /// @brief Displays a save file dialog box in front of a specified window.
      /// @param file_name An output xtd::ustring that will store the selected file name.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::ustring that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::ustring that specifies the initial directory displayed by the file dialog box
      /// @param filter An xtd::ustring that specifies the file name filter string, which determines the choices that appear in the "Save as file type" or "Files of type" box in the dialog box, separated by vertical bar | for example: @verbatim (*.txt)|*.txt|All files (*.*)|*.* @endverbatim
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& file_name, const xtd::forms::iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& initial_directory,  const xtd::ustring& filter) { return show_save_file_box(file_name, title, initial_directory, filter, save_file_box_options::none, &owner); }
      
      /// @brief Displays a save file dialog box in front of a specified window.
      /// @param file_name An output xtd::ustring that will store the selected file name.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::ustring that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::ustring that specifies the initial directory displayed by the file dialog box
      /// @param filter An xtd::ustring that specifies the file name filter string, which determines the choices that appear in the "Save as file type" or "Files of type" box in the dialog box, separated by vertical bar | for example: @verbatim (*.txt)|*.txt|All files (*.*)|*.* @endverbatim
      /// @param options A bitwise combination of enum xtd::forms::save_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& file_name, const xtd::forms::iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& initial_directory,  const xtd::ustring& filter, const save_file_box_options options) { return show_save_file_box(file_name, title, initial_directory, filter, options, &owner); }
      
      /// @brief Displays a save file dialog box.
      /// @param file_name An output xtd::ustring that will store the selected file name.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& file_name) { return show_save_file_box(file_name, "", "", "", save_file_box_options::none, nullptr); }
      
      /// @brief Displays a save file dialog box.
      /// @param file_name An output xtd::ustring that will store the selected file name.
      /// @param title An xtd::ustring that specifies the caption title of the file dialog box.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& file_name, const xtd::ustring& title) { return show_save_file_box(file_name, title, "", "", save_file_box_options::none, nullptr); }
      
      /// @brief Displays a select file dialog box.
      /// @param file_name An output xtd::ustring that will store the selected file name.
      /// @param title An xtd::ustring that specifies the caption title of the file dialog box.
      /// @param options A bitwise combination of enum xtd::forms::save_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& file_name, const xtd::ustring& title, const save_file_box_options options) { return show_save_file_box(file_name, title, "", "", options, nullptr); }
      
      /// @brief Displays a save file dialog box.
      /// @param file_name An output xtd::ustring that will store the selected file name.
      /// @param title An xtd::ustring that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::ustring that specifies the initial directory displayed by the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& file_name, const xtd::ustring& title, const xtd::ustring& initial_directory) { return show_save_file_box(file_name, title, initial_directory, "", save_file_box_options::none, nullptr); }
      
      /// @brief Displays a save file dialog box.
      /// @param file_name An output xtd::ustring that will store the selected file name.
      /// @param title An xtd::ustring that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::ustring that specifies the initial directory displayed by the file dialog box
      /// @param options A bitwise combination of enum xtd::forms::save_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& file_name, const xtd::ustring& title, const xtd::ustring& initial_directory, const save_file_box_options options) { return show_save_file_box(file_name, title, initial_directory, "", options, nullptr); }
      
      /// @brief Displays a save file dialog box.
      /// @param file_name An output xtd::ustring that will store the selected file name.
      /// @param title An xtd::ustring that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::ustring that specifies the initial directory displayed by the file dialog box
      /// @param filter An xtd::ustring that specifies the file name filter string, which determines the choices that appear in the "Save as file type" or "Files of type" box in the dialog box, separated by vertical bar | for example: @verbatim (*.txt)|*.txt|All files (*.*)|*.* @endverbatim
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& file_name, const xtd::ustring& title, const xtd::ustring& initial_directory,  const xtd::ustring& filter) { return show_save_file_box(file_name, title, initial_directory, filter, save_file_box_options::none, nullptr); }
      
      /// @brief Displays a save file dialog box.
      /// @param file_name An output xtd::ustring that will store the selected file name.
      /// @param title An xtd::ustring that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::ustring that specifies the initial directory displayed by the file dialog box
      /// @param filter An xtd::ustring that specifies the file name filter string, which determines the choices that appear in the "Save as file type" or "Files of type" box in the dialog box, separated by vertical bar | for example: @verbatim (*.txt)|*.txt|All files (*.*)|*.* @endverbatim
      /// @param options A bitwise combination of enum xtd::forms::save_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& file_name, const xtd::ustring& title, const xtd::ustring& initial_directory,  const xtd::ustring& filter, const save_file_box_options options) { return show_save_file_box(file_name, title, initial_directory, filter, options, nullptr); }
      /// @}
      
    private:
      static xtd::forms::dialog_result show_save_file_box(xtd::ustring& output, const xtd::ustring& title, const xtd::ustring& initial_directory = "", const xtd::ustring& filter = "", const save_file_box_options options = save_file_box_options::none, const iwin32_window* owner = nullptr) {
        xtd::forms::save_file_dialog dialog{};
        dialog.title(title)
        .initial_directory(initial_directory)
        .file_name(output)
        .filter(filter)
        .check_file_exists(options & save_file_box_options::check_file_exists)
        .dereference_link(options & save_file_box_options::dereference_link)
        .validate_names(options & save_file_box_options::validate_names)
        .restore_directory(options & save_file_box_options::restore_directory)
        .auto_upgrade_enabled(options & save_file_box_options::enable_auto_upgrade)
        .show_hidden_files(options & save_file_box_options::show_hidden_files)
        .show_help(options & save_file_box_options::show_help)
        .show_preview(options & save_file_box_options::show_preview)
        .support_multi_dotted_extensions(options & save_file_box_options::support_multi_dotted_extensions);
        const auto res = owner ? dialog.show_sheet_dialog(*owner) : dialog.show_dialog();
        if (res == dialog_result::ok)
          output = dialog.file_name();
        return res;
      }
    };
  }
}
