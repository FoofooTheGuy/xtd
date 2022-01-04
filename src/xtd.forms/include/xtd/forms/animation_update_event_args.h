/// @file
/// @brief Contains xtd::forms::animation_updated_event_args event args.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/event_args.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides data for the animation update event.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    class animation_updated_event_args : public xtd::event_args {
    public:
      /// @name Constructors
      
      /// @{
      animation_updated_event_args(int32_t frame_counter, int64_t elapsed_milliseconds) : frame_counter_(frame_counter), elapsed_milliseconds_(elapsed_milliseconds) {}
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets elepased time in milliseconds.
      /// @return Elapsed time in milliseconds
      int64_t elapsed_milliseconds() const {return elapsed_milliseconds_;}
      
      /// @brief Gets frame counter.
      /// @return Frame counter.
      int32_t frame_counter() const {return frame_counter_;}
      /// @}
      
    private:
      int32_t frame_counter_ = 0;
      int64_t elapsed_milliseconds_ = 0;
    };
  }
}
