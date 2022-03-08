/// @file
/// @brief Contains xtd::threading::interlocked class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once

#include <atomic>
#include <mutex>

#include "../core_export.h"
#include "../static.h"
#include "../object.h"
#include "../types.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming.
  /// In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Provides atomic operations for variables that are shared by multiple threads.
    /// @code
    /// class core_export_ interlocked static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::threading::interlocked
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    /// @remarks The methods of this class help protect against errors that can occur when the scheduler switches contexts while a thread is updating a variable that can be accessed by other threads, or when two threads are executing concurrently on separate processors. The members of this class do not throw exceptions.
    /// @remarks The xtd::threading::interlocked::increment and xtd::threading::interlocked::decrement methods increment or decrement a variable and store the resulting value in a single operation. On most computers, incrementing a variable is not an atomic operation, requiring the following steps:
    /// @remarks   1. Load a value from an instance variable into a register.
    /// @remarks   2. Increment or decrement the value.
    /// @remarks   3. Store the value in the instance variable.
    /// @remarks If you do not use xtd::threading::interlocked::increment and xtd::threading::interlocked::decrement, a thread can be preempted after executing the first two steps. Another thread can then execute all three steps. When the first thread resumes execution, it overwrites the value in the instance variable, and the effect of the increment or decrement performed by the second thread is lost.
    /// @remarks The xtd::threading::exchange method atomically exchanges the values of the specified variables. The compare_exchange method combines two operations: comparing two values and storing a third value in one of the variables, based on the outcome of the comparison. The compare and exchange operations are performed as an atomic operation.
    /// @par Examples
    /// The following code example shows a thread-safe resource locking mechanism.
    /// @include interlocked.cpp
    class core_export_ interlocked static_ {
    public:
      /// @brief Adds two 32-bit integers and replaces the first integer with the sum, as an atomic operation.
      /// @param location A variable containing the first value to be added. The sum of the two values is stored in location.
      /// @param value The value to be added to the integer at location.
      /// @return int32_t The new value stored at location.
      static int32_t add(int32_t& location, int32_t value) noexcept;
      
      /// @brief Adds two 64-bit integers and replaces the first integer with the sum, as an atomic operation.
      /// @param location A variable containing the first value to be added. The sum of the two values is stored in location.
      /// @param value The value to be added to the integer at location.
      /// @return int64_t The new value stored at location.
      static int64_t add(int64_t& location, int64_t value) noexcept;
      
      /// @brief Compares two Double for equality and, if they are equal, replaces one of the values.
      /// @param location The destination, whose value is compared with comparand and possibly replaced.
      /// @param value The value that replaces the destination value if the comparison results in equality.
      /// @param comparand The value that is compared to the value at location.
      /// @return The original value in location.
      static double compare_exchange(double& location, double value, double comparand) noexcept;
      
      /// @brief Compares two 32-bit signed integers for equality and, if they are equal, replaces one of the values.
      /// @param location The destination, whose value is compared with Comparand and possibly replaced.
      /// @param value The value that replaces the destination value if the comparison results in equality.
      /// @param Comparand The value that is compared to the value at location.
      /// @return The original value in location.
      static int32_t compare_exchange(int32_t& location, int32_t value, int32_t comparand) noexcept;
      
      /// @brief Compares two 64-bit signed integers for equality and, if they are equal, replaces one of the values.
      /// @param location The destination, whose value is compared with comparand and possibly replaced.
      /// @param value The value that replaces the destination value if the comparison results in equality.
      /// @param comparand The value that is compared to the value at location.
      /// @return The original value in location.
      static int64_t compare_exchange(int64_t& location, int64_t value, int64_t comparand) noexcept;
      
      /// @brief Compares two platform-specific handles or pointers for equality and, if they are equal, replaces one of them.
      /// @param location The destination, whose value is compared with comparand and possibly replaced.
      /// @param value The value that replaces the destination value if the comparison results in equality.
      /// @param comparand The value that is compared to the value at location.
      /// @return The original value in location.
      static void* compare_exchange(void*& location, void* value, void* comparand) noexcept;
      
      /// @brief Compares two objects for equality and, if they are equal, replaces one of them.
      /// @param location The destination, whose value is compared with comparand and possibly replaced.
      /// @param value The value that replaces the destination value if the comparison results in equality.
      /// @param comparand The value that is compared to the value at location.
      /// @return The original value in location.
      template<typename type_t>
      static type_t compare_exchange(object& location, const object& value, const object& comparand) noexcept {
        type_t retValue = location;
        std::lock_guard<std::mutex> lock(guard);
        if (location.equals(comparand))
          location = value;
        return retValue;
      }
      
      /// @brief Compares two instances of the specified reference type type_t for equality and, if they are equal, replaces one of them.
      /// @param location The destination, whose value is compared with comparand and possibly replaced.
      /// @param value The value that replaces the destination value if the comparison results in equality.
      /// @param comparand The value that is compared to the value at location.
      /// @return The original value in location.
      template<typename type_t>
      static type_t compare_exchange(type_t& location, type_t value, type_t comparand) noexcept {
        type_t retValue = location;
        std::lock_guard<std::mutex> lock(guard);
        if (location == comparand)
          location = value;
        return retValue;
      }
      
      /// @brief Compares two Single for equality and, if they are equal, replaces one of the values.
      /// @param location The destination, whose value is compared with comparand and possibly replaced.
      /// @param value The value that replaces the destination value if the comparison results in equality.
      /// @param comparand The value that is compared to the value at location.
      /// @return The original value in location.
      static float compare_exchange(float& location, float value, float comparand) noexcept;
      
      /// @brief Decrements a specified variable and stores the result, as an atomic operation.
      /// @param location The variable whose value is to be decremented.
      /// @return The decremented value.
      /// @par Examples
      /// The following code example shows a thread-safe way to increment and decrement an integer value. SafeInstanceCount will always be zero. However, UnsafeInstanceCount will not necessarily be zero because a race condition occurs between incrementing and decrementing the count. This effect is especially marked on a multiprocessor computer.
      /// @include interlocked_decrement.cpp
      static int32_t decrement(int32_t& location) noexcept;
      
      /// @brief Decrements a specified variable and stores the result, as an atomic operation.
      /// @param location The variable whose value is to be decremented.
      /// @return The decremented value.
      static int64_t decrement(int64_t& location) noexcept;
      
      /// @brief Sets a variable of the specified type type_t to a specified value and returns the original value, as an atomic operation.
      /// @param location The variable to set to the specified value.
      /// @param value The value to which the location parameter is set.
      /// @return The original value of location.
      template<typename type_t>
      static type_t exchange(type_t& location, type_t value) {
        type_t original = location;
        std::lock_guard<std::mutex> lock(guard);
        location = value;
        return original;
      }
      
      /// @brief Sets a double-precision floating point number to a specified value and returns the original value, as an atomic operation.
      /// @param location The variable to set to the specified value.
      /// @param value The value to which the location_d parameter is set.
      /// @return The original value of location_d.
      static double exchange(double& location, double value) noexcept;
      
      /// @brief Sets a 32-bit signed integer to a specified value and returns the original value, as an atomic operation.
      /// @param location The variable to set to the specified value.
      /// @param value The value to which the location parameter is set.
      /// @return The original value of location.
      /// @par Examples
      /// The following code example shows a thread-safe resource locking mechanism.
      /// @include interlocked.cpp
      static int32_t exchange(int32_t& location, int32_t value) noexcept;
      
      /// @brief Sets a 64-bit signed integer to a specified value and returns the original value, as an atomic operation.
      /// @param location The variable to set to the specified value.
      /// @param value The value to which the location parameter is set.
      /// @return The original value of location.
      static int64_t exchange(int64_t& location, int64_t value) noexcept;
      
      /// @brief Sets a platform-specific handles or pointers to a specified value and returns the original value, as an atomic operation.
      /// @param location The variable to set to the specified value.
      /// @param value The value to which the location parameter is set.
      /// @return The original value of location.
      static void* exchange(void*& location, void* value) noexcept;
      
      /// @brief Sets an object to a specified value and returns the original value, as an atomic operation.
      /// @param location The variable to set to the specified value.
      /// @param value The value to which the location parameter is set.
      /// @return The original value of location.
      template<typename type_t>
      static type_t exchange(object& location, const object& value) noexcept {
        type_t original = location;
        std::lock_guard<std::mutex> lock(guard);
        location = value;
        return original;
      }
      
      /// @brief Sets a double-precision floating point number to a specified value and returns the original value, as an atomic operation.
      /// @param location The variable to set to the specified value.
      /// @param value The value to which the location_f parameter is set.
      /// @return The original value of location_f.
      static float exchange(float& location, float value) noexcept;
      
      /// @brief Increments a specified variable and stores the result, as an atomic operation.
      /// @param location The variable whose value is to be incremented.
      /// @return The incremented value.
      /// @par Examples
      /// The following code example shows a thread-safe way to increment and decrement an integer value. SafeInstanceCount will always be zero. However, UnsafeInstanceCount will not necessarily be zero because a race condition occurs between incrementing and decrementing the count. This effect is especially marked on a multiprocessor computer.
      /// @include interlocked_decrement.cpp
      static int32_t increment(int32_t& location) noexcept;
      
      /// @brief Increments a specified variable and stores the result, as an atomic operation.
      /// @param location The variable whose value is to be incremented.
      /// @return The incremented value.
      static int64_t increment(int64_t& location) noexcept;
      
      /// @brief Synchronizes memory access as follows: The processor that executes the current thread cannot reorder instructions in such a way that memory accesses before the call to xtd::threading::interlocked::memory_barrier execute after memory accesses that follow the call to xtd::threading::interlocked::memory_barrier.
      /// @remarks This method was added to the xtd::threading::interlocked class as a convenience; it's a wrapper for the xtd::threading::thread::memory_barrier method.
      /// @remarks xtd::threading::interlocked::memory_barrier is required only on multiprocessor systems that have weak memory ordering (for example, a system that employs multiple Intel Itanium processors).
      /// @remarks For most purposes, the lock_ statement, or the Monitor class provide easier ways to synchronize data.
      static void memory_barrier() noexcept;
      
      /// @brief Returns a 64-bit value, loaded as an atomic operation.
      /// @param location The 64-bit value to be loaded.
      /// @return The loaded value.
      static int64_t read(int64_t& location) noexcept;
      
    private:
      /// @brief Represent The object used to create a lock section
      static std::mutex guard;
    };
  }
}
