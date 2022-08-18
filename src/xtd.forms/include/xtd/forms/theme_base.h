/// @file
/// @brief Contains xtd::forms::theme_base class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/environment.h>
#include <xtd/object.h>
#include <xtd/ustring.h>
#include "../forms_export.h"
#include "theme_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class forms_export_ theme_base : public object {
    public:
      /// @name Alias
      
      /// @{
      using theme_name_collection = std::vector<xtd::ustring>;
      /// @}
      
      /// @name Fields
      
      /// @{
      static const theme_base empty;
      /// @}
      
      /// @cond
      theme_base(const theme_base&) = default;
      theme_base& operator=(const theme_base&) = default;
      bool operator==(const theme_base& value) const {return name_ == value.name_ && theme_style_ == value.theme_style_ && is_default_ == value.is_default();}
      bool operator!=(const theme_base& value) const {return !operator==(value);}
      friend std::ostream& operator<<(std::ostream& os, const theme_base& theme) noexcept {return os << theme.to_string();}
      /// @endcond
      
      /// @name Properties
      
      /// @{
      static xtd::ustring default_theme_name();
      
      static xtd::ustring fallback_theme_name() {return "symbolic";}
      
      bool is_default() const {return is_default_;}
      
      static const theme_name_collection& theme_names() {return theme_names_;}
      
      virtual const xtd::ustring& name() const {return name_;}
      theme_base& name(const xtd::ustring& name) {
        name_ = name;
        return *this;
      }
      
      xtd::forms::theme_style theme_style() const {return theme_style_;}
      theme_base& theme_style(xtd::forms::theme_style theme_style) {
        theme_style_ = theme_style;
        return *this;
      }
      /// @}
      
      /// @name Methods
      
      /// @{
      xtd::ustring to_string() const noexcept override {return xtd::ustring::format("[name={}, style={}, is_default={}] ", name_, theme_style_, is_default_);}
      /// @}
      
    protected:
      /// @name Protcted constructors
      
      /// @{
      theme_base() = default;
      explicit theme_base(const xtd::ustring& name) : name_(name) {}
      theme_base(const xtd::ustring& name, xtd::forms::theme_style theme_style) : name_(name), theme_style_(theme_style) {}
      theme_base(const xtd::ustring& name, xtd::forms::theme_style theme_style, bool is_default) : name_(name), theme_style_(theme_style), is_default_(is_default) {}
      /// @}
      
      /// @name Protected properties
      
      /// @{
      theme_base& is_default(bool is_default) {
        is_default_ = is_default;
        return *this;
      }
      /// @}
      
    private:
      xtd::ustring name_;
      xtd::forms::theme_style theme_style_ = xtd::forms::theme_style::undefined;
      bool is_default_ = false;
      static theme_name_collection theme_names_;
    };
  }
}

/* Include file :
 --------------
#pragma once
#include "theme_base.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class theme final : public theme_base {
    public:
      theme() = default;
      explicit theme(const xtd::ustring& name) : theme_base(name) {}
      theme(const xtd::ustring& name, xtd::forms::theme_style theme_style) : theme_base(name, theme_style) {}
      /// @cond
      theme(const theme&) = default;
      theme& operator=(const theme&) = default;
      bool operator==(const theme& value) const {return theme_base::operator==(value);}
      bool operator!=(const theme& value) const {return !operator==(value);}
      /// @endcond

      static const theme empty;

      static theme current_theme() {
        if (current_theme_ == theme::empty()) current_theme_ = default_theme();
        return current_theme_;
      }
      static void current_theme(const theme& theme) {current_theme_ = theme;}
      static void current_theme(const xtd::ustring& name) {current_theme_ = theme_from_name(name);}

      static theme default_theme() {return theme_from_name(default_theme_name());}

      static theme theme_from_name(const xtd::ustring& theme_name);

    private:
      theme(const xtd::ustring& name, xtd::forms::theme_style theme_style, bool is_default) : theme_base(name, theme_style, is_default) {}
      static theme current_theme_;
    };
  }
}
*/


/* Source file :
 ---------------
#include "../../../include/xtd/forms/theme.h"

using namespace xtd::forms;

const theme theme::empty {};
theme theme::current_theme_;

theme theme::theme_from_name(const xtd::ustring& name) {
  if (name == default_theme_name()) return theme(default_theme_name(), theme_style::system_auto);
  if (name == "gnome") return theme("gnome", theme_style::system_auto);
  if (name == "gnome (dark)") return theme("gnome (dark)", theme_style::dark);
  if (name == "gnome (light)") return theme("gnome (light)", theme_style::light);
  if (name == "kde") return theme("kde", theme_style::system_auto);
  if (name == "kde (dark)") return theme("kde (dark)", theme_style::dark);
  if (name == "kde (light)") return theme("kde (light)", theme_style::light);
  if (name == "macos") return theme("macos", theme_style::system_auto);
  if (name == "macos (dark)") return theme("macos (dark)", theme_style::dark);
  if (name == "macos (light)") return theme("macos (light)", theme_style::light);
  if (name == "symbolic") return theme("symbolic", theme_style::system_auto);
  if (name == "symbolic (dark)") return theme("symbolic (dark)", theme_style::dark);
  if (name == "symbolic (light)") return theme("symbolic (light)", theme_style::light);
  if (name == "windows") return theme("windows", theme_style::system_auto);
  if (name == "windows (dark)") return theme("windows (dark)", theme_style::dark);
  if (name == "windows (light)") return theme("windows (light)", theme_style::light);
  if (name == "xtd") return theme("xtd", theme_style::system_auto);
  if (name == "xtd (dark)") return theme("xtd (dark)", theme_style::dark);
  if (name == "xtd (light)") return theme("xtd (light)", theme_style::light);
  return default_theme();
}

*/
