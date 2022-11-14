/// @file
/// @brief Contains xtd::processor class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <map>
#include <vector>
#include "architecture_id.h"
#include "object.h"
#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents information about a processor, such as the architecture. This class cannot be inherited.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  class processor final : public object {
  public:
    /// @name Constructors
    
    /// @{
    /// @brief Initialise a new instance oof xtd::processor class.
    /// @param architecture One of xtd::architectuure_id valuues.
    /// @param is_64_bit true if 64 bit architecture; otherwise false.
    /// @param core_count THe number of cores.
    processor(xtd::architecture_id architecture, bool is_64_bit, uint32_t core_count) : architecture_(architecture), is_64_bit_(is_64_bit), core_count_(core_count) {}
    /// @}
    
    /// @cond
    processor() = default;
    processor(const processor&) = default;
    processor& operator=(const processor&) = default;
    /// @endcond
    
    /// @name Properties
    
    /// @{
    /// @brief Gets a xtd::platform_id enumeration value that identifies the operating system platform.
    /// @return xtd::platform_id One of the xtd::platform_id values.
    xtd::architecture_id architecture() const noexcept {return architecture_;}
    
    /// @brief Gets the number of processors on the current machine.
    /// @return The 32-bit unsigned integer that specifies the number of processors on the current machine. There is no default. If the current machine contains multiple processor groups, this property returns the number of logical processors that are available for use.
    uint32_t core_count() const noexcept {return core_count_;}
    
    /// @brief Determines whether the current operating system is a 64-bit operating system.
    /// @return true if the operating system is 64-bit; otherwise, false.
    bool is_64_bit() const noexcept {return is_64_bit_;}
    
    /// @brief Gets the concatenated string representation of the platform identifier.
    /// @return The string representation of the values returned by the platform.
    xtd::ustring name() const noexcept {
      static std::map<xtd::architecture_id, xtd::ustring> processor_names {{architecture_id::x86, "Intel or AMD"}, {architecture_id::arm, "ARM"}, {architecture_id::unknown, "<Unknown>"}};
      return processor_names[architecture_];
    }
    
    xtd::ustring architecture_string() const noexcept {
      if (!architecture_string_.empty()) return architecture_string_;
      architecture_string_ = ustring::format("{}", architecture_);
      if (is_64_bit_) {
        if (architecture_ == architecture_id::x86) architecture_string_ += "_";
        architecture_string_ += "64";
      }
      return architecture_string_;
    }
    /// @}
    
    /// @name Methods
    
    /// @{
    /// @brief Converts the value of this processor object to its equivalent string representation.
    /// @return The string representation of the values returned by the platform, version, and service_pack methods.
    xtd::ustring to_string() const noexcept override {return architecture_string();}
    /// @}
    
  private:
    xtd::architecture_id architecture_ = xtd::architecture_id::unknown;
    bool is_64_bit_ = false;
    uint32_t core_count_ = 1;
    mutable xtd::ustring architecture_string_;
  };
}
