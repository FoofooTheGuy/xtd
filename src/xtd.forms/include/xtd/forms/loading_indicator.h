/// @file
/// @brief Contains xtd::forms::loading_indicator control.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "control.h"
#include "content_alignment.h"
#include "loading_indicator_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a loading indicator control.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrates the use of loading indicator control.
    /// @include loading_indicator.cpp
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
    ///     <td>@image html control_loading_indicator_w.png</td>
    ///     <td>@image html control_loading_indicator_m.png</td>
    ///     <td>@image html control_loading_indicator_g.png</td>
    ///   </tr>
    ///   <tr>
    ///     <th>Dark</th>
    ///     <td>@image html control_loading_indicator_wd.png</td>
    ///     <td>@image html control_loading_indicator_md.png</td>
    ///     <td>@image html control_loading_indicator_gd.png</td>
    ///   </tr>
    /// </table>
    /// @par Examples
    /// The following code example demonstrates the use of loading_indicator control.
    /// @include hello_world_loading_indicator.cpp
    class forms_export_ loading_indicator : public control {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initialize a new instance of loading_indicator class.
      loading_indicator();
      /// @}
      
      /// @name Propeties
      
      /// @{
      /// @brief Gets the flat style appearance of the loading_indicator control.
      /// @return One of the xtd::forms::loading_indicator_style values. The default value is xtd::forms::loading_indicator_style::standard.
      /// @remarks When the loading_indicator_style property is set to xtd::forms::loading_indicator_style::system, any values assigned to the image_list, image, image_index, and image_align properties are ignored. In addition, the text_align property ignores any property values that are not vertical property settings. Horizontally aligned settings of the text_align property are aligned to the top of the control. For example, if you set the text_align property to content_alignment::top_center, content_alignment::middle_center, or content_alignment::bottom_center, when the loading_indicator_style property is set to xtd::forms::loading_indicator_style::system, the text in the loading_indicator control will be aligned to the top and center locations within the bounds of the control.
      virtual xtd::forms::loading_indicator_style loading_indicator_style() const {return loading_indicator_style_;}
      /// @brief Sets the flat style appearance of the loading_indicator control.
      /// @param loading_indicator_style One of the xtd::forms::loading_indicator_style values. The default value is xtd::forms::loading_indicator_style::standard.
      /// @return Current loading_indicator instance.
      /// @remarks When the loading_indicator_style property is set to xtd::forms::loading_indicator_style::system, any values assigned to the image_list, image, image_index, and image_align properties are ignored. In addition, the text_align property ignores any property values that are not vertical property settings. Horizontally aligned settings of the text_align property are aligned to the top of the control. For example, if you set the text_align property to content_alignment::top_center, content_alignment::middle_center, or content_alignment::bottom_center, when the loading_indicator_style property is set to xtd::forms::loading_indicator_style::system, the text in the loading_indicator control will be aligned to the top and center locations within the bounds of the control.
      virtual xtd::forms::loading_indicator& loading_indicator_style(xtd::forms::loading_indicator_style loading_indicator_style);
      
      /// @brief Returns if the loading indicator animation is started.
      /// @return true if the loading indicator is running; otherwise false.
      bool is_running() const {return is_running_;}
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Starts animation of the loading indicator.
      void start();
      /// @brief Stops animation of the loading indicator.
      void stop();
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      xtd::forms::create_params create_params() const override;
      /// @}

      /// @name Protected method
      
      /// @{
      xtd::drawing::size measure_control() const override;
      void on_handle_created(const event_args& e) override;
      void on_paint(xtd::forms::paint_event_args& e) override;
      /// @}
      
    private:
      void on_timer_tick(object& timer, const xtd::event_args& e);
      
      bool is_running_ = false;
      xtd::forms::loading_indicator_style loading_indicator_style_ = xtd::forms::loading_indicator_style::standard;
      xtd::forms::timer timer_;
      int32_t intervals_ = 8;
      int32_t radius_factor_ = 10;
      int32_t frame_ = 0;
      int32_t interval_ = 150;
    };
  }
}
