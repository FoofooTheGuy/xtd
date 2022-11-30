/// @file
/// @brief Contains xtd::forms::tab_page container.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "panel.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a single tab page in a tab_control.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
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
    ///     <td>@image html containers_tab_control_w.png</td>
    ///     <td>@image html containers_tab_control_m.png</td>
    ///     <td>@image html containers_tab_control_g.png</td>
    ///   </tr>
    ///   <tr>
    ///     <td>Dark</td>
    ///     <td>@image html containers_tab_control_wd.png</td>
    ///     <td>@image html containers_tab_control_md.png</td>
    ///     <td>@image html containers_tab_control_gd.png</td>
    ///   </tr>
    /// </table>
    /// @par Examples
    /// The following code example demonstrates the use of tab_page container.
    /// @include tab_control.cpp
    /// @par Examples
    /// The following code example demonstrates the use of tab_control and colored tab_page containers.
    /// @include colored_tab_pages.cpp
    class forms_export_ tab_page : public panel {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the tab_page class.
      tab_page() = default;
      /// @}
      
      /// @name Properties
      
      /// @{
      using panel::auto_scroll;
      /// @brief Sets a value indicating whether the container enables the user to scroll to any controls placed outside of its visible boundaries.
      /// @param value true if the container enables auto-scrolling; otherwise, false. The default value is false.
      /// @return Current scrollable_control instance.
      scrollable_control& auto_scroll(bool value) override;
      
      /// @brief Gets the image list index value of the image displayed on the tab_page control.
      /// @return A zero-based index, which represents the image position in an image_list. The default is -1.
      /// @remarks When the image_index or image_list properties are set, the Image property is set to its default value, xtd::drawing::image::empty.
      /// @remarks image_key and image_index are mutually exclusive, meaning if one is set, the other is set to an invalid value and ignored. If you set the image_key property, the image_index property is automatically set to -1. Alternatively, if you set the image_index property, the image_key is automatically set to an empty string ("").
      /// @remarks If the image_list property value is changed to xtd::forms::image_list::empty, the image_index property returns its default value, -1. However, the assigned image_index value is retained internally and used when another image_list object is assigned to the image_list property. If the new image_list assigned to the image_list property has an imageList::_image_collection::size property value that is less than or equal to the value assigned to the image_index property minus one (to account for the collection being a zero-based index), the image_index property value is adjusted to one less than the size property value. For example, consider a tab_page control whose image_list has three images and whose image_index property is set to 2. If a new image_list that has only two images is assigned to the tab_page, the image_index value changes to 1.
      virtual int32_t image_index() const noexcept;
      /// @brief Sets the image list index value of the image displayed on the tab_page control.
      /// @return A zero-based index, which represents the image position in an image_list. The default is -1.
      /// @remarks When the image_index or image_list properties are set, the Image property is set to its default value, xtd::drawing::image::empty.
      /// @remarks image_key and image_index are mutually exclusive, meaning if one is set, the other is set to an invalid value and ignored. If you set the image_key property, the image_index property is automatically set to -1. Alternatively, if you set the image_index property, the image_key is automatically set to an empty string ("").
      /// @remarks If the image_list property value is changed to xtd::forms::image_list::empty, the image_index property returns its default value, -1. However, the assigned image_index value is retained internally and used when another image_list object is assigned to the image_list property. If the new image_list assigned to the image_list property has an imageList::_image_collection::size property value that is less than or equal to the value assigned to the image_index property minus one (to account for the collection being a zero-based index), the image_index property value is adjusted to one less than the size property value. For example, consider a tab_page control whose image_list has three images and whose image_index property is set to 2. If a new image_list that has only two images is assigned to the tab_page, the image_index value changes to 1.
      virtual tab_page& image_index(int32_t value);
      
      using panel::text;
      /// @brief Sets the text associated with this control.
      /// @param text The text associated with this control.
      /// @return Current control instance.
      control& text(const xtd::ustring& text) override;
      /// @}
      
      /// @name Metthods
      
      /// @{
      void destroy_handle() override;
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      forms::create_params create_params() const noexcept override;
      /// @}

      /// @name Protected methods
      
      /// @{
      void on_handle_created(const event_args& e) override;
      /// @}
      
    private:
      struct data {
        int32_t image_index = -1;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
