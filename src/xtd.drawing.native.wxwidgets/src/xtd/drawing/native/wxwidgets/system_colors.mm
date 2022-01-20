#if defined(__APPLE__)
#include <AppKit/AppKit.h>

namespace {
  uint32_t to_argb(uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue) {
    return (alpha << 24) + (red << 16) + (green << 8) + blue;
  }
  
  uint32_t to_argb(uint8_t red, uint8_t green, uint8_t blue) {
    return to_argb(255, red, green, blue);
  }
  
  uint32_t to_argb(NSColor* color) {
    const CGFloat* components = CGColorGetComponents(color.CGColor);
    uint32_t alpha = CGColorGetAlpha(color.CGColor) * 0xFF;
    uint32_t red = components[0] * 0xFF;
    uint32_t green = components[1] * 0xFF;
    uint32_t blue = components[2] * 0xFF;
    return (alpha << 24) + (red << 16) + (green << 8) + blue;
  }
}

intptr_t __xtd__macos_system_colors_accent_control__() {
  return to_argb(NSColor.controlAccentColor);
}

intptr_t __xtd__macos_system_colors_accent_text__() {
  return to_argb(255, 255, 255);
}

intptr_t __xtd__macos_system_colors_active_border__() {
  return to_argb([[NSColor highlightColor] colorUsingColorSpace:[NSColorSpace deviceRGBColorSpace]]);
}

intptr_t __xtd__macos_system_colors_active_caption__() {
  return to_argb([[NSColor highlightColor] colorUsingColorSpace:[NSColorSpace deviceRGBColorSpace]]);
}

intptr_t __xtd__macos_system_colors_button_face__() {
  uint32_t argb = to_argb(NSColor.controlColor);
  if (argb != 0xFFFFFFFF) {
    argb &= 0x00FFFFFF;
    argb |= 0x40000000;
  }
  return argb;
  
}

intptr_t __xtd__macos_system_colors_button_text__() {
  return to_argb(NSColor.controlTextColor);
}

intptr_t __xtd__macos_system_colors_control__() {
  return to_argb(NSColor.windowBackgroundColor);
}

intptr_t __xtd__macos_system_colors_control_text__() {
  return to_argb(NSColor.controlTextColor);
}

intptr_t __xtd__macos_system_colors_text_box__() {
  uint32_t argb = to_argb(NSColor.controlColor);
  if (argb != 0xFFFFFFFF) {
    argb &= 0x00FFFFFF;
    argb |= 0x10000000;
  }
  return argb;
}

intptr_t __xtd__macos_system_colors_text_box_text__() {
  return to_argb(NSColor.textColor);
}

#endif
