#include "../../../include/xtd/io/text_reader.h"
#include "../../../include/xtd/argument_out_of_range_exception.h"
#include "../../../include/xtd/lock.h"

using namespace xtd;
using namespace xtd::io;

null_text_reader& text_reader::null() noexcept {
  static null_text_reader null_text_reader;
  return null_text_reader;
}

void text_reader::close() {
}

int32 text_reader::peek() const {
  return EOF;
}

int32 text_reader::read() {
  return EOF;
}

size_t text_reader::read(std::vector<char>& buffer, size_t index, size_t count) {
  if (index + count > buffer.size()) throw argument_exception(csf_);
  for (auto i = 0U; i < count; i++) {
    auto current = read();
    if (current == EOF) return i;
    buffer[index + i] = static_cast<char>(current);
  }
  return count;
}

size_t text_reader::read_block(std::vector<char>& buffer, size_t index, size_t count) {
  return read(buffer, index, count);
}

ustring text_reader::read_line() {
  ustring line;
  for (int32 current = read(); current != EOF && current != '\n'; current = read()) {
    if (current == '\r') continue;
    line += static_cast<char>(current);
  }
  return line;
}

ustring text_reader::read_to_end() {
  std::string text;
  for (int32 current = read(); current != EOF; current = read()) {
    if (current == '\r') continue;
    text += static_cast<char>(current);
  }
  return text;
}

synchronized_text_reader text_reader::synchronised(text_reader& reader) noexcept {
  return synchronized_text_reader(reader);
}

int32 null_text_reader::read() {
  return EOF;
}

int32 synchronized_text_reader::read() {
  lock_(reader_);
    return reader_.read();
  return EOF;
}

synchronized_text_reader::synchronized_text_reader(xtd::io::text_reader& reader) : reader_(reader) {
}
