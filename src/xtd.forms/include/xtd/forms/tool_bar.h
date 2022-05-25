/// @file
/// @brief Contains xtd::forms::tool_bar container.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <memory>
#include <vector>
#include "button.h"
#include "border_style.h"
#include "context_menu.h"
#include "image_list.h"
#include "panel.h"
#include "tool_bar_appearance.h"
#include "tool_bar_button.h"
#include "tool_bar_button_click_event_handler.h"
#include "tool_bar_text_align.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class form;
    /// @endcond
    
    /// @brief Represents a Windows toolbar.
    /// @code
    /// class forms_export_ tool_bar : public xtd::forms::control
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::forms::component → xtd::forms::control → xtd::forms::tool_bar
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms  menus_and_toolbars
    /// @par Examples
    /// The following code example demonstrates the use of xtd::forms::tool_bar control.
    /// @include tool_bar.cpp
    /// @remarks xtd::forms::tool_bar controls are used to display xtd::forms::tool_bar_button controls that can appear as a standard button, a toggle-style button, or a drop-down style button. You can assign images to the buttons by creating an xtd::forms::image_list, assigning it to the xtd::forms::tool_bar::image_list property of the toolbar, and assigning the image index value to the xtd::forms::tool_bar_button::image_index property each xtd::forms::tool_bar_button. You can then assign text to be displayed underneath or to the right of the image by setting the xtd::forms::tool_bar_button::text property of the xtd::forms::tool_bar_button.
    /// @remarks Set the xtd::forms::tool_bar::appearance property of the toolbar to xtd::forms::tool_bar_appearance::flat to give the toolbar and its buttons a flat appearance. As the mouse pointer moves over the buttons, their appearance changes to three-dimensional. Toolbar buttons can be divided into logical groups by using separators. A separator is a toolbar button with the xtd::forms::tool_bar_button::style property set to xtd::forms::tool_bar_button_style::separator. Button separators appear as lines rather than spaces between the buttons when the toolbar has a flat appearance. If the xtd::forms::tool_bar::appearance property is set to xtd::forms::tool_bar_appearance::normal, the toolbar buttons appear raised and three-dimensional.
    /// @remarks If you specify a value for the xtd::forms::tool_bar::button_size property, all buttons in the tool bar are restricted to the specified size. Otherwise, the buttons adjust their size depending on their content, and the xtd::forms::tool_bar::button_size property returns the initial size of the largest button.
    /// @remarks To create a collection of xtd::forms::tool_bar_button controls to display on the xtd::forms::tool_bar, add the buttons individually by using the xtd::forms::tool_bar::tool_bar_button_collection::push_back or xtd::forms::tool_bar::tool_bar_button_collection::insert methods of the xtd::forms::tool_bar::buttons property.
    class forms_export_ tool_bar : public control {
      class tool_bar_button_control;
      
    public:
      /// @name Alias
      
      /// @{
      /// @brief Represents the base type of the xtd::forms::tool_bar::buttons collection.
      using tool_bar_button_collection = xtd::forms::layout::arranged_element_collection<tool_bar_button_ref>;
      /// @}
      
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::forms::tool_bar class.
      /// @remarks A newly created toolbar control is empty; add xtd::forms::tool_bar_button controls by setting the xtd::forms::tool_bar::buttons property.
      tool_bar();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the value that determines the appearance of a toolbar control and its buttons.
      /// @return One of the xtd::forms::tool_bar_appearance values. The default is xtd::forms::tool_bar::appearance::normal.
      /// @remarks The xtd::forms::tool_bar::appearance property affects the appearance of the buttons assigned to the toolbar. When the appearance is set to xtd::forms::tool_bar_appearance::normal, the toolbar's buttons appear three-dimensional and raised. Set the xtd::forms::tool_bar::appearance property of the toolbar to xtd::forms::tool_bar_ppearance::flat to give the toolbar's buttons a flat appearance. As the mouse pointer moves over the flat buttons, they appear raised and three-dimensional. Separators on a xtd::forms::tool_bar with the xtd::forms::tool_bar::appearance property set to xtd::forms::tool_bar_appearance::flat appear as etched lines rather than spaces between the raised buttons. The flat style buttons give your application a more Web-like look.
      virtual xtd::forms::tool_bar_appearance appearnce() const;
      /// @brief Sets the value that determines the appearance of a toolbar control and its buttons.
      /// @param value One of the xtd::forms::tool_bar_appearance values. The default is xtd::forms::tool_bar::appearance::normal.
      /// @return Current tool_bar instance.
      /// @remarks The xtd::forms::tool_bar::appearance property affects the appearance of the buttons assigned to the toolbar. When the appearance is set to xtd::forms::tool_bar_appearance::normal, the toolbar's buttons appear three-dimensional and raised. Set the xtd::forms::tool_bar::appearance property of the toolbar to xtd::forms::tool_bar_ppearance::flat to give the toolbar's buttons a flat appearance. As the mouse pointer moves over the flat buttons, they appear raised and three-dimensional. Separators on a xtd::forms::tool_bar with the xtd::forms::tool_bar::appearance property set to xtd::forms::tool_bar_appearance::flat appear as etched lines rather than spaces between the raised buttons. The flat style buttons give your application a more Web-like look.
      virtual tool_bar& appearnce(xtd::forms::tool_bar_appearance value);

      /// @brief Gets the border sides for the control.
      /// @return A bitwise combination of the A bitwise combination values. The default is border_style::all.
      virtual forms::border_sides border_sides() const {return data_->border_sides;}
      /// @brief Sets the border sides for the control.
      /// @param border_style A bitwise combination of the border_sides values. The default is border_style::all.
      /// @return Current tool_bar instance.
      virtual tool_bar& border_sides(forms::border_sides border_sides);
      
      /// @brief Gets the border style for the control.
      /// @return One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @remarks The xtd::forms::tool_bar can take on a sunken, three-dimensional appearance when the xtd::forms::tool_bar::border_style property is set to xtd::forms::border_style::fixed_3d. To display a flat thin border around the toolbar control, set the xtd::forms::tool_bar::border_style property to xtd::forms::border_style.fixed_single.
      virtual forms::border_style border_style() const {return data_->border_style.value_or(xtd::forms::border_style::none);}
      /// @brief Sets the border style for the control.
      /// @param value One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @return Current tool_bar instance.
      /// @remarks The xtd::forms::tool_bar can take on a sunken, three-dimensional appearance when the xtd::forms::tool_bar::border_style property is set to xtd::forms::border_style::fixed_3d. To display a flat thin border around the toolbar control, set the xtd::forms::tool_bar::border_style property to xtd::forms::border_style.fixed_single.
      virtual tool_bar& border_style(forms::border_style value);
      /// @brief Reets the border style for the control.
      /// @param value nullptr.
      /// @return Current tool_bar instance.
      /// @remarks The xtd::forms::tool_bar can take on a sunken, three-dimensional appearance when the xtd::forms::tool_bar::border_style property is set to xtd::forms::border_style::fixed_3d. To display a flat thin border around the toolbar control, set the xtd::forms::tool_bar::border_style property to xtd::forms::border_style.fixed_single.
      virtual xtd::forms::tool_bar& border_style(std::nullptr_t value);
        
      /// @brief Gets the collection of xtd::forms::tool_bar_button controls assigned to the toolbar control.
      /// @return A xtd::forms::tool_bar::tool_bar_button_collection that contains a collection of xtd::forms::tool_bar_button controls.
      /// @remarks The xtd::forms::tool_bar::item property is a zero-based indexed collection used to hold all the xtd::forms::tool_bar_button controls assigned to the toolbar. Because the property is read-only, it can not be assigned a collection of toolbar buttons directly. Toolbar item can be added or removed by using the methods inherited from the xtd::forms::tool_bar::tool_bar_button_collection class. Use the xtd::forms::tool_bar::tool_bar_button_collection::push_back method to add individual buttons and the xtd::forms::tool_bar::tool_bar_button_collection::erase method to delete a item. Call the xtd::forms::tool_bar::tool_bar_button_collection::clear method to remove all the buttons from the collection.
      const tool_bar_button_collection& buttons() const;
      /// @brief Gets the collection of xtd::forms::tool_bar_button controls assigned to the toolbar control.
      /// @return A xtd::forms::tool_bar::tool_bar_button_collection that contains a collection of xtd::forms::tool_bar_button controls.
      /// @remarks The xtd::forms::tool_bar::item property is a zero-based indexed collection used to hold all the xtd::forms::tool_bar_button controls assigned to the toolbar. Because the property is read-only, it can not be assigned a collection of toolbar buttons directly. Toolbar item can be added or removed by using the methods inherited from the xtd::forms::tool_bar::tool_bar_button_collection class. Use the xtd::forms::tool_bar::tool_bar_button_collection::push_back method to add individual buttons and the xtd::forms::tool_bar::tool_bar_button_collection::erase method to delete a item. Call the xtd::forms::tool_bar::tool_bar_button_collection::clear method to remove all the buttons from the collection.
      tool_bar_button_collection& buttons();

      /// @brief Gets the size of the buttons on the toolbar control.
      /// @return A xtd::drawing::size object that represents the size of the xtd::forms::tool_bar_button controls on the toolbar. The default size has a width of 24 pixels and a height of 22 pixels, or large enough to accommodate the xtd::drawing::image and text, whichever is greater.
      /// @remarks If the xtd::forms::tool_bar::button_size is not set, it is set to its default. Alternatively, a xtd::forms::tool_bar::size is computed to accommodate the largest xtd::drawing::image and text assigned to the xtd::forms::tool_bar_button controls.
      virtual xtd::drawing::size button_size() const;
      /// @brief Sets the size of the buttons on the toolbar control.
      /// @param value A xtd::drawing::size object that represents the size of the xtd::forms::tool_bar_button controls on the toolbar. The default size has a width of 24 pixels and a height of 22 pixels, or large enough to accommodate the xtd::drawing::image and text, whichever is greater.
      /// @return Current tool_bar instance.
      /// @remarks If the xtd::forms::tool_bar::button_size is not set, it is set to its default. Alternatively, a xtd::forms::tool_bar::size is computed to accommodate the largest xtd::drawing::image and text assigned to the xtd::forms::tool_bar_button controls.
      virtual tool_bar& button_size(const xtd::drawing::size& value);
      /// @brief Resets the size of the buttons on the toolbar control.
      /// @param value nullptr.
      /// @return Current tool_bar instance.
      /// @remarks If the xtd::forms::tool_bar::button_size is not set, it is set to its default. Alternatively, a xtd::forms::tool_bar::size is computed to accommodate the largest xtd::drawing::image and text assigned to the xtd::forms::tool_bar_button controls.
      virtual tool_bar& button_size(std::nullptr_t value);

      xtd::drawing::font default_font() const override;

      drawing::size default_size() const override;

      dock_style dock() const override;
      control& dock(dock_style dock) override;
      
      const xtd::forms::image_list& image_list() const;
      xtd::forms::image_list& image_list();
      tool_bar& image_list(const xtd::forms::image_list& value);
      
      virtual xtd::drawing::size image_size() const;

      virtual bool show_icon() const;
      virtual tool_bar& show_icon(bool value);
      
      virtual bool show_text() const;
      virtual tool_bar& show_text(bool value);
      
      virtual bool show_tool_tips() const;
      virtual tool_bar& show_tool_tips(bool value);
      
      virtual xtd::forms::tool_bar_text_align text_align() const;
      virtual tool_bar& text_align(xtd::forms::tool_bar_text_align value);
      /// @}
      
      /// @name Events
      
      /// @{
      xtd::event<tool_bar, xtd::forms::tool_bar_button_click_event_handler> button_click;
      /// @}
      
    protected:
      /// @name protected methods
      
      /// @{
      void on_button_click(const xtd::forms::tool_bar_button_click_event_args& e);
      /// @}

    protected:
      friend tool_bar_button;
      friend form;
      
      /// @name Protetced properties
      
      /// @{
      virtual bool is_horizontal() const;      
      virtual bool is_system_tool_bar() const;
      virtual tool_bar& is_system_tool_bar(bool value);
      /// @}
      
      /// @name Protetced methods
      
      /// @{
      forms::create_params create_params() const override;
      void on_handle_created(const event_args& e) override;
      void on_handle_destroyed(const event_args& e) override;
      void on_paint(xtd::forms::paint_event_args& e) override;
      void on_resize(const event_args& e) override;
      void wnd_proc(message& message) override;
      /// @}
      
    private:
      void fill();

      void on_item_added(size_t pos, tool_bar_button_ref item);
      void on_item_updated(size_t pos, tool_bar_button_ref item);
      void on_item_removed(size_t pos, tool_bar_button_ref item);

      void resize_stretchable_separtors();
      void update_toolbar_button_control(intptr_t handle, const xtd::ustring& text, const xtd::ustring& tool_tip_text, const xtd::drawing::image& image, bool pushed, bool enabled, bool visible);

      void wm_click(const message& message);
      
      struct data {
        xtd::forms::tool_bar_appearance appearnce = xtd::forms::tool_bar_appearance::normal;
        forms::border_sides border_sides = forms::border_sides::all;
        std::optional<xtd::forms::border_style> border_style;
        std::optional<xtd::drawing::size> button_size;
        xtd::forms::image_list image_list;
        tool_bar_button_collection buttons;
        bool is_system_tool_bar = false;
        dock_style non_system_dock = dock_style::none;
        bool show_icon = true;
        bool show_text = false;
        bool show_tool_tips = false;
        std::vector<std::shared_ptr<xtd::forms::tool_bar::tool_bar_button_control>> stretchable_separators;
        std::vector<std::shared_ptr<xtd::forms::tool_bar::tool_bar_button_control>> tool_bar_buttons;
        std::vector<intptr_t> system_tool_bar_button_handles;
        xtd::forms::tool_bar_text_align text_align = xtd::forms::tool_bar_text_align::underneath;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
