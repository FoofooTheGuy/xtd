#include <xtd/xtd>

using namespace xtd;

class generic_progress {
public:
  generic_progress() = default;
  generic_progress(int val, int min = 0, int max = 100, const ustring& msg = "") : message_(msg) {
    minimum_value(min);
    maximum_value(max);
    value(val);
  }

  int minimum_value() const noexcept {return minimum_value_;}
  generic_progress& minimum_value(int minimum_value) noexcept {
    minimum_value_ = minimum_value;
    maximum_value_ = math::max(maximum_value(), minimum_value);
    value_ = math::max(value(), minimum_value);
    return *this;
  }
  
  int maximum_value() const noexcept {return maximum_value_;}
  generic_progress& maximum_value(int maximum_value) noexcept {
    maximum_value_ = maximum_value;
    minimum_value_ = math::min(minimum_value(), maximum_value);
    value_ = math::min(value(), maximum_value);
    return *this;
  }
  
  const ustring& message() const noexcept {return message_;}
  generic_progress& message(const ustring& message) noexcept {
    message_ = message;
    return *this;
  }

  float percent() const noexcept {return maximum_value_ - minimum_value_ ? as<float>(value() - minimum_value()) / (maximum_value() - minimum_value()) : 1;}

  generic_progress& perform_step() noexcept {
    value(value() + step());
    return *this;
  }
  generic_progress& perform_step(const ustring& message) noexcept {
    message_ = message;
    return perform_step();
  }

  int value() const noexcept {return value_;}
  generic_progress& value(int value) noexcept {
    value_ = math::clamp(value, minimum_value(), maximum_value());
    return *this;
  }

  int step() const noexcept {return step_;}
  generic_progress& step(int step) noexcept {
    step_ = step;
    return *this;
  }

private:
  int minimum_value_ = 0;
  int maximum_value_ = 100;
  int step_ = 1;
  int value_ = 0;
  ustring message_;
};

class print_generic_progress : public iprogress<generic_progress> {
public:
  print_generic_progress() = default;
  
  void report(const generic_progress& value) noexcept override {
    console::write_line("completion={,3}%, message=\"{}\"", as<int>(value.percent() * 100), value.message());
  }
};

int main() {
  console::write_line("Started");

  print_generic_progress print_progress;
  generic_progress progress {0, 0, 5, "Initialized"};
  print_progress.report(progress);
  
  // Open device....
  print_progress.report(progress.perform_step("Device opened"));
  // Update 1 device....
  print_progress.report(progress.perform_step("Device updated 1"));
  // Update 2 device....
  print_progress.report(progress.perform_step("Device updated 2"));
  // Update 3 device....
  print_progress.report(progress.perform_step("Device updated 3"));
  // Close device....
  print_progress.report(progress.perform_step("Device closed"));
  
  console::write_line("Ended");
}

// The example displays output similar to the following:
//
// Started
// completion=  0%, message="Initialized"
// completion= 20%, message="Device opened"
// completion= 40%, message="Device updated 1"
// completion= 60%, message="Device updated 2"
// completion= 80%, message="Device updated 3"
// completion=100%, message="Device closed"
// Ended
