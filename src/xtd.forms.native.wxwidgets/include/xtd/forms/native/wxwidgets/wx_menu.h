#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <limits>
#include <map>
#include <string>
#include <vector>
#include <xtd/convert_string.h>
#include <xtd/ustring.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/native/virtual_keys.h>
#include <wx/app.h>
#include <wx/string.h>
#include <wx/menu.h>
#include <wx/menuitem.h>

namespace xtd {
  namespace forms {
    namespace native {
      class control;
      class menu_item;
      class menu;
      class wx_menu_bar;
      class wx_menu;
      
      enum class wx_menu_item_kind {
        normal = 0,
        check = 1,
        radio = 2,
        drop_down = 3,
        separator = 4,
      };
      
      class wx_menu_item {
        friend xtd::forms::native::control;
        friend xtd::forms::native::menu_item;
        friend xtd::forms::native::menu;
      private:
        wx_menu_item() = default;
        
        wx_menu_item(const xtd::ustring& text, intptr_t image, wx_menu_item_kind kind, bool checked, size_t shortcut) : text_(text), shortcut_(shortcut), image_(image), kind_(kind != wx_menu_item_kind::normal ? kind : (text == "-" ? wx_menu_item_kind::separator : wx_menu_item_kind::normal)), checked_(checked) {}
        
        wx_menu_item(const xtd::ustring& text, const std::vector<wx_menu_item*>& items) : text_(text), items_(items) {}
        wx_menu_item(const xtd::ustring& text, size_t shortcut, const std::vector<wx_menu_item*>& items) : text_(text), shortcut_(shortcut), items_(items) {}
        
        const xtd::ustring& text() const {return text_;}
        size_t shortcut() const {return shortcut_;}
        bool enabled() const {return enabled_;}
        intptr_t image() const {return image_;}
        wx_menu_item_kind kind() const {return kind_;}
        bool checked() const {return checked_;}
        const std::vector<wx_menu_item*>& items() const {return items_;}
        std::vector<wx_menu_item*>& items() {return items_;}
        
        static bool isAboutItem(const xtd::ustring& text) {
          wxString itemText = text;
          itemText.Replace("&", "");
          itemText.Replace(".", "");
          itemText.LowerCase();
          return itemText == "about";
        }
        
        static bool isHelpItem(const xtd::ustring& text) {
          wxString itemText = text;
          itemText.Replace("&", "");
          itemText.Replace(".", "");
          itemText.LowerCase();
          return itemText == "help";
        }
        
        static bool isQuitItem(const xtd::ustring& text) {
          wxString itemText = text;
          itemText.Replace("&", "");
          itemText.Replace(".", "");
          itemText.LowerCase();
          return itemText == "exit" || itemText == "quit";
        }
        
        static bool isPreferencesItem(const xtd::ustring& text) {
          wxString itemText = text;
          itemText.Replace("&", "");
          itemText.Replace(".", "");
          itemText.LowerCase();
          return itemText == "preferences" || itemText == "options";
        }
        
        static bool isWindowItem(const xtd::ustring& text) {
          wxString itemText = text;
          itemText.Replace("&", "");
          itemText.Replace(".", "");
          itemText.LowerCase();
          return itemText == "window";
        }
        
      private:
        friend class wx_menu_bar;
        friend class wx_menu;
        
        static wxWindowID MakeWindowID(const xtd::ustring& text) {
          if (isAboutItem(text)) return wxID_ABOUT;
          if (isQuitItem(text)) return wxID_EXIT;
          if (isPreferencesItem(text)) return wxID_PREFERENCES;
          return wxID_ANY;
        }
        
        static wxItemKind ToItemKind(wx_menu_item_kind kind) {
          std::map<wx_menu_item_kind, wxItemKind> kinds {
            {wx_menu_item_kind::normal, wxITEM_NORMAL},
            {wx_menu_item_kind::check, wxITEM_CHECK},
            {wx_menu_item_kind::radio, wxITEM_RADIO},
            {wx_menu_item_kind::drop_down, wxITEM_DROPDOWN},
            {wx_menu_item_kind::separator, wxITEM_SEPARATOR},
          };
          return kinds[kind];
        }
        
        static xtd::ustring MakeItemText(const xtd::ustring& text, size_t shortcut) {
          using namespace std::literals;
#if defined(__APPLE__)
          if (isAboutItem(text)) return "";
          if (isQuitItem(text)) return "";
          if (isPreferencesItem(text)) return "";
#endif
          if (shortcut == VK_NONE) return text;
          auto key = ""s;
          if ((shortcut & VK_COMMAND_MODIFIER) == VK_COMMAND_MODIFIER) key += (key.empty() ? ""s : "+"s) + "Ctrl"s;
          if ((shortcut & VK_CONTROL_MODIFIER) == VK_CONTROL_MODIFIER) key += (key.empty() ? ""s : "+"s) + "RawCtrl"s;
          if ((shortcut & VK_ALT_MODIFIER) == VK_ALT_MODIFIER) key += (key.empty() ? ""s : "+"s) + "Alt"s;
          if ((shortcut & VK_SHIFT_MODIFIER) == VK_SHIFT_MODIFIER) key += (key.empty() ? ""s : "+"s) + "Shift"s;
          
          shortcut &= ~(VK_COMMAND_MODIFIER|VK_CONTROL_MODIFIER|VK_ALT_MODIFIER|VK_SHIFT_MODIFIER);
          
          if (shortcut >= VK_A && shortcut <= VK_Z) key += (key.empty() ? ""s : "+"s) + static_cast<char>(shortcut);
          else if (shortcut >= VK_0 && shortcut <= VK_9) key += (key.empty() ? ""s : "+"s) + static_cast<char>(shortcut);
          else if (shortcut == VK_BACK) key += (key.empty() ? ""s : "+"s) + "Back"s;
          else if (shortcut == VK_TAB) key += (key.empty() ? ""s : "+"s) + "Tab"s;
          else if (shortcut == VK_CLEAR) key += (key.empty() ? ""s : "+"s) + "Clear"s;
          else if (shortcut == VK_RETURN) key += (key.empty() ? ""s : "+"s) + "Return"s;
          else if (shortcut == VK_ESCAPE) key += (key.empty() ? ""s : "+"s) + "Escape"s;
          else if (shortcut == VK_SPACE) key += (key.empty() ? ""s : "+"s) + "Space"s;
          else if (shortcut == VK_PRIOR) key += (key.empty() ? ""s : "+"s) + "Prior"s;
          else if (shortcut == VK_NEXT) key += (key.empty() ? ""s : "+"s) + "Next"s;
          else if (shortcut == VK_END) key += (key.empty() ? ""s : "+"s) + "End"s;
          else if (shortcut == VK_HOME) key += (key.empty() ? ""s : "+"s) + "Home"s;
          else if (shortcut == VK_LEFT) key += (key.empty() ? ""s : "+"s) + "Left"s;
          else if (shortcut == VK_UP) key += (key.empty() ? ""s : "+"s) + "Up"s;
          else if (shortcut == VK_RIGHT) key += (key.empty() ? ""s : "+"s) + "Right"s;
          else if (shortcut == VK_DOWN) key += (key.empty() ? ""s : "+"s) + "Down"s;
          else if (shortcut == VK_SELECT) key += (key.empty() ? ""s : "+"s) + "Select"s;
          else if (shortcut == VK_PRINT) key += (key.empty() ? ""s : "+"s) + "Print"s;
          else if (shortcut == VK_EXECUTE) key += (key.empty() ? ""s : "+"s) + "Execute"s;
          else if (shortcut == VK_SNAPSHOT) key += (key.empty() ? ""s : "+"s) + "Snapshot"s;
          else if (shortcut == VK_INSERT) key += (key.empty() ? ""s : "+"s) + "Insert"s;
          else if (shortcut == VK_DELETE) key += (key.empty() ? ""s : "+"s) + "Delete"s;
          else if (shortcut == VK_HELP) key += (key.empty() ? ""s : "+"s) + "Help"s;
          else if (shortcut == VK_F1) key += (key.empty() ? ""s : "+"s) + "F1"s;
          else if (shortcut == VK_F2) key += (key.empty() ? ""s : "+"s) + "F2"s;
          else if (shortcut == VK_F3) key += (key.empty() ? ""s : "+"s) + "F3"s;
          else if (shortcut == VK_F4) key += (key.empty() ? ""s : "+"s) + "F4"s;
          else if (shortcut == VK_F5) key += (key.empty() ? ""s : "+"s) + "F5"s;
          else if (shortcut == VK_F6) key += (key.empty() ? ""s : "+"s) + "F6"s;
          else if (shortcut == VK_F7) key += (key.empty() ? ""s : "+"s) + "F7"s;
          else if (shortcut == VK_F8) key += (key.empty() ? ""s : "+"s) + "F8"s;
          else if (shortcut == VK_F9) key += (key.empty() ? ""s : "+"s) + "F9"s;
          else if (shortcut == VK_F10) key += (key.empty() ? ""s : "+"s) + "F10"s;
          else if (shortcut == VK_F11) key += (key.empty() ? ""s : "+"s) + "F11"s;
          else if (shortcut == VK_F12) key += (key.empty() ? ""s : "+"s) + "F12"s;
          else if (shortcut == VK_F13) key += (key.empty() ? ""s : "+"s) + "F13"s;
          else if (shortcut == VK_F14) key += (key.empty() ? ""s : "+"s) + "F14"s;
          else if (shortcut == VK_F15) key += (key.empty() ? ""s : "+"s) + "F15"s;
          else if (shortcut == VK_F16) key += (key.empty() ? ""s : "+"s) + "F16"s;
          else if (shortcut == VK_F17) key += (key.empty() ? ""s : "+"s) + "F17"s;
          else if (shortcut == VK_F18) key += (key.empty() ? ""s : "+"s) + "F18"s;
          else if (shortcut == VK_F19) key += (key.empty() ? ""s : "+"s) + "F19"s;
          else if (shortcut == VK_F20) key += (key.empty() ? ""s : "+"s) + "F20"s;
          else if (shortcut == VK_F21) key += (key.empty() ? ""s : "+"s) + "F21"s;
          else if (shortcut == VK_F22) key += (key.empty() ? ""s : "+"s) + "F22"s;
          else if (shortcut == VK_F23) key += (key.empty() ? ""s : "+"s) + "F23"s;
          else if (shortcut == VK_F24) key += (key.empty() ? ""s : "+"s) + "F24"s;
          return text + "\t" + key;
        }
        
        static std::tuple<wxMenu*, xtd::ustring> MakeMenu(wx_menu_item* menu_item) {
          menu_item->menu_ = new wxMenu();
          auto index = 0;
          
          for (auto* item : menu_item->items()) {
            item->parent_ = menu_item->menu_;
            if (item->items().size() != 0) {
              auto [sub_menu, name] = MakeMenu(item);
              menu_item->menu_->AppendSubMenu(sub_menu, xtd::convert_string::to_wstring(item->text()));
            } else {
              item->item_id = MakeWindowID(item->text());
              item->menu_item_ = menu_item->menu_->Append(wxMenuItem::New(menu_item->menu_, item->item_id, xtd::convert_string::to_wstring(MakeItemText(item->text(), item->shortcut())), L"", ToItemKind(item->kind())));
              item->index_ = index++;
              if (item->image() != 0) item->menu_item_->SetBitmap({*reinterpret_cast<wxImage*>(item->image())});
              if (item->kind() == wx_menu_item_kind::check || item->kind() == wx_menu_item_kind::radio) item->menu_item_->Check(item->checked());
            }
          }
          
          return std::make_tuple(menu_item->menu_, menu_item->text());
        }
        
        xtd::ustring text_;
        size_t shortcut_ = VK_NONE;
        bool enabled_ = true;
        intptr_t image_ = 0;
        wx_menu_item_kind kind_ = wx_menu_item_kind::normal;
        bool checked_ = false;
        std::vector<wx_menu_item*> items_;
        wxMenu* parent_ = nullptr;
        wxMenuItem* menu_item_ = nullptr;
        wxMenu* menu_ = nullptr;
        wxWindowID item_id = 0;
        size_t index_ = std::numeric_limits<size_t>::max();
      };
      
      class wx_menu_bar : public wxMenuBar {
      public:
        wx_menu_bar(const std::vector<wx_menu_item*>& items) : items_(items) {
#if defined(__APPLE__)
          auto has_window_menu = false;
          auto has_help_menu = false;
#endif
          
          for (auto* menu_item : items_) {
            auto [menu, name] = wx_menu_item::MakeMenu(menu_item);
#if defined(__APPLE__)
            if (wx_menu_item::isWindowItem(name)) has_window_menu = true;
            if (wx_menu_item::isHelpItem(name)) {
              has_help_menu = true;
              if (!has_window_menu) {
                has_window_menu = true;
                Append(new wxMenu(), "&Window");
              }          }
#endif
            Append(menu, name);
          }
          
#if defined(__APPLE__)
          if (!has_window_menu) Append(new wxMenu(), "&Window");
          if (!has_help_menu) Append(new wxMenu(), "&Help");
#endif
          add_ids(items_);
        }
        
        bool Destroy() override {
          remove_ids(items_);
          return wxMenuBar::Destroy();
        }
        
        static wx_menu_item* from_id(wxWindowID id) {
          return ids_[id];
        }
        
        const std::vector<wx_menu_item*>& items() const {return items_;}
        
        static wxMenu* find_menu_from_id(wxWindowID id) {
          auto item = ids_[id];
          if (item == nullptr) return nullptr;
          return item->parent_;
        }
        
        static size_t find_index_from_id(wxWindowID id) {
          auto item = ids_[id];
          if (item == nullptr) return std::numeric_limits<size_t>::max();
          return item->index_;
        }
        
        static wxMenuBar* create_default_menu_bar() {
          wxMenuBar* default_menu_bar = new wxMenuBar;
          default_menu_bar->Bind(wxEVT_MENU, &on_exit_menu);
          return default_menu_bar;
        }
        
      private:
        static void on_exit_menu(wxCommandEvent& event) {
          if (event.GetId() == wxID_EXIT) {
            for (auto window : wxTopLevelWindows)
              if (!window->Close())
                return;
            wxTheApp->ExitMainLoop();
          } else event.Skip();
        }
        
        void add_ids(std::vector<wx_menu_item*>& items) {
          for (auto* menu_item : items) {
            if (menu_item->items().size() != 0) add_ids(menu_item->items());
            if (menu_item->menu_item_) ids_[menu_item->menu_item_->GetId()] = menu_item;
          }
        }
        
        void remove_ids(std::vector<wx_menu_item*>& items) {
          for (auto* menu_item : items) {
            if (menu_item->items().size() != 0)
              remove_ids(menu_item->items());
            else
              ids_.erase(menu_item->menu_item_->GetId());
          }
        }
        
        static std::map<wxWindowID, wx_menu_item*> ids_;
        std::vector<wx_menu_item*> items_;
      };
      
      class wx_menu : public wxMenu {
      public:
        wx_menu(const std::vector<wx_menu_item*>& items) : items_(items) {
          for (auto* item : items_) {
            if (item->items().size() != 0) {
              auto [sub_menu, name] = wx_menu_item::MakeMenu(item);
              AppendSubMenu(sub_menu, xtd::convert_string::to_wstring(item->text()));
            } else {
              wxWindowID itemID = wx_menu_item::MakeWindowID(item->text());
              wxMenuItem* menuItem = Append(wxMenuItem::New(this, itemID, xtd::convert_string::to_wstring(wx_menu_item::MakeItemText(item->text(), item->shortcut())), L"", wx_menu_item::ToItemKind(item->kind())));
              if (item->image() != 0) menuItem->SetBitmap({*reinterpret_cast<wxImage*>(item->image())});
              if (item->kind() == wx_menu_item_kind::check || item->kind() == wx_menu_item_kind::radio) menuItem->Check(item->checked());
            }
          }
        }
        
        bool Destroy() {
          delete this;
          return true;
        }
        
      private:
        std::vector<wx_menu_item*> items_;
      };
    }
  }
}

