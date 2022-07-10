#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "wx_brush.h"
#include "wxConicalGradient.h"
#include "hdc_wrapper.h"
#include <cmath>
#include <xtd/drawing/native/hot_key_prefixes.h>
#include <xtd/drawing/native/string_formats.h>
#include <xtd/drawing/native/string_trimmings.h>
#include <xtd/convert_string.h>
#include <wx/control.h>
#include <wx/dcclient.h>
#include <wx/dcmemory.h>
#include <wx/dcgraph.h>
#include <wx/graphics.h>
#include <wx/string.h>

namespace xtd {
  namespace drawing {
    namespace native {
      class wxDrawString {
      public:
        static void DrawString(intptr_t handle, const wxString& text, const wxFont& font, const wx_brush& brush, float x, float y, float angle, wxAlignment align, int32_t hotKeyPrefix, int32_t trimming) {
          DrawString(handle, text, font, brush, x, y, 0.0f, 0.0f, angle, align, hotKeyPrefix, trimming, 0);
        }
        
        static void DrawString(intptr_t handle, const wxString& text, const wxFont& font, const wx_brush& brush, float x, float y, float widthF, float heightF, float angle, wxAlignment align, int32_t hotKeyPrefix, int32_t trimming, int32_t stringFormats) {
          auto width = static_cast<int32_t>(std::floor(widthF));
          auto height = static_cast<int32_t>(std::floor(heightF));
          auto noClip = (stringFormats & SF_NO_CLIP) == SF_NO_CLIP || (width == 0 && height == 0); // && angle == 0;
          auto directionVertical = (stringFormats & SF_VERTICAL) == SF_VERTICAL;
          auto measureTrailingSpaces = (stringFormats & SF_MEASURE_TRAILING_SPACES) == SF_MEASURE_TRAILING_SPACES;
          auto rightToLeft = (stringFormats & SF_RIGHT_TO_LEFT) == SF_RIGHT_TO_LEFT;

          if (rightToLeft) {
            auto newAlign = static_cast<int32_t>(align);
            if ((align & wxALIGN_RIGHT) == wxALIGN_RIGHT) {
              newAlign &= ~wxALIGN_RIGHT;
              newAlign |= wxALIGN_LEFT;
            } else if ((newAlign & wxALIGN_CENTER_HORIZONTAL) != wxALIGN_CENTER_HORIZONTAL) {
              newAlign &= ~wxALIGN_LEFT;
              newAlign |= wxALIGN_RIGHT;
            }
            align = static_cast<wxAlignment>(newAlign);
          }

          if (width == 0 && height == 0) MeasureString(reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc(), text, font, width, height, measureTrailingSpaces);
          
          if (directionVertical) {
            x = x + width;
            width = -width;
            angle += 90.0f;
          }
          
          auto& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc();
          dc.SetFont(font);

          wxArrayString strings;
          if ((stringFormats & SF_NO_WRAP) != SF_NO_WRAP) strings = WrapText(dc, text, font, width, height, directionVertical, measureTrailingSpaces);
          else strings.push_back(text);
          auto string = ToString(dc, FormatString(dc, strings, width, height, hotKeyPrefix, trimming, directionVertical), font, width, height, (stringFormats & SF_LINE_LIMIT) == SF_LINE_LIMIT, directionVertical);

          if (brush.is_solid_brush()) DrawStringWithSolidBrush(dc, string, font, brush, x, y, width, height, angle, align, hotKeyPrefix, noClip);
          else DrawStringWithGradientBrush(handle, string, font, brush, x, y, width, height, angle, align, hotKeyPrefix, noClip);
        }
        
        static void MeasureString(wxDC& dc, const wxString& text, const wxFont& font, float& width, float& height, bool measureTrailingSpaces) {
          width = 0.0f;
          height = 0.0f;
          dc.SetFont(font);
          auto strings = wxSplit(text, '\n');
          for (auto string : strings) {
            auto lineWidth = 0.0;
            auto lineHeight = 0.0;
            auto lineSize = dc.GetTextExtent(measureTrailingSpaces ? string : string.Trim());
            lineWidth = lineSize.GetWidth();
            lineHeight = lineSize.GetHeight();
            width = std::max(width, static_cast<float>(lineWidth));
            height += static_cast<float>(lineHeight);
            
            // Workaround : with wxWidgets version <= 3.1.5 width size text is too small on macOS and linux.
            if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() != "Windows" && font.GetStyle() > wxFontStyle::wxFONTSTYLE_NORMAL) width += std::ceil(dc.GetFontMetrics().averageWidth / 2.3f);
          }
        }
        
        static void MeasureString(wxDC& dc, const wxString& text, const wxFont& font, int32_t& width, int32_t& height, bool measureTrailingSpaces) {
          auto widthF = 0.0f;
          auto heightF = 0.0f;
          MeasureString(dc, text, font, widthF, heightF, measureTrailingSpaces);
          width = static_cast<float>(std::ceil(widthF));
          height = static_cast<float>(std::ceil(heightF));
        }

        static wxString FormatString(wxDC& dc, const wxString& string, float width, int32_t hotKeyPrefix, int32_t trimming) {
          auto result = hotKeyPrefix != HKP_NONE ? RemoveHotKeyPrefixLocations(string) : string;
          switch (trimming) {
            case ST_NONE: result = wxControl::Ellipsize(result, dc, wxEllipsizeMode::wxELLIPSIZE_NONE, width, wxEllipsizeFlags::wxELLIPSIZE_FLAGS_NONE); break;
            case ST_CHARACTER: result = wxControl::Ellipsize(result, dc, wxEllipsizeMode::wxELLIPSIZE_NONE, width, wxEllipsizeFlags::wxELLIPSIZE_FLAGS_DEFAULT); break;
            case ST_WORD: result = wxControl::Ellipsize(result, dc, wxEllipsizeMode::wxELLIPSIZE_NONE, width, wxEllipsizeFlags::wxELLIPSIZE_FLAGS_DEFAULT); break;
            case ST_ELLIPSIS_CHARACTER: result = wxControl::Ellipsize(result, dc, wxEllipsizeMode::wxELLIPSIZE_END, width, wxEllipsizeFlags::wxELLIPSIZE_FLAGS_DEFAULT); break;
            case ST_ELLIPSIS_WORD: result = wxControl::Ellipsize(result, dc, wxEllipsizeMode::wxELLIPSIZE_END, width, wxEllipsizeFlags::wxELLIPSIZE_FLAGS_DEFAULT); break;
            case ST_ELLIPSIS_PATH: result = wxControl::Ellipsize(result, dc, wxEllipsizeMode::wxELLIPSIZE_MIDDLE, width, wxEllipsizeFlags::wxELLIPSIZE_FLAGS_DEFAULT); break;
            default: break;
          }
          return result;
        }

      private:
        static void DrawStringWithSolidBrush(wxDC& dc, const wxString& string, const wxFont& font, const wx_brush& brush, int32_t x, int32_t y, int32_t width, int32_t height, float angle, wxAlignment align, int32_t hotKeyPrefix, bool noClip) {
          if (!noClip) dc.SetClippingRegion({static_cast<int32_t>(x), static_cast<int32_t>(y)}, {static_cast<int32_t>(width), static_cast<int32_t>(height)});
          dc.SetTextForeground(brush.get_solid_brush().color);
          auto hotKeyPrefixLocation = GetFirstHotKeyPrefixLocations(string);
          if (angle == 0) dc.DrawLabel(string, wxRect(x, y, width, height), align, hotKeyPrefix == HKP_SHOW ? hotKeyPrefixLocation : -1);
          else dc.DrawRotatedText(string, x, y, -angle);
          if (!noClip) dc.DestroyClippingRegion();
        }

        static void DrawStringWithGradientBrush(intptr_t handle, const wxString& string, const wxFont& font, const wx_brush& brush, int32_t x, int32_t y, int32_t width, int32_t height, float angle, wxAlignment align, int32_t hotKeyPrefix, bool noClip) {
          auto maxSize = math::max(width, height);
          wxImage image(x + maxSize, y + maxSize);
          if (brush.is_conical_gradiant_brush())
            image = wxConicalGradient::CreateBitmap(wxSize(maxSize, maxSize), brush.get_conical_gradiant_brush().colors, brush.get_conical_gradiant_brush().center_point, brush.get_conical_gradiant_brush().angle).ConvertToImage();
          else {
            image.InitAlpha();
            for (auto y1 = 0; y1 < static_cast<int32_t>(maxSize + y); y1++)
              for (auto x1 = 0; x1 < static_cast<int32_t>(maxSize + x); x1++)
                image.SetAlpha(x1, y1, 0);
            wxBitmap bitmap(image);
            auto bitmapGraphics = wxGraphicsContext::Create(wxMemoryDC(bitmap));
            bitmapGraphics->SetBrush(wx_brush::to_graphics_brush(*reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics(), brush));
            bitmapGraphics->DrawRectangle(0, 0, maxSize + x, maxSize + y);
            image = bitmap.ConvertToImage();
          }
          
          wxBitmap bitmapMask(x + maxSize, y + maxSize);
          wxMemoryDC bitmapMaskDc(bitmapMask);
          bitmapMaskDc.SetFont(font);
          bitmapMaskDc.SetTextForeground(wxColour(255, 255, 255));
          auto hotKeyPrefixLocation = GetFirstHotKeyPrefixLocations(string);
          if (angle == 0) bitmapMaskDc.DrawLabel(string, wxRect(x, y, width, height), align, hotKeyPrefix == HKP_SHOW ? hotKeyPrefixLocation : -1);
          else bitmapMaskDc.DrawRotatedText(string, x, y, -angle);
          
          image.SetMaskFromImage(bitmapMask.ConvertToImage(), 0, 0, 0);
          wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
          if (!noClip) graphics.Clip(x, y, width, height);
          graphics.DrawBitmap(wxBitmap(image), 0, 0, maxSize + x, maxSize + y);
          if (!noClip) graphics.ResetClip();
        }
        
        static wxArrayString FormatString(wxDC& dc, const wxArrayString& strings, int32_t width, int32_t height, int32_t hotKeyPrefix, int32_t trimming, bool directionVertical) {
          if (directionVertical) {
            std::swap(width, height);
            height = std::abs(height);
          }
          auto results = strings;
          for (auto& string : results)
            string = FormatString(dc, string, width, hotKeyPrefix, trimming);
          return results;
        }
        
        static int32_t GetFirstHotKeyPrefixLocations(const wxString& str) {
          if (str.IsEmpty()) return -1;
          for (auto index = 0U; index < str.size() - 1; index++)
            if (str[index] == '&' && str[index + 1] != '&') return static_cast<int32_t>(index);
          return -1;
        }
        
        static int32_t GetTextHeight(wxDC& dc, const wxString& str, const wxFont& font) noexcept {
          auto width = 0;
          auto height = 0;
          MeasureString(dc, str, font, width, height, true);
          return height;
        }

        static int32_t GetTextWidth(wxDC& dc, const wxString& str, const wxFont& font, bool measureTrailingSpaces) noexcept {
          auto width = 0;
          auto height = 0;
          MeasureString(dc, str, font, width, height, measureTrailingSpaces);
          return width;
        }

        static wxString RemoveHotKeyPrefixLocations(const wxString& str) {
          wxString result;
          if (str.IsEmpty() && GetFirstHotKeyPrefixLocations(str) == -1) return str;
          for (auto index = 0U; index < str.size() - 1; index++)
            if (str[index] != '&' || str[index + 1] == '&') result += str[index];
          result += str[str.size() - 1];
          return result;
        }

        static wxString ToString(wxDC& dc, const wxArrayString& strings, const wxFont& font, int32_t width, int32_t height, bool lineLimit, bool directionVertical) {
          wxString result;
          if (directionVertical) {
            std::swap(width, height);
            height = std::abs(height);
          }
          for (auto& string : strings) {
            if (lineLimit && GetTextHeight(dc, result + (string.size() ?  string : wxString(" ")) + "\n", font) > height) break;
            result += (string.size() ?  string : wxString(" ")) + "\n";
          }
          if (result.size() > 0) result.Remove(result.size() - 1);
          return result;
        }

        static wxArrayString WrapText(wxDC& dc, const wxString& string, const wxFont& font, int32_t width, int32_t height, bool directionVertical, bool measureTrailingSpaces) noexcept {
          if (directionVertical) std::swap(width, height);
          auto strings = wxSplit(string, '\n');
          wxArrayString results;

          for (auto sentence : strings) {
            auto words = wxSplit(sentence, ' ');
            if (words.size() == 0) results.push_back(" ");
            else for (auto index = 0U; index < words.size(); ++index) {
              results.push_back(words[index]);
              while (index + 1 < words.size() && GetTextWidth(dc, results[results.size() - 1] + " " + words[index + 1], font, measureTrailingSpaces) <= width)
                results[results.size() - 1] += " " + words[++index];
            }
          }
          return results;
        }
      };
    }
  }
}
