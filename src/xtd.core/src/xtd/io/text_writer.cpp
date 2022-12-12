#include "../../../include/xtd/io/text_writer.h"

using namespace xtd::io;

const xtd::ustring& text_writer::new_line() const noexcept {
  return new_line_;
}

void text_writer::new_line(const xtd::ustring& new_line) noexcept {
  new_line_ = new_line;
}

null_text_writer& text_writer::null() noexcept {
  static null_text_writer null_text_writer;
  return null_text_writer;
}

void text_writer::close() {
}

void text_writer::flush() {
}

synchronized_text_writer text_writer::synchronised(text_writer& writer) noexcept {
  return synchronized_text_writer(writer);
}

void text_writer::write(const xtd::ustring& value) {
}

void text_writer::write(bool value) {
  write(xtd::ustring::format("{}", value));
}

void text_writer::write(double value) {
  write(xtd::ustring::format("{}", value));
}

void text_writer::write(float value) {
  write(xtd::ustring::format("{}", value));
}

void text_writer::write(sbyte value) {
  write(xtd::ustring::format("{}", value));
}

void text_writer::write(int16 value) {
  write(xtd::ustring::format("{}", value));
}

void text_writer::write(int32 value) {
  write(xtd::ustring::format("{}", value));
}

void text_writer::write(int64 value) {
  write(xtd::ustring::format("{}", value));
}

void text_writer::write(xtd::byte value) {
  write(xtd::ustring::format("{}", value));
}

void text_writer::write(uint16_t value) {
  write(xtd::ustring::format("{}", value));
}

void text_writer::write(uint32 value) {
  write(xtd::ustring::format("{}", value));
}

void text_writer::write(uint64_t value) {
  write(xtd::ustring::format("{}", value));
}

void text_writer::write_line() {write(new_line_);}

void text_writer::write_line(const xtd::ustring& value) {
  write(value);
  write_line();
}

void text_writer::write_line(bool value) {
  write_line(xtd::ustring::format("{}", value));
}

void text_writer::write_line(double value) {
  write_line(xtd::ustring::format("{}", value));
}

void text_writer::write_line(float value) {
  write_line(xtd::ustring::format("{}", value));
}

void text_writer::write_line(sbyte value) {
  write_line(xtd::ustring::format("{}", value));
}

void text_writer::write_line(int16 value) {
  write_line(xtd::ustring::format("{}", value));
}

void text_writer::write_line(int32 value) {
  write_line(xtd::ustring::format("{}", value));
}

void text_writer::write_line(int64 value) {
  write_line(xtd::ustring::format("{}", value));
}

void text_writer::write_line(xtd::byte value) {
  write_line(xtd::ustring::format("{}", value));
}

void text_writer::write_line(uint16_t value) {
  write_line(xtd::ustring::format("{}", value));
}

void text_writer::write_line(uint32 value) {
  write_line(xtd::ustring::format("{}", value));
}

void text_writer::write_line(uint64_t value) {
  write_line(xtd::ustring::format("{}", value));
}

void null_text_writer::write(const xtd::ustring&) {
}

void synchronized_text_writer::write(const xtd::ustring& value) {
  std::lock_guard<std::mutex> lock(mutex_);
  writer_.write(value);
}

synchronized_text_writer::synchronized_text_writer(xtd::io::text_writer& writer) : writer_(writer) {
}
