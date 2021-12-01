/// @file
/// @brief Contains xtd::io::binary_writer class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <fstream>
#include <optional>
#include <array>
#include <vector>
#include "../object.h"
#include "../ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Writes primitive types in binary to a stream and supports writing strings.
    /// @code
    /// class binary_writer : public xtd::object
    /// @endcode
    /// Ineheritance xtd::object → xtd::io::binary_writer
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    /// @par Example
    /// The following code example demonstrates how to store and retrieve application settings in a file.
    /// @include binary_reader.cpp
    /// @par Example
    /// The same example with stream operators.
    /// @include binary_reader2.cpp
    /// @remarks The xtd::io::binary_writer class provides methods that simplify writing primitive data types to a stream. For example, you can use the Write method to write a Boolean value to the stream as a one-byte value. The class includes write methods that support different data types.
    /// @remarks When you create a new instance of the xtd::io::binary_writer class, you provide the stream to write to.
    class binary_writer : public object {
    public:
      /// @brief Initializes a new instance of the binary_writer class for the specified file name.
      /// @param path The complete file path to be read.
      /// @exception xtd::argument_exception path contains one or more of the invalid characters -or- The system could not retrieve the absolute path.
      /// @exception xtd::io::io_exception the handle of the specified file cannot be opened
      binary_writer(const xtd::ustring& path);
      /// @brief Initializes a new instance of the binary_writer class for the specified stream.
      /// @param stream The stream to be read.
      binary_writer(std::ostream& stream);
      /// @cond
      ~binary_writer();
      /// @endcond
      
      /// @brief Returns the underlying stream.
      /// @return The underlying stream.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      std::optional<std::reference_wrapper<std::ostream>> base_stream() const;
      
      /// @brief Closes the xtd::io::binary_writer object and the underlying stream, and releases any system resources associated with the reader.
      virtual void close();
      
      /// @brief Clears all buffers for the current writer and causes any buffered data to be written to the underlying device.
      /// @remarks This default method does nothing, but derived classes can virtual the method to provide the appropriate functionality
      virtual void flush();
      
      /// @brief Sets the position within the current stream.
      /// @param ofsset A byte offset relative to origin.
      /// @param origin A field of std::ios::seekdir indicating the reference point from which the new position is to be obtained.
      /// @return The position with the current stream.
      /// @exception xtd::io::io_exception The file pointer was moved to an invalid location.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      virtual size_t seek(size_t offset, std::ios::seekdir origin);

      /// @brief Writes a one-byte boolean value to the current stream, with 0 representing false and 1 representing true.
      /// @param value The boolean value to write (0 or 1).
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      virtual void write(bool value);
      
      /// @brief Writes an unsigned byte to the current stream and advances the stream position by one byte.
      /// @param value The unsigned byte to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      virtual void write(byte_t value);
      
      /// @brief Writes a character to the current stream and advances the current position by one byte.
      /// @param value The character to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      virtual void write(char value);
      
      /// @brief Writes a byte array to the underlying stream.
      /// @param buffer A byte array containing the data to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      template<size_t size>
      void write(const std::array<byte_t, size>& buffer) {
        for (auto b : buffer)
          write(b);
      }
      
      /// @brief Writes a character array to the underlying stream.
      /// @param buffer A character array containing the data to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      template<size_t size>
      void write(const std::array<char, size>& buffer) {
        for (auto c : buffer)
          write(c);
      }

      /// @brief Writes a byte array to the underlying stream.
      /// @param buffer A byte array containing the data to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      virtual void write(const std::vector<byte_t>& buffer);

      /// @brief Writes a region of a byte array to the current stream.
      /// @param buffer A byte array containing the data to write.
      /// @param index The index of the first byte to read from buffer and to write to the stream.
      /// @param count The number of bytes to read from buffer and to write to the stream.
      /// @exception xtd::argument_exception The buffer length minus index is less than count.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      virtual void write(const std::vector<byte_t>& buffer, size_t index, size_t count);

      /// @brief Writes a character array to the underlying stream.
      /// @param buffer A character array containing the data to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      virtual void write(const std::vector<char>& buffer);

      /// @brief Writes a region of a character array to the current stream.
      /// @param buffer A character array containing the data to write.
      /// @param index The index of the first byte to read from buffer and to write to the stream.
      /// @param count The number of bytes to read from buffer and to write to the stream.
      /// @exception xtd::argument_exception The buffer length minus index is less than count.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      virtual void write(const std::vector<char>& buffer, size_t index, size_t count);

      /// @brief Writes an eight-byte floating-point value to the current stream and advances the stream position by eight bytes.
      /// @param value The eight-byte floating-point value to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      virtual void write(double value);

      /// @brief Writes a two-byte signed integer to the current stream and advances the stream position by two bytes.
      /// @param value The two-byte signed integer to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      virtual void write(int16_t value);
      
      /// @brief Writes a four-byte signed integer to the current stream and advances the stream position by four bytes.
      /// @param value The four-byte signed integer to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      virtual void write(int32_t value);
      
      /// @brief Writes a eight-byte signed integer to the current stream and advances the stream position by eight bytes.
      /// @param value The eight-byte signed integer to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      virtual void write(int64_t value);
      
      /// @brief Writes an signed byte to the current stream and advances the stream position by one byte.
      /// @param value The signed byte to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      virtual void write(sbyte_t value);
      
      /// @brief Writes an four-byte floating-point value to the current stream and advances the stream position by four bytes.
      /// @param value The four-byte floating-point value to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      virtual void write(float value);
      
      /// @brief Writes a length-prefixed string to this stream, and advances the current position of the stream and the specific characters being written to the stream.
      /// @param value The value to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      virtual void write(const ustring& value);
      /// @cond
      virtual void write(const std::string& value);
      virtual void write(const std::u8string& value);
      virtual void write(const std::u16string& value);
      virtual void write(const std::u32string& value);
      virtual void write(const std::wstring& value);
      virtual void write(const char* value);
      virtual void write(const char8_t* value);
      virtual void write(const char16_t* value);
      virtual void write(const char32_t* value);
      virtual void write(const wchar_t* value);
      /// @endcond

      /// @brief Writes a two-byte unsigned integer to the current stream and advances the stream position by two bytes.
      /// @param value The two-byte unsigned integer to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      virtual void write(uint16_t value);
      
      /// @brief Writes a four-byte unsigned integer to the current stream and advances the stream position by four bytes.
      /// @param value The four-byte unsigned integer to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      virtual void write(uint32_t value);
      
      /// @brief Writes a eight-byte unsigned integer to the current stream and advances the stream position by eight bytes.
      /// @param value The eight-byte unsigned integer to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      virtual void write(uint64_t value);
      
      /// @cond
      binary_writer& operator<<(bool value) {write(value); return *this;}
      binary_writer& operator<<(byte value) {write(value); return *this;}
      binary_writer& operator<<(char value) {write(value); return *this;}
      template<size_t size>
      binary_writer& operator<<(const std::array<byte_t, size>& value) {write(value); return *this;}
      template<size_t size>
      binary_writer& operator<<(const std::array<char, size>& value) {write(value); return *this;}
      binary_writer& operator<<(const std::vector<byte_t>& value) {write(value); return *this;}
      binary_writer& operator<<(const std::vector<char>& value) {write(value); return *this;}
      binary_writer& operator<<(double value) {write(value); return *this;}
      binary_writer& operator<<(int16_t value) {write(value); return *this;}
      binary_writer& operator<<(int32_t value) {write(value); return *this;}
      binary_writer& operator<<(int64_t value) {write(value); return *this;}
      binary_writer& operator<<(sbyte value) {write(value); return *this;}
      binary_writer& operator<<(float value) {write(value); return *this;}
      binary_writer& operator<<(const ustring& value) {write(value); return *this;}
      binary_writer& operator<<(const std::string& value) {write(value); return *this;}
      binary_writer& operator<<(const std::u8string& value) {write(value); return *this;}
      binary_writer& operator<<(const std::u16string& value) {write(value); return *this;}
      binary_writer& operator<<(const std::u32string& value) {write(value); return *this;}
      binary_writer& operator<<(const std::wstring& value) {write(value); return *this;}
      binary_writer& operator<<(const char* value) {write(value); return *this;}
      binary_writer& operator<<(const char8_t* value) {write(value); return *this;}
      binary_writer& operator<<(const char16_t* value) {write(value); return *this;}
      binary_writer& operator<<(const char32_t* value) {write(value); return *this;}
      binary_writer& operator<<(const wchar_t* value) {write(value); return *this;}
      binary_writer& operator<<(uint16_t value) {write(value); return *this;}
      binary_writer& operator<<(uint32_t value) {write(value); return *this;}
      binary_writer& operator<<(uint64_t value) {write(value); return *this;}
      /// @endcond

    private:
      std::ostream* stream_ = nullptr;
      bool delete_when_destroy_ = false;
    };
  }
}
