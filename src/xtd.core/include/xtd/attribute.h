/// @file
/// @brief Contains xtd::attribute class.
#pragma once

#include "object.h"
#include "guid.h"
#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the base class for custom attributes.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  class attribute : public object {
  public:
    /// @cond
    attribute(const attribute&) = default;
    attribute(attribute&&) = default;
    attribute& operator=(const attribute&) = default;
    /// @endcond
    
    /// @brief When implemented in a derived class, gets a unique identifier for this attribute.
    /// @remarks As implemented, this identifier is merely the Type of the attribute. However, it is intended that the unique identifier be used to identify two attributes of the same type.
    std::shared_ptr<object> type_id() {return get_type_id();}
    
  protected:
    /// @brief Initializes a new instance of the attribute class.
    /// @remarks This constructor is only called by classes that derive from attribute.
    attribute() = default;
    
    /// @brief When implemented in a derived class, gets a unique identifier for this attribute.
    /// @remarks As implemented, this identifier is merely the Type of the attribute. However, it is intended that the unique identifier be used to identify two attributes of the same type.
    virtual std::shared_ptr<object> get_type_id() const = 0;
  };
}
