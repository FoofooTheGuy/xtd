/// @file
/// @brief Contains xtd::forms::month_calendar control.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <chrono>
#include "control.h"
#include "day.h"
#include "selection_range.h"
#include "date_range_event_handler.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a control that displays a month calendar.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrates the use of month_calendar control.
    /// @include month_calendar.cpp
    /// @remarks The xtd::forms::month_calendar control allows the user to select a date using a visual display. You can limit the date and times that can be selected by setting the xtd::forms::month_calendar::min_date and xtd::forms::month_calendar::max_date properties.
    /// @remarks You can change the look of the calendar portion of the control by setting the xtd::forms::month_calendar::fore_color, xtd::forms::month_calendar::font, xtd::forms::month_calendar::title_back_color, xtd::forms::month_calendar::title_fore_color, xtd::forms::month_calendar::trailing_fore_color, and xtd::forms::month_calendar::back_color properties.
    /// @note The xtd::forms::month_calendar control only supports Gregorian calendars.
    /// @remarks The xtd::forms::month_calendar control is drawn by the operating system, so the xtd::forms::month_calendar::paint event is never raised. If you need to provide a customized look to the xtd::forms::month_calendar control, you should override the xtd::forms::month_calendar::on_print method, call the base implementation of xtd::forms::control::on_print, and then perform custom painting.
    /// @remarks If you need custom date formatting and a selection limited to just one date, you might consider using a xtd::forms::month_calendar::date_time_picker control instead of a xtd::forms::month_calendar. Using the xtd::forms::month_calendar::date_time_picker eliminates much of the need for validating date/time values.
    class forms_export_ month_calendar : public control {
    public:
      /// @name Constructors
      /// @{
      /// @brief Initializes a new instance of the month_calendar class.
      /// @par Examples
      /// The following code example demonstrates the use of month_calendar control.
      /// @include month_calendar.cpp
      /// @remarks The xtd::forms::month_calendar constructor creates a new xtd::forms::month_calendar.
      month_calendar();
      /// @}
      
      /// @name Properties
      /// @{
      /// @brief Gets the array of xtd::date_time objects that determines which annual days are displayed in bold.
      /// @return An array of xtd::date_time objects.
      /// @remarks Using this property, you can assign an array of annual bold dates. When you assign an array of dates, the existing dates are first cleared.
      std::vector<xtd::date_time> annually_bolded_dates() const;
      /// @brief Sets the array of xtd::date_time objects that determines which annual days are displayed in bold.
      /// @param value An array of xtd::date_time objects.
      /// @return Current month_calendar.
      /// @remarks Using this property, you can assign an array of bold dates. When you assign an array of dates, the existing dates are first cleared.
      month_calendar& annually_bolded_dates(const std::vector<xtd::date_time>& value);

      /// @brief Gets the array of xtd::date_time bjects that determines which nonrecurring dates are displayed in bold.
      /// @return An array of xtd::date_time objects.
      /// @remarks Using this property, you can assign an array of annual bold dates. When you assign an array of dates, the existing dates are first cleared.
      std::vector<xtd::date_time> bolded_dates() const;
      /// @brief Sets the array of xtd::date_time bjects that determines which nonrecurring dates are displayed in bold.
      /// @param value An array of xtd::date_time objects.
      /// @return Current month_calendar.
      /// @remarks Using this property, you can assign an array of bold dates. When you assign an array of dates, the existing dates are first cleared.
      month_calendar& bolded_dates(const std::vector<xtd::date_time>& value);

      /// @brief Gets the number of columns and rows of months displayed.
      /// @return A xtd::drawing::size with the number of columns and rows to use to display the calendar.
      /// @remarks Only one calendar year is displayed at a time, and the maximum number of months that can be displayed is 12. Valid combinations of columns and rows make a maximum product of 12; for values greater than 12, the display is modified on a best-fit basis.
      const xtd::drawing::size& calendar_dimensions() const;
      /// @brief Sets the number of columns and rows of months displayed.
      /// @param value A xtd::drawing::size with the number of columns and rows to use to display the calendar.
      /// @return Current month_calendar.
      /// @remarks Only one calendar year is displayed at a time, and the maximum number of months that can be displayed is 12. Valid combinations of columns and rows make a maximum product of 12; for values greater than 12, the display is modified on a best-fit basis.
      month_calendar& calendar_dimensions(const xtd::drawing::size& value);

      drawing::size default_size() const override {return {240, 162};}
      
      /// @brief Gets the first day of the week as displayed in the month calendar.
      /// @return One of the xtd::forms::day values. The default is td::forms::day::default_day.
      xtd::forms::day first_day_of_week() const;
      /// @brief Sets the first day of the week as displayed in the month calendar.
      /// @param value One of the xtd::forms::day values. The default is td::forms::day::default_day.
      /// @return Current month_calendar.
      month_calendar& first_day_of_week(xtd::forms::day value);
      
      /// @brief Gets the maximum date that can be selected in the control.
      /// @return The maximum date that can be selected in the control.
      date_time max_date() const;
      /// @brief Sets the maximum date that can be selected in the control.
      /// @param value The maximum date that can be selected in the control.
      /// @return Current month_calendar.
      month_calendar& max_date(date_time value);
      
      /// @brief Gets the maximum number of days that can be selected in a month calendar control.
      /// @return The maximum number of days that you can select. The default is 7.
      /// @exception xtd::argument_exception The value is less than 1.
      /// @remarks Setting this property does not effect the current selection range.
      /// @remarks It is important to remember that the xtd::forms::month_calendar::max_selection_count property represents the number of days in the selection, not the difference between xtd::forms::month_calendar::selection_start and xtd::forms::month_calendar::selection_end. For example, if xtd::forms::month_calendar::max_selection_count is 7 (the default), xtd::forms::month_calendar::selection_start and xtd::forms::month_calendar::selection_end can be no more than six days apart.
      uint32_t max_selection_count() const;
      /// @brief Sets the maximum number of days that can be selected in a month calendar control.
      /// @param value The maximum number of days that you can select. The default is 7.
      /// @return Current month_calendar.
      /// @exception xtd::argument_exception The value is less than 1.
      /// @remarks Setting this property does not effect the current selection range.
      /// @remarks It is important to remember that the xtd::forms::month_calendar::max_selection_count property represents the number of days in the selection, not the difference between xtd::forms::month_calendar::selection_start and xtd::forms::month_calendar::selection_end. For example, if xtd::forms::month_calendar::max_selection_count is 7 (the default), xtd::forms::month_calendar::selection_start and xtd::forms::month_calendar::selection_end can be no more than six days apart.
      month_calendar& max_selection_count(uint32_t value);
      
      /// @brief Gets the minimum date that can be selected in the control.
      /// @return The minimum date that can be selected in the control.
      date_time min_date() const;
      /// @brief Sets the minimum date that can be selected in the control.
      /// @param value The minimum date that can be selected in the control.
      /// @return Current month_calendar.
      month_calendar& min_date(date_time value);
      
      /// @brief Gets the array of xtd::date_time objects that determine which monthly days to bold.
      /// @return An array of xtd::date_time objects.
      /// @remarks Using this property, you can assign an array of annual bold dates. When you assign an array of dates, the existing dates are first cleared.
      std::vector<xtd::date_time> monthly_bolded_dates() const;
      /// @brief Sets the array of xtd::date_time objects that determine which monthly days to bold.
      /// @param value An array of xtd::date_time objects.
      /// @return Current month_calendar.
      /// @remarks Using this property, you can assign an array of bold dates. When you assign an array of dates, the existing dates are first cleared.
      month_calendar& monthly_bolded_dates(const std::vector<xtd::date_time>& value);
      
      /// @brief Gets the end date of the selected range of dates.
      /// @return A xtd::date_time indicating the last date in the selection range.
      /// @remarks If you set the value of the xtd::forms::month_calendar::selection_end property to a date that is earlier than the current value of the xtd::forms::month_calendar::selection_start property, xtd::forms::month_calendar::selection_start is automatically set equal to xtd::forms::month_calendar::selection_end.
      /// @remarks If you set a date in xtd::forms::month_calendar::selection_end that causes the selection to exceed the number of days specified by the xtd::forms::month_calendar::max_selection_count property, the value of xtd::forms::month_calendar::selection_start is adjusted; xtd::forms::month_calendar::selection_start is automatically set so that the number of days selected is equal to xtd::forms::month_calendar::max_selection_count.
      /// @note xtd::forms::month_calendar::max_selection_count represents the number of days in the selection, not the difference between xtd::forms::month_calendar::selection_start and xtd::forms::month_calendar::selection_end. For example, if xtd::forms::month_calendar::max_selection_count is 7 (the default), then xtd::forms::month_calendar::selection_start and xtd::forms::month_calendar::selection_end can be no more than six days apart.
      /// @note Setting the xtd::forms::month_calendar::selection_range for a xtd::forms::month_calendar control that has visual styles enabled will result in the selection range not painting correctly on the control.
      date_time selection_end() const;
      /// @brief Sets the end date of the selected range of dates.
      /// @param value A xtd::date_time indicating the last date in the selection range.
      /// @return Current month_calendar.
      /// @remarks If you set the value of the xtd::forms::month_calendar::selection_end property to a date that is earlier than the current value of the xtd::forms::month_calendar::selection_start property, xtd::forms::month_calendar::selection_start is automatically set equal to xtd::forms::month_calendar::selection_end.
      /// @remarks If you set a date in xtd::forms::month_calendar::selection_end that causes the selection to exceed the number of days specified by the xtd::forms::month_calendar::max_selection_count property, the value of xtd::forms::month_calendar::selection_start is adjusted; xtd::forms::month_calendar::selection_start is automatically set so that the number of days selected is equal to xtd::forms::month_calendar::max_selection_count.
      /// @note xtd::forms::month_calendar::max_selection_count represents the number of days in the selection, not the difference between xtd::forms::month_calendar::selection_start and xtd::forms::month_calendar::selection_end. For example, if xtd::forms::month_calendar::max_selection_count is 7 (the default), then xtd::forms::month_calendar::selection_start and xtd::forms::month_calendar::selection_end can be no more than six days apart.
      /// @note Setting the xtd::forms::month_calendar::selection_range for a xtd::forms::month_calendar control that has visual styles enabled will result in the selection range not painting correctly on the control.
      month_calendar& selection_end(date_time value);

      /// @brief Gets the selected range of dates for a month calendar control.
      /// @return A xtd::forms::selection_range with the start and end dates of the selected range.
      /// @remarks Setting this property is functionally equivalent to using the xtd::forms::month_calendar::set_selection_range method. You can set the start and end dates separately by setting either the xtd::forms::month_calendar::selection_start or xtd::forms::month_calendar::selection_end properties. You cannot change the start and end dates by setting the xtd::forms::selection_range::start or xtd::forms::selection_range::end property values of the xtd::forms::month_calendar::selection_range property. You should use xtd::forms::month_calendar::selection_start, xtd::forms::month_calendar::selection_end, or xtd::forms::month_calendar::set_selection_range.
      /// @remarks If the Start property value of the xtd::forms::month_calendar::selection_range is greater than its xtd::forms::selection_rande::end property value, the dates are swapped; the xtd::forms::selection_range::end property value becomes the starting date, and xtd::forms::selection_range::start property value becomes the end date.
      forms::selection_range selection_range() const;
      /// @brief Sets the selected range of dates for a month calendar control.
      /// @param value A xtd::forms::selection_range with the start and end dates of the selected range.
      /// @return Current month_calendar.
      /// @remarks Setting this property is functionally equivalent to using the xtd::forms::month_calendar::set_selection_range method. You can set the start and end dates separately by setting either the xtd::forms::month_calendar::selection_start or xtd::forms::month_calendar::selection_end properties. You cannot change the start and end dates by setting the xtd::forms::selection_range::start or xtd::forms::selection_range::end property values of the xtd::forms::month_calendar::selection_range property. You should use xtd::forms::month_calendar::selection_start, xtd::forms::month_calendar::selection_end, or xtd::forms::month_calendar::set_selection_range.
      /// @remarks If the Start property value of the xtd::forms::month_calendar::selection_range is greater than its xtd::forms::selection_rande::end property value, the dates are swapped; the xtd::forms::selection_range::end property value becomes the starting date, and xtd::forms::selection_range::start property value becomes the end date.
      month_calendar& selection_range(const forms::selection_range& value);
      
      /// @brief Gets the start date of the selected range of dates.
      /// @return A xtd::date_time indicating the first date in the selection range.
      /// @remarks If you set the value of the xtd::forms::month_calendar::selection_start property to a date that is later than the current value of the xtd::forms::month_calendar::selection_end property, xtd::forms::month_calendar::selection_end is automatically set equal to xtd::forms::month_calendar::selection_start.
      /// @remarks If you set a date in xtd::forms::month_calendar::selection_start that causes the selection to exceed the number of days specified by the xtd::forms::month_calendar::max_selection_count property, the value of xtd::forms::month_calendar::selection_end is adjusted; xtd::forms::month_calendar::selection_end is automatically set so that the number of days selected is equal to xtd::forms::month_calendar::max_selection_count.
      /// @note xtd::forms::month_calendar::max_selection_count represents the number of days in the selection, not the difference between xtd::forms::month_calendar::selection_start and xtd::forms::month_calendar::selection_end. For example, if xtd::forms::month_calendar::max_selection_count is 7 (the default), then xtd::forms::month_calendar::selection_start and xtd::forms::month_calendar::selection_end can be no more than six days apart.
      /// @note Setting the xtd::forms::month_calendar::selection_range for a xtd::forms::month_calendar control that has visual styles enabled will result in the selection range not painting correctly on the control.
      date_time selection_start() const;
      /// @brief Sets the start date of the selected range of dates.
      /// @param value A xtd::date_time indicating the first date in the selection range.
      /// @return Current month_calendar.
      /// @remarks If you set the value of the xtd::forms::month_calendar::selection_start property to a date that is later than the current value of the xtd::forms::month_calendar::selection_end property, xtd::forms::month_calendar::selection_end is automatically set equal to xtd::forms::month_calendar::selection_start.
      /// @remarks If you set a date in xtd::forms::month_calendar::selection_start that causes the selection to exceed the number of days specified by the xtd::forms::month_calendar::max_selection_count property, the value of xtd::forms::month_calendar::selection_end is adjusted; xtd::forms::month_calendar::selection_end is automatically set so that the number of days selected is equal to xtd::forms::month_calendar::max_selection_count.
      /// @note xtd::forms::month_calendar::max_selection_count represents the number of days in the selection, not the difference between xtd::forms::month_calendar::selection_start and xtd::forms::month_calendar::selection_end. For example, if xtd::forms::month_calendar::max_selection_count is 7 (the default), then xtd::forms::month_calendar::selection_start and xtd::forms::month_calendar::selection_end can be no more than six days apart.
      /// @note Setting the xtd::forms::month_calendar::selection_range for a xtd::forms::month_calendar control that has visual styles enabled will result in the selection range not painting correctly on the control.
      month_calendar& selection_start(date_time value);
      
      /// @brief Gets a value indicating whether the date represented by the xtd::today_date property is displayed at the bottom of the control.
      /// @return true if today's date is displayed; otherwise, false. The default is true.
      /// @remarks The date is displayed in the format specified by the system settings for the short date format.
      bool show_today() const;
      /// @brief Sets a value indicating whether the date represented by the xtd::today_date property is displayed at the bottom of the control.
      /// @param value true if today's date is displayed; otherwise, false. The default is true.
      /// @return Current month_calendar.
      /// @remarks The date is displayed in the format specified by the system settings for the short date format.
      month_calendar& show_today(bool value);
      
      /// @brief Gets a value indicating whether today's date is identified with a circle or a square.
      /// @return true if today's date is identified with a circle or a square; otherwise, false. The default is true.
      /// @remarks If xtd::forms::month_calendar::show_today_circle is true, and visual styles are enabled and supported on the computer running the application, today's date will be enclosed in a square, otherwise today's date will be circled.
      bool show_today_circle() const;
      /// @brief Sets a value indicating whether today's date is identified with a circle or a square.
      /// @param value true if today's date is identified with a circle or a square; otherwise, false. The default is true.
      /// @return Current month_calendar.
      /// @remarks If xtd::forms::month_calendar::show_today_circle is true, and visual styles are enabled and supported on the computer running the application, today's date will be enclosed in a square, otherwise today's date will be circled.
      month_calendar& show_today_circle(bool value);

      /// @brief Gets a value indicating whether the month calendar control displays week numbers (1-52) to the left of each row of days.
      /// @return true if the week numbers are displayed; otherwise, false. The default is false.
      bool show_week_numbers() const;
      /// @brief Sets a value indicating whether the month calendar control displays week numbers (1-52) to the left of each row of days.
      /// @param value true if the week numbers are displayed; otherwise, false. The default is false.
      /// @return Current month_calendar.
      month_calendar& show_week_numbers(bool value);
      
      /// @brief Gets the minimum size to display one month of the calendar.
      /// @return The size, in pixels, necessary to fully display one month in the calendar.
      /// @remarks The size information is presented in the form of the xtd::forms::control::width and xtd::forms::control::height members, representing the minimum width and height required to display one month in the control. The minimum required window size for a month calendar control depends on the currently selected font.
      xtd::drawing::size single_month_size() const;
      
      /// @brief Gets a value indicating the background color of the title area of the calendar.
      /// @return A xtd::drawing::color. The default is the system color for active captions.
      /// @remarks The font color of the days-of-the-week text depends on the xtd::forms::month_calendar::title_back_color property. Setting the xtd::forms::month_calendar::title_back_color equal to the xtd::forms::month_control::back_color for the main display area of the calendar causes the days-of-the-week text to become unreadable.
      xtd::drawing::color title_back_color() const;
      /// @brief Sets a value indicating the background color of the title area of the calendar.
      /// @param value A xtd::drawing::color. The default is the system color for active captions.
      /// @return Current month_calendar.
      /// @remarks The font color of the days-of-the-week text depends on the xtd::forms::month_calendar::title_back_color property. Setting the xtd::forms::month_calendar::title_back_color equal to the xtd::forms::control::back_color for the main display area of the calendar causes the days-of-the-week text to become unreadable.
      month_calendar& title_back_color(const xtd::drawing::color& value);
      
      /// @brief Gets a value indicating the foreground color of the title area of the calendar.
      /// @return A xtd::drawing::color. The default is the system color for active caption text.
      xtd::drawing::color title_fore_color() const;
      /// @brief Sets a value indicating the foreground color of the title area of the calendar.
      /// @param value A xtd::drawing::color. The default is the system color for active caption text.
      /// @return Current month_calendar.
      month_calendar& title_fore_color(const xtd::drawing::color& value);
      
      /// @brief Gets the value that is used by xtd::forms::month_calendar as today's date.
      /// @return A xtd::date_time representing today's date. The default value is the current system date.
      /// @remarks By default, the xtd::forms::month_calendar::today_date property returns the current system date, and the xtd::forms::month_calendar::today_date_set property is false. Setting the TodayDate property sets the xtd::forms::month_calendar::today_date_set property to true and, from that point, the value returned by the xtd::forms::month_calendar::roday_date property is the one the user sets.
      const xtd::date_time& today_date() const;
      /// @brief Sets the value that is used by xtd::forms::month_calendar as today's date.
      /// @param value A xtd::date_time representing today's date. The default value is the current system date.
      /// @return Current month_calendar.
      /// @remarks By default, the xtd::forms::month_calendar::today_date property returns the current system date, and the xtd::forms::month_calendar::today_date_set property is false. Setting the TodayDate property sets the xtd::forms::month_calendar::today_date_set property to true and, from that point, the value returned by the xtd::forms::month_calendar::roday_date property is the one the user sets.
      month_calendar& today_date(const xtd::date_time& value);

      /// @brief Gets a value indicating whether the xtd::forms::month_calendar::today_date property has been explicitly set.
      /// @return true if the value for the xtd::forms::month_calendar::today_date property has been explicitly set; otherwise, false. The default is false.
      bool today_date_set() const;
      
      /// @brief Gets a value indicating the color of days in months that are not fully displayed in the control.
      /// @return A xtd::drawing::color. The default is the system color for gray text.
      /// @remarks When the calendar is displayed, some dates precede and some follow the months that are fully displayed. Using the xtd::forms::month_calendar::trailing_fore_color property, you can modify the color of the text for those dates.
      xtd::drawing::color trailing_fore_color() const;
      /// @brief Sets a value indicating the color of days in months that are not fully displayed in the control.
      /// @param value A xtd::drawing::color. The default is the system color for gray text.
      /// @return Current month_calendar.
      /// @remarks When the calendar is displayed, some dates precede and some follow the months that are fully displayed. Using the xtd::forms::month_calendar::trailing_fore_color property, you can modify the color of the text for those dates.
      month_calendar& trailing_fore_color(const xtd::drawing::color& value);
      /// @}
      
      /// @name Events
      
      /// @{
      /// @brief Occurs when the date selected in the xtd::forms::month_calendar changes.
      /// @ingroup events
      /// @remarks The xtd::forms::month_calendar::date_changed event occurs during any date selection, whether by mouse, keyboard, or code. The xtd::forms::month_calendar::date_selected event is similar, but it occurs only at the end of a date selection made using the mouse.
      /// @remarks For more information about handling events, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_handle_and_raise_events.md">Handling and Raising Events</a>.
      event<month_calendar, xtd::forms::date_range_event_handler> date_changed;
      
      /// @brief Occurs when the user makes an explicit date selection using the mouse.
      /// @ingroup events
      /// @remarks This event is similar to the xtd::forms::month_calendar::date_changed event, but it occurs at the end of a date selection made using the mouse. The xtd::forms::month_calendar::date_changed event occurs during any date selection, whether by mouse, keyboard, or code.
      /// @remarks For more information about handling events, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_handle_and_raise_events.md">Handling and Raising Events</a>.
      event<month_calendar, xtd::forms::date_range_event_handler> date_selected;
      /// @}

      /// @name Protected methods
      
      /// @{
      /// @brief Adds a day that is displayed in bold on an annual basis in the month calendar.
      /// @param date The date to be displayed in bold.
      /// @remarks You must call the xtd::forms::month_calendar::update_bolded_dates method afterward to update the display.
      /// @remarks To add multiple dates in a single assignment, you can assign an array of xtd::date_time objects to the xtd::forms::month_calendar::annually_bolded_dates property.
      void add_annually_bolded_date(const xtd::date_time& date);

      /// @brief Adds a day to be displayed in bold in the month calendar.
      /// @param date The date to be displayed in bold.
      /// @remarks You must call the xtd::forms::month_calendar::update_bolded_dates method afterward to update the display.
      /// @remarks To add multiple dates in a single assignment, you can assign an array of xtd::date_time objects to the xtd::forms::month_calendar::bolded_dates property.
      void add_bolded_date(const xtd::date_time& date);

      /// @brief Adds a day that is displayed in bold on a monthly basis in the month calendar.
      /// @param date The date to be displayed in bold.
      /// @remarks You must call the xtd::forms::month_calendar::update_bolded_dates method afterward to update the display.
      /// @remarks To add multiple dates in a single assignment, you can assign an array of xtd::date_time objects to the xtd::forms::month_calendar::monthly_bolded_dates property.
      void add_monthly_bolded_date(const xtd::date_time& date);
      
      

      /// @brief Repaints the bold dates to reflect the dates set in the lists of bold dates.
      /// @remarks Use the xtd::forms::month_calendar::update_bolded_dates method to reflect changes made to xtd::forms::month_calendar::annually_bolded_dates, xtd::forms::month_calendar::monthly_bolded_dates, or xtd::forms::month_calendar::bolded_dates properties, either directly by modifying elements of the array or by using the add or remove methods provided to modify the date lists.
      void update_bolded_dates();
      /// @}

    protected:
      /// @name Protected methods
      
      /// @{
      forms::create_params create_params() const override;
      drawing::color default_back_color() const override {return xtd::forms::theme_colors::current_theme().window();}
      drawing::color default_fore_color() const override {return xtd::forms::theme_colors::current_theme().window_text();}
      
      /// @brief Raises the xtd::forms::month_calendar::date_changed event.
      /// @param e A xtd::forms::date_range_event_args that contains the event data.
      /// @remarks Raising an event invokes the event handler through a delegate. For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_handle_and_raise_events.md">Handling and Raising Events</a>.
      /// @remarks The xtd::forms::month_calendar::on_date_changed method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      /// @par Notes to Inherotors
      /// When overriding xtd::forms::month_calendar::on_date_changed in a derived class, be sure to call the base class' xtd::forms::month_calendar::on_date_changed method so that registered delegates receive the event.
      virtual void on_date_changed(const xtd::forms::date_range_event_args& e);
      
      /// @brief Raises the xtd::forms::month_calendar::date_selected event.
      /// @param e A xtd::forms::date_range_event_args that contains the event data.
      /// @remarks Raising an event invokes the event handler through a delegate. For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_handle_and_raise_events.md">Handling and Raising Events</a>.
      /// @remarks The xtd::forms::month_calendar::on_date_selected method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      /// @par Notes to Inherotors
      /// When overriding xtd::forms::month_calendar::on_date_selected in a derived class, be sure to call the base class' xtd::forms::month_calendar::on_date_selected method so that registered delegates receive the event.
      virtual void on_date_selected(const xtd::forms::date_range_event_args& e);
      
      void on_handle_created(const event_args& e) override;
      void wnd_proc(message& message) override;
      /// @}
      
    private:
      void wm_notify(message& message);
      void wm_date_selected(message& message);
      void wm_date_changed(message& message);
      void wm_view_changed(message& message);
      
      struct data {
        std::vector<xtd::date_time> annually_bolded_dates;
        std::vector<xtd::date_time> bolded_dates;
        xtd::drawing::size calendar_dimensions = {1, 1};
        xtd::forms::day first_day_of_week = xtd::forms::day::default_day;
        date_time min_date = date_time::min_value;
        date_time max_date = date_time::max_value;
        uint32_t max_selection_count = 7;
        std::vector<xtd::date_time> monthly_bolded_dates;
        date_time selection_start = date_time::now();
        date_time selection_end = date_time::now();
        mutable xtd::drawing::size single_month_size = {225, 143};
        bool show_today = true;
        bool show_today_circle = true;
        bool show_week_numbers = false;
        std::optional<xtd::drawing::color> title_back_color;
        std::optional<xtd::drawing::color> title_fore_color;
        xtd::date_time today_date = xtd::date_time::now();
        bool today_date_set = false;
        std::optional<xtd::drawing::color> trailing_fore_color;
      };
      
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
