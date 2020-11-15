/// @file
/// @brief Contains xtd::diagnostics::trace class.
#pragma once
#include <vector>
#include "stack_frame.h"
#include "../environment.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    class stack_trace {
    public:
      using frame_collection = std::vector<xtd::diagnostics::stack_frame>;
      
      stack_trace() : stack_trace("", 1, true) {}
      explicit stack_trace(bool need_file_info) : stack_trace("", 1, need_file_info) {}
      explicit stack_trace(size_t skip_frames) : stack_trace("", skip_frames + 1, true) {}
      stack_trace(size_t skip_frames, bool need_file_info) : stack_trace("", skip_frames + 1, need_file_info) {}
      stack_trace(const std::string& str) : stack_trace(str, 1, true) {}
      stack_trace(const std::string& str, bool need_file_info) : stack_trace(str, 1, need_file_info) {}
      stack_trace(const std::string& str, size_t skip_frames) : stack_trace(str, skip_frames + 1, true) {}
      stack_trace(const std::string& str, size_t skip_frames, bool need_file_info);
      /// @cond
      stack_trace(const char* str) : stack_trace(std::string(str), 1, true) {}
      stack_trace(const char* str, bool need_file_info) : stack_trace(std::string(str), 1, need_file_info) {}
      stack_trace(const char* str, size_t skip_frames) : stack_trace(std::string(str), skip_frames + 1, true) {}
      stack_trace(const char* str, size_t skip_frames, bool need_file_info) : stack_trace(std::string(str), skip_frames + 1, need_file_info) {}
      stack_trace(const stack_trace&) = default;
      stack_trace& operator=(const stack_trace&) = default;
      ~stack_trace();
      /// @endcond
      
      const frame_collection& frames() const {return frames_;}
            
      std::string to_string() const {
        std::string str;
        bool first = true;
        for (auto frame : frames_) {
          if (!first) str += xtd::environment::new_line();
          str += "   at " + frame.method_name();
          if (!frame.file_path().empty()) str += xtd::strings::format(" [0x{:X8}] in {}:{}", frame.offset(), frame.file_path(), frame.file_line());
          first = false;
        }
        return  str;
      }

      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::diagnostics::stack_trace& stack_trace) noexcept {return os << stack_trace.to_string();}
      /// @endcond

      static constexpr size_t METHODS_TO_SKIP = 0;
      
    private:
      void get_frames(const std::string& str, size_t skip_frames, bool need_file_info);
      frame_collection frames_;
      intptr_t handle_;
    };
  }
}
