/// @file
/// @brief Contains xtd::forms::main_menu menu.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <memory>
#include <vector>
#include "menu_item.h"
#include "message.h"
#include "theme_images.h"
#include <xtd/drawing/size.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class form;
    /// @endcond
    
    /// @brief Represents the menu structure of a form.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms menus_and_toolbars
    /// @par Examples
    /// The following code example demonstrate the use of main_menu control.
    /// @include main_menu.cpp
    /// @par Examples
    /// The following code example demonstrate the use of main_menu::create_standard_items factory.
    /// @include main_menu_create_standard_items.cpp
    class forms_export_ main_menu : public menu {
    public:
      /// @brief Initialize a new instance of main_menu class.
      main_menu();
      /// @brief Initialize a new instance of main_menu class.
      /// @param menu_items An array of menu_item objects that will be added to the main_menu.
      main_menu(const std::vector<menu_item_ref>& menu_items);
      /// @cond
      main_menu(const std::initializer_list<const_menu_item_ref>& menu_items);
      /// @endcond
      
      /// @brief A factory to create a main menu with specified on click event handler.
      /// @param menu_items an array xtd::forms::menu_item which will contain the created menu items.
      /// @param on_click an event handler to respond on lick event.
      /// @return new main menu instance.
      /// @remarks The following table shows the items contained in the menu_items array :
      /// | Position | menu item          |
      /// |----------|--------------------|
      /// | 0        | file               |
      /// | 1        | file new           |
      /// | 2        | file open          |
      /// | 3        | file separator1    |
      /// | 4        | file save          |
      /// | 5        | file save_as       |
      /// | 6        | file separator2    |
      /// | 7        | file print         |
      /// | 8        | file print_preview |
      /// | 9        | file separator3    |
      /// | 10       | file exit          |
      /// | 11       | edit               |
      /// | 12       | edit undo          |
      /// | 13       | edit redo          |
      /// | 14       | edit separator1    |
      /// | 15       | edit cut           |
      /// | 16       | edit copy          |
      /// | 17       | edit paste         |
      /// | 18       | edit separator2    |
      /// | 19       | edit select_all    |
      /// | 20       | tools              |
      /// | 21       | tools customize    |
      /// | 22       | tools options      |
      /// | 23       | help               |
      /// | 24       | help contents      |
      /// | 25       | help index         |
      /// | 26       | help search        |
      /// | 27       | help separator1    |
      /// | 28       | help about         |
      static std::unique_ptr<xtd::forms::main_menu> create_standard_items(std::vector<std::unique_ptr<menu_item>>& menu_items, const xtd::event_handler& on_click);
      /// @brief A factory to create a main menu with specified image size and on click event handler.
      /// @param menu_items an array xtd::forms::menu_item which will contain the created menu items.
      /// @param image_size A xtd::drawing::size that represent the menu item image size.
      /// @param on_click an event handler to respond on lick event.
      /// @return new main menu instance.
      /// @remarks The following table shows the items contained in the menu_items array :
      /// | Position | menu item          |
      /// |----------|--------------------|
      /// | 0        | file               |
      /// | 1        | file new           |
      /// | 2        | file open          |
      /// | 3        | file separator1    |
      /// | 4        | file save          |
      /// | 5        | file save_as       |
      /// | 6        | file separator2    |
      /// | 7        | file print         |
      /// | 8        | file print_preview |
      /// | 9        | file separator3    |
      /// | 10       | file exit          |
      /// | 11       | edit               |
      /// | 12       | edit undo          |
      /// | 13       | edit redo          |
      /// | 14       | edit separator1    |
      /// | 15       | edit cut           |
      /// | 16       | edit copy          |
      /// | 17       | edit paste         |
      /// | 18       | edit separator2    |
      /// | 19       | edit select_all    |
      /// | 20       | tools              |
      /// | 21       | tools customize    |
      /// | 22       | tools options      |
      /// | 23       | help               |
      /// | 24       | help contents      |
      /// | 25       | help index         |
      /// | 26       | help search        |
      /// | 27       | help separator1    |
      /// | 28       | help about         |
      static std::unique_ptr<xtd::forms::main_menu> create_standard_items(std::vector<std::unique_ptr<menu_item>>& menu_items, const xtd::drawing::size& image_size, const xtd::event_handler& on_click);
      /// @brief A factory to create a main menu with specified theme and on click event handler.
      /// @param menu_items an array xtd::forms::menu_item which will contain the created menu items.
      /// @param theme The theme of menu item image.
      /// @param on_click an event handler to respond on lick event.
      /// @return new main menu instance.
      /// @remarks The following table shows the items contained in the menu_items array :
      /// | Position | menu item          |
      /// |----------|--------------------|
      /// | 0        | file               |
      /// | 1        | file new           |
      /// | 2        | file open          |
      /// | 3        | file separator1    |
      /// | 4        | file save          |
      /// | 5        | file save_as       |
      /// | 6        | file separator2    |
      /// | 7        | file print         |
      /// | 8        | file print_preview |
      /// | 9        | file separator3    |
      /// | 10       | file exit          |
      /// | 11       | edit               |
      /// | 12       | edit undo          |
      /// | 13       | edit redo          |
      /// | 14       | edit separator1    |
      /// | 15       | edit cut           |
      /// | 16       | edit copy          |
      /// | 17       | edit paste         |
      /// | 18       | edit separator2    |
      /// | 19       | edit select_all    |
      /// | 20       | tools              |
      /// | 21       | tools customize    |
      /// | 22       | tools options      |
      /// | 23       | help               |
      /// | 24       | help contents      |
      /// | 25       | help index         |
      /// | 26       | help search        |
      /// | 27       | help separator1    |
      /// | 28       | help about         |
      static std::unique_ptr<xtd::forms::main_menu> create_standard_items(std::vector<std::unique_ptr<menu_item>>& menu_items, const xtd::ustring& theme, const xtd::event_handler& on_click);
      /// @brief A factory to create a main menu with specified theme, image size and on click event handler.
      /// @param menu_items an array xtd::forms::menu_item which will contain the created menu items.
      /// @param theme The theme of menu item image.
      /// @param image_size A xtd::drawing::size that represent the menu item image size.
      /// @param on_click an event handler to respond on lick event.
      /// @return new main menu instance.
      /// @remarks The following table shows the items contained in the menu_items array :
      /// | Position | menu item          |
      /// |----------|--------------------|
      /// | 0        | file               |
      /// | 1        | file new           |
      /// | 2        | file open          |
      /// | 3        | file separator1    |
      /// | 4        | file save          |
      /// | 5        | file save_as       |
      /// | 6        | file separator2    |
      /// | 7        | file print         |
      /// | 8        | file print_preview |
      /// | 9        | file separator3    |
      /// | 10       | file exit          |
      /// | 11       | edit               |
      /// | 12       | edit undo          |
      /// | 13       | edit redo          |
      /// | 14       | edit separator1    |
      /// | 15       | edit cut           |
      /// | 16       | edit copy          |
      /// | 17       | edit paste         |
      /// | 18       | edit separator2    |
      /// | 19       | edit select_all    |
      /// | 20       | tools              |
      /// | 21       | tools customize    |
      /// | 22       | tools options      |
      /// | 23       | help               |
      /// | 24       | help contents      |
      /// | 25       | help index         |
      /// | 26       | help search        |
      /// | 27       | help separator1    |
      /// | 28       | help about         |
      static std::unique_ptr<xtd::forms::main_menu> create_standard_items(std::vector<std::unique_ptr<menu_item>>& menu_items, const xtd::ustring& theme, const xtd::drawing::size& size, const xtd::event_handler& on_click);
      /// @brief A factory to create a main menu with specified theme, image size and on click event handler.
      /// @param menu_items an array xtd::forms::menu_item which will contain the created menu items.
      /// @param theme The theme of menu item image.
      /// @param image_size A xtd::drawing::size that represent the menu item image size.
      /// @param on_click an event handler to respond on lick event.
      /// @return new main menu instance.
      /// @remarks The following table shows the items contained in the menu_items array :
      /// | Position | menu item          |
      /// |----------|--------------------|
      /// | 0        | file               |
      /// | 1        | file new           |
      /// | 2        | file open          |
      /// | 3        | file separator1    |
      /// | 4        | file save          |
      /// | 5        | file save_as       |
      /// | 6        | file separator2    |
      /// | 7        | file print         |
      /// | 8        | file print_preview |
      /// | 9        | file separator3    |
      /// | 10       | file exit          |
      /// | 11       | edit               |
      /// | 12       | edit undo          |
      /// | 13       | edit redo          |
      /// | 14       | edit separator1    |
      /// | 15       | edit cut           |
      /// | 16       | edit copy          |
      /// | 17       | edit paste         |
      /// | 18       | edit separator2    |
      /// | 19       | edit select_all    |
      /// | 20       | tools              |
      /// | 21       | tools customize    |
      /// | 22       | tools options      |
      /// | 23       | help               |
      /// | 24       | help contents      |
      /// | 25       | help index         |
      /// | 26       | help search        |
      /// | 27       | help separator1    |
      /// | 28       | help about         |
      static std::unique_ptr<xtd::forms::main_menu> create_standard_items(std::vector<std::unique_ptr<menu_item>>& menu_items, const xtd::forms::theme_images& theme, const xtd::drawing::size& size, const xtd::event_handler& on_click);
      
      /// @cond
      template<typename on_click_type>
      static std::unique_ptr<xtd::forms::main_menu> create_standard_items(std::vector<std::unique_ptr<menu_item>>& menu_items, on_click_type on_click) {return create_standard_items(menu_items, xtd::event_handler(on_click));}
      template<typename on_click_type>
      static std::unique_ptr<xtd::forms::main_menu> create_standard_items(std::vector<std::unique_ptr<menu_item>>& menu_items, const xtd::drawing::size& size, on_click_type on_click) {return create_standard_items(menu_items, size, xtd::event_handler(on_click));}
      template<typename on_click_type>
      static std::unique_ptr<xtd::forms::main_menu> create_standard_items(std::vector<std::unique_ptr<menu_item>>& menu_items, const xtd::ustring& theme, on_click_type on_click) {return create_standard_items(menu_items, theme, xtd::event_handler(on_click));}
      template<typename on_click_type>
      static std::unique_ptr<xtd::forms::main_menu> create_standard_items(std::vector<std::unique_ptr<menu_item>>& menu_items, const xtd::ustring& theme, const xtd::drawing::size& size, on_click_type on_click) {return create_standard_items(menu_items, theme, size, xtd::event_handler(on_click));}
      template<typename on_click_type>
      static std::unique_ptr<xtd::forms::main_menu> create_standard_items(std::vector<std::unique_ptr<menu_item>>& menu_items, const xtd::forms::theme_images& theme, const xtd::drawing::size& size, on_click_type on_click) {return create_standard_items(menu_items, theme, size, xtd::event_handler(on_click));}
      /// @endcond
      
    protected:
      intptr_t create_menu_handle() override;
      void destroy_menu_handle(intptr_t handle) override;
      void on_item_added(size_t pos, menu_item_ref item) override;
      void on_item_removed(size_t pos, menu_item_ref item) override;
      
    private:
      friend class form;
      void wm_click(message& message);
    };
  }
}

