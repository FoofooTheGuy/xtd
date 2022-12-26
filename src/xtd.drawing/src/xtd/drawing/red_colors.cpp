#include "../../../include/xtd/drawing/red_colors.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

color red_colors::crimson() {
  return color::from_known_color(known_color::crimson);
}

color red_colors::dark_red() {
  return color::from_known_color(known_color::dark_red);
}

color red_colors::dark_salmon() {
  return color::from_known_color(known_color::dark_salmon);
}

color red_colors::firebrick() {
  return color::from_known_color(known_color::firebrick);
}

color red_colors::indian_red() {
  return color::from_known_color(known_color::indian_red);
}

color red_colors::light_coral() {
  return color::from_known_color(known_color::light_coral);
}

color red_colors::light_salmon() {
  return color::from_known_color(known_color::light_salmon);
}

color red_colors::red() {
  return color::from_known_color(known_color::red);
}

color red_colors::salmon() {
  return color::from_known_color(known_color::salmon);
}

const vector<color>& red_colors::get_colors() {
  static vector colors {red_colors::dark_red(), red_colors::red(), red_colors::firebrick(), red_colors::crimson(), red_colors::indian_red(), red_colors::light_coral(), red_colors::salmon(), red_colors::dark_salmon(), red_colors::light_salmon()};
  return colors;
}

const vector<ustring>& red_colors::get_color_names() {
  static vector color_names {red_colors::dark_red().name(), red_colors::red().name(), red_colors::firebrick().name(), red_colors::crimson().name(), red_colors::indian_red().name(), red_colors::light_coral().name(), red_colors::salmon().name(), red_colors::dark_salmon().name(), red_colors::light_salmon().name()};
  return color_names;
}
