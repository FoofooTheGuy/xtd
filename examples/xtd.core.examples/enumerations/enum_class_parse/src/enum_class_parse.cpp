#include <xtd/xtd>

using namespace xtd;

enum_class_(, enum_test,
  value_one,
  value_two,
  value_three,
  value_four
);

int main() {
  console::write_line("result = {}", enum_object<>::parse<enum_test>("value_two"));
  console::write_line("result = {}", enum_object<>::parse<enum_test>("VaLuE_fOuR", true));
  try {
    console::write_line("result = {}", enum_object<>::parse<enum_test>("value_five"));
  } catch (const xtd::system_exception&) {
    console::write_line("enum_test::value_five does not exists!");
  }
  
  enum_test result;
  if (enum_object<>::try_parse<enum_test>("value_three", result)) console::write_line("result = {}", result);
  if (enum_object<>::try_parse<enum_test>("vAlUe_OnE", true, result)) console::write_line("result = {}", result);
  if (enum_object<>::try_parse<enum_test>("value_six", result)) console::write_line("result = {}", result);
  else console::write_line("enum_test::value_six does not exists!");
}
