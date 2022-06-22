/// @todo Remove following includes when xtd::diagnostics::process will used for restart see below..
#if !defined(_WIN32)
#include <unistd.h>
#endif
#include <xtd/io/path.h>
#include <xtd/date_time.h>
#include <xtd/environment.h>
#include <xtd/invalid_operation_exception.h>
#include <xtd/literals.h>
#include <xtd/diagnostics/process.h>
#include <xtd/io/directory.h>
#include <xtd/reflection/assembly.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/application.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/window_messages.h>
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/exception_box.h"
#include "../../../include/xtd/forms/message_box.h"
#include "../../../include/xtd/forms/theme.h"

using namespace std;
using namespace std::chrono;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::forms;
using namespace xtd::reflection;

// Initialize xtd::diagnostics::process::message_box_message_ delegate th show message_box dialog.
// This operation can be done only if xtd.forms lib is present.
struct __init_process_message_box_message__ {
  __init_process_message_box_message__() {
    xtd::diagnostics::process::message_box_message_ = {*this, &__init_process_message_box_message__::__show_message_box__};
  }
  
  void __show_message_box__(const ustring& file_name) {
    xtd::forms::message_box::show(ustring::format("{} cannot find '{}'. Make sure you typed the name correctly, and try again.", xtd::environment::os_version().name(), file_name), file_name, xtd::forms::message_box_buttons::ok, xtd::forms::message_box_icon::error);
  }
  
  void __force_compiler_optimizer_to_create_object__() {
  }
};

__init_process_message_box_message__ __init_process_message_box_message_value__;

namespace {
  using message_filter_ref = std::reference_wrapper<imessage_filter>;
  using message_filter_collection = std::vector<message_filter_ref>;
  
  static message_filter_collection message_filters;
  
  bool message_filter_proc(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t handle) {
    bool block = false;
    
    for (message_filter_ref message_filter : message_filters) {
      block = message_filter.get().pre_filter_message(xtd::forms::message::create(hwnd, msg, wparam, lparam, 0, handle));
      if (block == true) break;
    }
    
    if (!block) {
      for (auto open_form : application::open_forms()) {
        auto message = xtd::forms::message::create(hwnd, msg, wparam, lparam, 0, handle);
        block = open_form.get().pre_process_message(message);
        if (block == true) break;
      }
    }
    
    return block;
  }
}


bool application::use_visual_styles_ = false;
bool application::use_wait_cursor_ = false;
bool application::message_loop_ = false;
bool application::raise_idle_ = false;

event<application, delegate<void(const event_args&)>> application::application_exit;
event<application, delegate<void(const event_args&)>> application::enter_thread_modal;
event<application, delegate<void(const event_args&)>> application::idle;
event<application, delegate<void(const event_args&)>> application::leave_thread_modal;
//event<threading::thread_exception_event_handler> application::thread_exception;
event<application, delegate<void(const event_args&)>> application::thread_exit;

bool application::allow_quit() {
  return native::application::allow_quit();
}

xtd::ustring application::common_app_data_path() {
  xtd::ustring common_app_data_path = io::path::combine({environment::get_folder_path(environment::special_folder::common_application_data), company_name(), product_name(), product_version()});
  if (!io::directory::exists(common_app_data_path))
    io::directory::create_directory(common_app_data_path);
  return common_app_data_path;
}

/*
microsoft::win32::registry_key application::common_app_data_registry() {
  return microsoft::win32::registry::local_machine().create_sub_key("Software").create_sub_key(company_name()).create_sub_key(product_name()).create_sub_key(product_version());
}
 */

xtd::ustring application::company_name() {
  if (assembly::get_executing_assembly().company() == "") return xtd::io::path::get_file_name_without_extension(executable_path());
  return assembly::get_executing_assembly().company();
}

xtd::ustring application::executable_name() {
  return io::path::get_file_name(application::executable_path());
}

xtd::ustring application::executable_path() {
  if (environment::get_command_line_args().size() == 0) return "";
  return environment::get_command_line_args()[0];
}

bool application::message_loop() {
  return  message_loop_;
}

const form_collection application::open_forms() {
  form_collection forms;
  for (auto control : control::top_level_controls_)
    forms.push_back(static_cast<form&>(control.get()));
  return forms;
  
  /*
  vector<reference_wrapper<form>> forms;
  
  for (intptr_t handle : native::application::open_forms()) {
    control& control = control::from_handle(handle);
    forms.push_back(static_cast<form&>(control));
  }
  return forms;
   */
}

xtd::ustring application::product_name() {
  if (assembly::get_executing_assembly().product() == "") return xtd::io::path::get_file_name_without_extension(executable_path());
  return assembly::get_executing_assembly().product();
}

xtd::ustring application::product_version() {
  if (assembly::get_executing_assembly().version() == "") return ustring("0.0.0");
  return assembly::get_executing_assembly().version();
}

xtd::ustring application::startup_path() {
  if (environment::get_command_line_args().size() == 0) return "";
  return io::path::get_directory_name(environment::get_command_line_args()[0]);
}

const xtd::forms::style_sheets::style_sheet& application::style_sheet() noexcept {
  return style_sheets::style_sheet::current_style_sheet();
}

void application::style_sheet(const xtd::forms::style_sheets::style_sheet& value) {
  style_sheets::style_sheet::current_style_sheet(value);
}

const xtd::forms::style_sheets::style_sheet::style_sheets_t& application::style_sheets() noexcept {
  return xtd::forms::style_sheets::style_sheet::style_sheets();
}

const xtd::forms::style_sheets::style_sheet::style_sheet_names_t& application::style_sheet_names() noexcept {
  return xtd::forms::style_sheets::style_sheet::style_sheet_names();
}

const xtd::forms::style_sheets::style_sheet& application::system_style_sheet() noexcept {
  return xtd::forms::style_sheets::style_sheet::system_style_sheet();
}

xtd::ustring application::user_app_data_path() {
  xtd::ustring user_app_data_path = io::path::combine({environment::get_folder_path(environment::special_folder::application_data), company_name(), product_name(), product_version()});
  if (!io::directory::exists(user_app_data_path))
    io::directory::create_directory(user_app_data_path);
  return user_app_data_path;
}

/*
 microsoft::win32::registry_key application::user_app_data_registry() {
   return microsoft::win32::registry::current_user().create_sub_key("Software").create_sub_key(company_name()).create_sub_key(product_name()).create_sub_key(product_version());
 }
 */

bool application::use_visual_styles() {
  return use_visual_styles_;
}

bool application::use_wait_cursor() {
  return use_wait_cursor_;
}

void application::use_wait_cursor(bool use_wait_cursor) {
  if (use_wait_cursor_ != use_wait_cursor) {
    use_wait_cursor_ = use_wait_cursor;
    native::application::use_wait_cursor(use_wait_cursor_);
  }
}

void application::add_message_filter(const imessage_filter& value) {
  message_filters.push_back(const_cast<imessage_filter&>(value));
}

void application::do_events() {
  native::application::do_events();
}

bool application::dark_mode_enabled() {
  return native::application::dark_mode_enabled();
}

bool application::light_mode_enabled() {
  return !dark_mode_enabled();
}

void application::enable_dark_mode() {
  if (application::application::message_loop_ == true) throw invalid_operation_exception("Call application::enable_dark_mode() before application::run()"_t, current_stack_frame_);
  native::application::enable_dark_mode();
}

void application::enable_button_images() {
  if (application::application::message_loop_ == true) throw invalid_operation_exception("Call application::enable_button_images() before application::run()"_t, current_stack_frame_);
  native::application::enable_button_images();
}

void application::enable_light_mode() {
  if (application::application::message_loop_ == true) throw invalid_operation_exception("Call application::enable_light_mode() before application::run()"_t, current_stack_frame_);
  native::application::enable_light_mode();
}

void application::enable_menu_images() {
  if (application::application::message_loop_ == true) throw invalid_operation_exception("Call application::enable_menu_images() before application::run()"_t, current_stack_frame_);
  native::application::enable_menu_images();
}

void application::enable_visual_styles() {
  if (application::application::message_loop_ == true) throw invalid_operation_exception("Call application::enable_visual_styles() before application::run()"_t, current_stack_frame_);
  application::use_visual_styles_ = true;
  native::application::enable_visual_style();
}

void application::exit() {
  cancel_event_args e;
  application::exit(e);
}

void application::exit(cancel_event_args& e) {
  e.cancel(!close_forms());
  if (!e.cancel()) native::application::exit();
}

void application::exit_thread() {
  native::application::exit();
}

xtd::forms::style_sheets::style_sheet application::get_style_sheet_from_name(const xtd::ustring& name) {
  return xtd::forms::style_sheets::style_sheet::get_style_sheet_from_name(name);
}

void application::raise_idle(const event_args& e) {
  raise_idle_ = true;
  auto message = forms::message::create(0, WM_ENTERIDLE, 0, 0);
  wm_enter_idle(message);
}

void application::register_message_loop_callback(message_loop_callback callback) {
}

void application::remove_message_filter(const imessage_filter& value) {
  for (message_filter_collection::iterator iterator = message_filters.begin(); iterator != message_filters.end(); ++iterator) {
    if (&iterator->get() == &value) {
      message_filters.erase(iterator);
      break;
    }
  }
}

void application::restart() {
  native::application::restart(close_forms());
}

void application::run() {
  __init_process_message_box_message_value__.__force_compiler_optimizer_to_create_object__();
  application_context context;
  application::run(context);
}

void application::run(application_context& context) {
  if (application::application::message_loop_ == true) throw invalid_operation_exception("Application already running"_t, current_stack_frame_);

  cursor::current(cursors::default_cursor());
  context.thread_exit += application::on_app_thread_exit;
  native::application::register_message_filter(delegate<bool(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>(message_filter_proc));
  native::application::register_thread_exception(delegate<bool()>(on_app_thread_exception));
  native::application::register_wnd_proc(delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>(application::wnd_proc_));

  application::message_loop_ = true;
  if (context.main_form_ != nullptr) context.main_form().show();
  native::application::run();
  context.thread_exit -= application::on_app_thread_exit;
  application::message_loop_ = false;
}

void application::run(const form& form) {
  application_context context(form);
  application::run(context);
}

void application::theme(const xtd::ustring& theme_name) {
  application::theme(xtd::forms::theme::theme_from_name(theme_name));
}

void application::theme(const xtd::forms::theme& theme) {
  xtd::forms::theme::current_theme(theme);
  
  std::function<void(xtd::forms::control&)> update_control = [&](xtd::forms::control & control) {
    //control.back_color(nullptr);
    //control.fore_color(nullptr);
    control.back_color(control.default_back_color());
    control.fore_color(control.default_fore_color());
    for (auto& child_control : control.controls())
      update_control(child_control.get());
  };
  
  for (auto form : open_forms()) {
    //form.get().back_color(theme_colors::current_theme().control());
    //form.get().fore_color(theme_colors::current_theme().control_text());
    form.get().back_color(form.get().default_back_color());
    form.get().fore_color(form.get().default_fore_color());
    for (auto& child_control : form.get().controls())
      update_control(child_control.get());
    form.get().invalidate(true);
    form.get().refresh();
  }
}

const xtd::forms::theme& application::theme() {
  return xtd::forms::theme::current_theme();
}

const std::vector<xtd::ustring>& application::theme_names() {
  return theme::theme_names();
}

bool application::close_forms() {
  for (auto f : application::open_forms()) {
    form_closing_event_args closing_args;
    f.get().on_form_closing(closing_args);
    if (closing_args.cancel()) return false;
  }
  
  for (auto f : application::open_forms())
    f.get().on_form_closed(form_closed_event_args());
  
  return true;
}

void application::on_app_thread_exit(object& sender, const event_args& e) {
  application::exit_thread();
}

bool application::on_app_thread_exception() {
  try {
    throw;
  } catch (const std::exception& e) {
    return (open_forms().size() > 0 ? exception_box::show(open_forms()[0].get(), e, product_name()) : exception_box::show(e, product_name())) == dialog_result::ok;
  } catch (...) {
    return (open_forms().size() > 0 ? exception_box::show(open_forms()[0].get(), product_name()) : exception_box::show(product_name())) == dialog_result::ok;
  }
}

void application::raise_enter_thread_modal(const event_args& e) {
  application::enter_thread_modal(e);
}

void application::raise_leave_thread_modal(const event_args& e) {
  application::leave_thread_modal(e);
}

intptr_t application::wnd_proc_(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t handle) {
  message message = forms::message::create(hwnd, msg, wparam, lparam, 0, handle);
  wnd_proc(message);
  return message.result();
}

void application::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_ACTIVATEAPP: wm_activate_app(message); break;
    case WM_ENTERIDLE: wm_enter_idle(message); break;
    case WM_QUIT: wm_quit(message); break;
    default: break;
  }
}

void application::wm_activate_app(message& message) {
  for (auto form : open_forms())
    form.get().send_message(form.get().handle(), message.msg(), message.wparam(), message.lparam());
}

void application::wm_enter_idle(message& message) {
  static date_time last_idle_time;
  if (raise_idle_ || duration_cast<milliseconds>((date_time::now() - last_idle_time).ticks()) >= chrono::milliseconds(100)) {
    last_idle_time = date_time::now();
    idle(event_args::empty);
    raise_idle_ = false;
  }
  if (!idle.is_empty()) native::application::do_idle();
  
  for (auto form : open_forms())
    form.get().wnd_proc(message);
}

void application::wm_quit(message& message) {
  thread_exit(event_args::empty);
  application_exit(event_args::empty);
}
