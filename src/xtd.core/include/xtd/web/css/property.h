/// @file
/// @brief Contains xtd::web::css::property class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <ostream>
#include "../../object.h"
#include "../../ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  namespace web {
    namespace css {
      class property : public object {
      public:
        /// @name Constructors
        
        /// @{
        property() = default;
        explicit property(const xtd::ustring& value) : value_(value) {}
        /// @}
        
        /// @name Operators
        
        /// @{
        operator xtd::ustring() noexcept {return value_;}
        /// @}
        
        /// @name Properties
        
        /// @{
        const xtd::ustring& value() const noexcept {return value_;}
        template<typename value_t>
        uintptr_t value() const noexcept {return xtd::parse<value_t>(value_);}
        /// @}
        
        /// @name Methods
        
        /// @{
        static property from(bool value) {return property(ustring::format("{}", value));}
        static property from(double value) {return property(ustring::format("{}", value));}
        static property from(float value) {return property(ustring::format("{}", value));}
        static property from(int8_t value) {return property(ustring::format("{}", value));}
        static property from(int16_t value) {return property(ustring::format("{}", value));}
        static property from(int32_t value) {return property(ustring::format("{}", value));}
        static property from(int64_t value) {return property(ustring::format("{}", value));}
        static property from(const xtd::ustring& value) {return property(ustring::format("{}", value));}
        static property from(uint8_t value) {return property(ustring::format("{}", value));}
        static property from(uint16_t value) {return property(ustring::format("{}", value));}
        static property from(uint32_t value) {return property(ustring::format("{}", value));}
        static property from(uint64_t value) {return property(ustring::format("{}", value));}
        template<typename value_t>
        static property from(value_t value) {return property(ustring::format("{}", value));}
        
        bool to_boolean() const {return xtd::parse<bool>(value_);}
        double to_double() const {return xtd::parse<double>(value_);}
        int8_t to_int8() const {return xtd::parse<int8_t>(value_);}
        int16_t to_int16() const {return xtd::parse<int16_t>(value_);}
        int32_t to_int32() const {return xtd::parse<int32_t>(value_);}
        int64_t to_int64() const {return xtd::parse<int64_t>(value_);}
        intptr_t to_intptr() const {return xtd::parse<intptr_t>(value_);}
        float to_single() const {return xtd::parse<float>(value_);}
        xtd::ustring to_string() const noexcept override {return value_;}
        uint8_t to_uint8() const {return xtd::parse<uint8_t>(value_);}
        uint16_t to_uint16() const {return xtd::parse<uint16_t>(value_);}
        uint32_t to_uint32() const {return xtd::parse<uint32_t>(value_);}
        uint64_t to_uint64() const {return xtd::parse<uint64_t>(value_);}
        uintptr_t to_uintptr() const {return xtd::parse<uintptr_t>(value_);}
        template<typename value_t>
        uintptr_t to() const {return xtd::parse<value_t>(value_);}
        /// @}
        
      private:
        xtd::ustring value_;
      };
    }
  }
}
