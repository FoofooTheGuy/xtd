/// @file
/// @brief Contains xtd::forms::common_dialog_closed_event_args event args.
#pragma once
#include <xtd/event_handler.h>
#include "dialog_result.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides data for a common dialog closed event.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    class common_dialog_closed_event_args final : public event_args {
    public:
      common_dialog_closed_event_args() = default;
      explicit common_dialog_closed_event_args(forms::dialog_result dialog_result) : dialog_result_(dialog_result) {};
      
      virtual forms::dialog_result dialog_result() const {return dialog_result_;}
      
    private:
      forms::dialog_result dialog_result_ = forms::dialog_result::none;
    };
  }
}
