| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Release Notes

![0.2.0](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/version_0_2_0.png) (beta) Not yet planned

This version is currently in development. See [roadmap](https://github.com/gammasoft71/xtd/blob/master/docs/roadmap.md) to know the list of features and their progress

## Incompatibility list

* xtd::forms::menu and xtd::forms::menu_item are reimplemented as of version 0.2.0 and are not compatible with the previous version. See [Reference Guide](https://codedocs.xyz/gammasoft71/xtd/index.html) and [example](https://github.com/gammasoft71/xtd/tree/master/examples/xtd.forms.examples/menus_and_toolbars/main_menu) for more information.
* Linux and macOS users : if you have cloned and instlled a version 0.2.0 from git before the commit [98d65c9](https://github.com/gammasoft71/xtd/commit/98d65c9810ede427b9f203c20ddc255b45731c77). Delete the "/usr/local/share/xtd/themes" directory before the new installation.
* Windows users : if you have cloned and instlled a version 0.2.0 from git before the commit [98d65c9](https://github.com/gammasoft71/xtd/commit/98d65c9810ede427b9f203c20ddc255b45731c77). Delete the "C:\Program Files (x86)\xtd\share\xtd\themes" directory before the new installation.

## Issues

* ![fixed](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/fixed.png) #16 - WriteFile never sets number_of_bytes_written to -1
* ![fixed](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/fixed.png) #18 - Set xtd::forms::tab_page auto_size(true) after set parent(form) : dump
* ![fixed](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/fixed.png) #19 - operator + and operator - does not build with xtd::delegate
* ![fixed](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/fixed.png) #20 - cannot build unit test project created with xtdc-gui
* ![fixed](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/fixed.png) #25 - xtdc-gui crashes with projects with space in name
* ![fixed](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/fixed.png) #26 - When resizing xtdc-gui, the graphics get messed up
* ![fixed](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/fixed.png) #27 - cannot delete recent projects in xtdc-gui
* ![fixed](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/fixed.png) #31 - xtdc-gui panels redraw over each other
* ![fixed](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/fixed.png) #38 - install.cmd removed items from my windows path
* ![fixed](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/fixed.png) #40 - Problems of installing xtd in Arch linux and distributions that are based on it
* ![fixed](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/fixed.png) #42 - how to redraw Caption bar, or create Caption menu?

## xtd

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) packages (vcpkg, brew, apt) - xtd packages.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) register xtd domain nameProvides the default output methods and behavior for tracing.

## xtd.core

### System

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) box - Represents a boxed object.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) date_time - Represents an instant in time, typically expressed as a date and time of day.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) lock - The lock keyword marks a statement block as a critical section by obtaining the mutual-exclusion lock for a given object, executing a statement, and then releasing the lock. The following example includes a lock statement.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) math - Provides constants and static methods for trigonometric, logarithmic, and other common mathematical functions.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) type - Represents type declarations: class types, interface types, array types, value types, enumeration types, type parameters, generic type definitions, and open or closed constructed generic types.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) uri - Provides an object representation of a uniform resource identifier (URI) and easy access to the parts of the URI.

### IO

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) binary_reader - Reads primitive data types as binary values in a specific encoding.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) binary_writer - Writes primitive types in binary to a stream and supports writing strings in a specific encoding.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) directory - Provides static methods for the creation, copying, deletion, moving, and opening of directories, and aids in the creation of xtd::io::directory_dtream objects.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) directory_info - Exposes instance methods for creating, moving, and enumerating through directories and subdirectories.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) drive_info - Provides access to information on a drive.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) file_info - Provides properties and instance methods for the creation, copying, deletion, moving, and opening of files, and aids in the creation of std::fstream objects.

#### Memory mapped files

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) memory_mapped_file - Represents a memory-mapped file.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) memory_mapped_view_accessor - Represents a randomly accessed view of a memory-mapped file.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) memory_mapped_view_stream - Represents a view of a memory-mapped file as a sequentially accessed stream.

### Media

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) sound_player - Controls playback of a sound from a .wav file.

### Microsoft

#### Win32
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) registry - Provides xtd::microsoft::win32::registry_key objects that represent the root keys in the Windows registry, and static methods to access key/value pairs.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) registry_key - Represents a key-level node in the Windows registry. This class is a registry encapsulation.

### Net

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) web_request - Makes a request to a Uniform Resource Identifier (URI).
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) web_response - Provides a response from a Uniform Resource Identifier (URI).

##### web sockets

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) client_web_socket - Provides a client for connecting to WebSocket services.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) web_socket - The xtd::net::sockets::web_sockets::web_socket class allows applications to send and receive data after the WebSocket upgrade has completed.

### Reflection

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) assembly - Represents an assembly, which is a reusable, versionable, and self-describing building block of a common language runtime application.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) assembly_company_attribute - Defines a company name custom attribute for an assembly manifest.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) assembly_configuration_attribute - Specifies the build configuration, such as retail or debug, for an assembly.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) assembly_copyright_attribute - Defines a copyright copyright attribute for an assembly manifest.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) assembly_culture_attribute - Specifies which culture the assembly supports.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) assembly_description_attribute - Provides a text description for an assembly.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) assembly_file_version_attribute - Instructs a compiler to use a specific version number for the Win32 file version resource. The Win32 file version is not required to be the same as the assembly's version number.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) assembly_guid_attribute - Specifies the guid of the assembly being attributed.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) assembly_identifier_attribute - Specifies the identifier of the assembly being attributed.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) assembly_name_attribute - Specifies a name for an assembly.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) assembly_product_attribute - Defines a product name custom attribute for an assembly manifest.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) assembly_title_attribute - Specifies a title for an assembly.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) assembly_trademark_attribute - Defines a trademark custom attribute for an assembly manifest.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) assembly_version_attribute - Specifies the version of the assembly being attributed.

### Text

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) string_builder - Represents a mutable string of characters.

### Threading

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) auto_reset_event - Notifies a waiting thread that an event has occurred.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) barrier - Enables multiple tasks to cooperatively work on an algorithm in parallel through multiple phases.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) event_wait_handle - Represents a thread synchronization event.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) interlocked - Provides atomic operations for variables that are shared by multiple threads.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) manual_reset_event - Notifies a waiting thread that an event has occurred.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) monitor - Provides a mechanism that synchronizes access to objects.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) mutex - A synchronization primitive that can also be used for interprocess synchronization.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) registered_wait_handle - Represents a handle that has been registered when calling xtd::threading::register_wait_for_single_object.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) semaphore - Limits the number of threads that can access a resource or pool of resources concurrently.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) spin_lock - Provides a mechanism for executing a method at specified intervals.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) thread_local - Provides thread-local storage of data.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) thread_pool - Provides a pool of threads that can be used to post work items, process asynchronous I/O, wait on behalf of other threads, and process timers.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) timer - Provides a mechanism for executing a method at specified intervals.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) timer_callback - Represents the method that handles calls from a xtd::threading::timer.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) wait_callback - Represents a method to be called when a xtd::threading::wait_handle is signaled or times out.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) wait_handle - Encapsulates operating system specific objects that wait for exclusive access to shared resources.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) wait_or_timer_callback - Represents a method to be called when a xtd::threading::wait_handle is signaled or times out.

### Timers

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) timer - Generates an event after a set interval, with an option to generate recurring events.

## xtd.drawing

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) buffered_graphics - Provides a graphics buffer for double buffering.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) region - Describes the interior of a graphics shape composed of rectangles and paths. This class cannot be inherited.

### Drawing 2d

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) conical_gradient_brush - Encapsulates a xtd::drawing::brush with a conical gradient. This class cannot be inherited.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) graphics_path - Defines an object used to draw lines and curves. This class cannot be inherited.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) matrix - Encapsulates a 3-by-3 affine matrix that represents a geometric transform. This class cannot be inherited.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) radial_gradient_brush - Encapsulates a xtd::drawing::brush with a radial gradient. This class cannot be inherited.

## xtd.forms

### Dialog

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) find_dialog - Represents a dialog box that displays find dialog.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) replace_dialog - Represents a dialog box that displays replace dialog.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) find_box - Represents a dialog box that displays find box.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) font_box - Represents a common dialog box that displays a dialog to the user to choose a font from among those installed on the local computer.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) folder_browser_box - Prompts the user to select a folder.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) open_file_box - Displays a standard dialog box that prompts the user to open a file.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) progress_box - Represents a common dialog box that displays progress box.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) replace_box - Represents a dialog box that displays replace box.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) save_file_box - Prompts the user to select a location for saving a file.

### Menus and toolbars

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) context_menu - Represents a shortcut menu.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) context_menu_strip - Represents a shortcut menu.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) menu_strip - Provides a menu system for a form.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) ribbon_bar - Represents a Windows ribbon bar control.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) status_bar - Represents a Windows status bar control.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) status_strip - Represents a Windows status bar control.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) tool_bar - Represents a Windows tool bar control.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) tool_strip - Provides a container for Windows toolbar objects.

### Containers

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) collapsible_panel - Used to group collections of controls in a collapsible panel.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) flow_layout_panel - Used to group collections of fixed aligned controls.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) table_layout_panel - Used to group collections of fixed aligned controls.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) tool_strip_container - Provides panels on each side of the form and a central panel that can hold one or more controls.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) tool_strip_panel - Creates a container within which other controls can share horizontal or vertical space.

### Controls

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) dial - Represents a dial control.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) light_button - Represents a light button control.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) list_view - Represents a Windows list view control, which displays a collection of items that can be displayed using one of four different views.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) masked_text_box - Uses a mask to distinguish between proper and improper user input.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) media_player - Represents a media player control.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) month_calender - Represents a Windows control that enables the user to select a date using a visual monthly calendar display.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) notify_icon - Specifies a component that creates an icon in the notification area.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) property_grid - Provides a user interface for browsing the properties of an object.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) rich_text_box - Represents a Windows rich text box control.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) roller - Represents a roller control.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) tool_tip - Represents a small rectangular pop-up window that displays a brief description of a control's purpose when the user rests the pointer on the control.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) tool_strip_progress_bar - Represents a tool strip progress bar class.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) tree_view - Displays a hierarchical collection of labeled items, each represented by a xtd::forms::tree_node.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) web_browser - Enables the user to navigate Web pages inside your form.

### Components

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) error_provider - Provides a user interface for indicating that a control on a form has an error associated with it
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) file_system_watcher - Listens to the file system change notifications and raises events when a directory, or file in a directory, changes.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) help_provider - Provides pop-up or online Help for controls.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) performance_counter - Represents a Windows NT performance counter component.

### Data

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) binding_navigator - Represents the navigation and manipulation user interface (UI) for controls on a form that are bound to data.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) binding_source - Encapsulates the data source for a form.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) chart - Displays data in a customizable chart.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) data_grid_view - Displays data in a customizable grid.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) data_set - Represents an in-memory cache of data.

### Printing

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) page_setup_dialog - Enables users to change page-related print settings, including margins and paper orientation.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) print_dialog - Lets users select a printer and choose which sections of the document to print from a Windows Forms application.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) print_document - Defines a reusable object that sends output to a printer, when printing from a Windows Forms application.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) print_preview_control - Represents the raw preview part of print previewing from a Windows Forms application, without any dialog boxes or buttons. Most xtd::forms::print_preview_control objects are found on xtd::forms::print_preview_dialog objects, but they do not have to be.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) print_preview_dialog - Represents a dialog box form that contains a xtd::forms::print_preview_control for printing from a Windows Forms application.

### Clipboard and Drag & Drop

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) clipboard - Provides methods to place data on and retrieve data from the system Clipboard. This class cannot be inherited.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) data_format - Provides static, predefined xtd::forms::clipboard format names. Use them to identify the format of data that you store in an xtd::forms::idata_object.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) data_object - Implements a basic data transfer mechanism.

### Style sheets

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) ibox_model - The box model allows you to specify the margin, borders, padding, background color, width and height of a box.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) iimage_model - The image model allows you to specify the alignment  of an image
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) itext_model - The text model allows you to specify the alignment, color, decoration, transformation, and font of a text.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) control - The control selector allows you to specify the box and color of a control.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) style_shet - The xtd::forms::style_sheets::style_sheet allows you to specify an xtd style sheet.

### Renderers

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) box_renderer - Provides methods used to render a box with or without style sheets.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) checked_list_box_renderer - Provides checked list box renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) choice_renderer - Provides choice renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) color_picker_renderer - Provides color picker renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) combo_box_renderer - Provides combo box renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) command_link_button_renderer - Provides link button renderer methods.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) control_renderer - Provides control renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) date_time_picker_renderer - Provides data time picker renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) dial_renderer - Provides dial renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) domain_up_down_renderer - Provides up down renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) dot_matrix_display_renderer - Provides dot matrix display renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) font_picker_renderer - Provides font picker renderer methods.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) form_renderer - Provides form control renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) fourteen_segment_display_renderer - Provides fourteen segment display renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) h_scroll_bar_renderer - Provides horizont scroll bar renderer methods.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) image_renderer - Provides image renderer methods.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) label_renderer - Provides label renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) lcd_label_renderer - Provides lcd label renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) light_button - Provides light button renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) link_label_renderer - Provides link label renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) list_box_renderer - Provides list box renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) list_view_renderer - Provides list view renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) loading_indicator_renderer - Provides loading indicator renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) masked_text_box_renderer - Provides masked text box renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) media_player_renderer - Provides media player renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) month_calendar_renderer - Provides month calendar renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) nine_segment_display_renderer - Provides nine segment display renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) numeric_up_down_renderer - Provides numeric up down renderer methods.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) panel_renderer - Provides panel control renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) picture_box_renderer - Provides picture box renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) progress_bar_renderer - Provides progress bar renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) property_grid_renderer - Provides property grid renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) rich_text_box_renderer - Provides text box renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) roller_renderer - Provides roller renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) sevent_segment_display_renderer - Provides seven segment display renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) sixteen_segment_display_renderer - Provides sixteen segment display renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) splitter_renderer - Provides splitter renderer methods.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) text_renderer - Provides methods used to render a text with style sheets.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) text_box_renderer - Provides text box renderer methods.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) toggle_button_renderer - Provides toggle_button renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) tool_tip_renderer - Provides tool tip renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) tool_strip_progress_bar_renderer - Provides strip progress bar renderer methods.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) toggle_button_renderer - Provides toggle button renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) track_bar_renderer - Provides track bar renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) tree_view_renderer - Provides tree view renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) up_down_button_renderer - Provides up down button renderer methods.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) user_control_renderer - Provides user_Control renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) v_scroll_bar_renderer - Provides vertical scroll bar renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) web_browser_renderer - Provides web browser renderer methods.

## Tools

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) xtd-code - Forms builder and c++ code generator.

## Translations

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) Add new translation languages.

## Themes

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) default - Default theme css files.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) gnome dark - Gnome dark theme css files.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) gnome light - Gnome light theme css files.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) kde dark - kde dark theme css files.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) kde light - kde light theme css files.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) macos dark - macOS dark theme css files.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) macos light - macOS light theme css files.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) symbolic dark - symbolic dark theme css files.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) symbolic light - symbolic light theme css files.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) windows dark - Windows dark theme css files.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) windows light - Windows light theme css files.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) xtd dark - xtd dark theme css files.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) xtd light - xtd light theme css files.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) light - Light color theme css files.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) dark - Dark color theme css files.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) white - White color theme css files.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) black - Black color theme css files.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) blue - Blue color theme css files.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) green - Green color theme css files.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) red - Red color theme css files.

## Toolkits

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) cocoa - Apple AppKit toolkit.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) fltk - FLTK toolkit.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) gtk4 - Gtk4 toolkit.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) qt6 - Qt6 toolkit.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) sdl2 - Sdl2 toolkit.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) win32 - Win32 API toolkit.

## CMake

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) Assembly commands - CMake commands to generate assembly information from the CMakeLists.txt file.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) iOS platforms - Toolchain for iOS devices.

______________________________________________________________________________________________

![0.1.0](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/version_0_1_0.png) (beta) October 10, 2021

* After 3 years of development, we are happy to release the first beta version of xtd. This version contains a lot of functionalities. It is the first of a long serie.
* The essentials are listed below. For more information about all functionalities read the [Reference Guide](https://codedocs.xyz/gammasoft71/xtd/index.html).

## xtd

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) CMake commands - Specific CMake commands to manage project, assembly informations and application properties
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) continuous integration build - Continuous integration build for Windows, MacOS and linux (appveyor, CircleCI and travisCI).
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) documentation - Markdown documentation.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) installation - Install scripts for Windows, macOS and linux.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) packages (vcpkg, brew, apt) - xtd packages.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) project - SourceForge project.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) reference guide -  Online and offline user and developer guide.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) register xtd domain nameProvides the default output methods and behavior for tracing.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) website - https://gammasoft71.wixsite.com/xtdpro

## xtd.core

### System

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) action - Represents a xtd::delegate that has variable parameters and does not return a value.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) argument_exception - The exception that is thrown when one of the arguments provided to a method is not valid.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) argument_null_exception - The exception that is thrown when one of the arguments provided to a method is null.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) argument_out_of_range_exception - The exception that is thrown when one of the arguments provided to a method is out of range.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) arithmetic_exception - The exception that is thrown for errors in an arithmetic, casting, or conversion operation.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) as - Casts a type into another type.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) async_callback - References a method to be called when a corresponding asynchronous operation completes.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) background_color - Sets the background color of the console.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) beep - Represent beep output manipulator class.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) bit_converter - Converts base data types to an std::vector of bytes, and an std::vector of bytes to base data types.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) block_scope - The specified expression is cleared automatically when the scope is ended.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) cdebug - Provides an std::ostream for xtd::diagnostics::debug.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) cnull - Provides a null std::ostream.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) compiler - Represents information about c++ libraries, such as the version and standard identifier.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) console - Represents the standard input, output, and error streams for console applications.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) console_key_info - Specifies the standard keys on a console.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) convert - Represents API to convert base type code.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) convert_pointer - Represents API to convert pointers.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) convert_string - Represents API to convert string containers.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) cpp_language - Represents information about c++ libraries, such as the version and language identifier.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) ctrace - Provides an std::ostream for xtd::diagnostics::trace.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) date_time - Represents an instant in time, typically expressed as a date and time of day.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) delegate - Represents a delegate, which is a data structure that refers to a static method or to a class instance && an instance method of that class.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) divide_by_zero_exception - The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) domain_exception - The exception that is thrown for errors in domain. That is, situations where the inputs are outside of the domain on which an operation is defined..
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) environment - The environment class.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) event - Represents an event.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) foreground_color - Represent foreground color output manipulator class.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) format_exception - The exception that is thrown when the format of an argument does not meet the parameter specifications of the invoked method.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) func - Represents a delegate that has variables parameters and returns a value of the type specified by the result_t type.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) guid - Represents a globally unique identifier (GUID). A GUID is a 128-bit integer (16 bytes) that can be used across all computers and networks wherever a unique identifier is required. Such an identifier has a very low probability of being duplicated.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) index_out_of_range_exception - The exception that is thrown when an attempt is made to access an element of an array with an index that is outside the bounds of the array.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) interface - Represent an interface class.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) invalid_cast_exception - The exception that is thrown for invalid casting or explicit conversion.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) invalid_operation_exception - The exception that is thrown when a method call is invalid for the object's current state.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) invalid_program_exception - The exception that is thrown when a program contains invalid metadata. Generally this indicates a bug in the compiler that generated the program.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) is - Checks if the result of an expression is compatible with a given type.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) length_exception - The exception that is thrown when an attempts to exceed implementation defined length limits for some object.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) literals operators - Used to convert specified value into another.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) lock - The lock keyword marks a statement block as a critical section by obtaining the mutual-exclusion lock for a given object, executing a statement, and then releasing the lock. The following example includes a lock statement.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) math - Provides constants and static methods for trigonometric, logarithmic, and other common mathematical functions.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) nameof - Used to obtain the simple (unqualified) string name of a variable, type, or member.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) not_finit_number_exception - The exception that is thrown when a floating-point value is positive infinity, negative infinity, or Not-a-Number (NaN).
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) not_implemented_exception - The exception that is thrown when a requested method or operation is not implemented.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) not_supported_exception - The exception that is thrown when an invoked method is not supported, or when there is an attempt to read, seek, or write to a stream that does not support the invoked functionality.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) null_pointer_exception - The exception that is thrown when there is an attempt to dereference a null object pointer.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) object - Supports all classes in the xtd class hierarchy and provides low-level services to derived classes.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) object_closed_exception - The exception that is thrown when one of the arguments provided to a method is not valid.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) operating_system - Represents information about an operating system, such as the version and platform identifier.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) operation_canceled_exception - The exception that is thrown in a thread upon cancellation of an operation that the thread was executing.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) overflow_exception - The exception that is thrown when an arithmetic, casting, or conversion operation in a checked context results in an overflow.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) overload - Represents class that use to determine one of const and non const overloaded methods.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) parse - Convert a type into a string.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) platform_not_supported_exception - The exception that is thrown when a feature does not run on a particular platform.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) predicate - Represents a delegate that defines a set of criteria and determines whether the specified object meets those criteria.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) processor - Represents information about a processor, such as the architecture.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) random - Represents a pseudo-random number generator, a device that produces a sequence of numbers that meet certain statistical requirements for randomness.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) reset_color - Represent reset color output manipulator class.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) startup - Defines the entry point to be called when the application loads. Generally this is set either to the main form in your application or to the main procedure that should run when the application starts.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) static - Represent a static object. A static class can't be instantiated (constructors are deleted).
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) system_exception - Defines the base class for predefined exceptions in the xtd namespace.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) tick - Represents a tick (1 tick = 100 nanoseconds).
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) ticks - Represents a tick duration
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) time_out_exception - The exception that is thrown when the time allotted for a process or operation has expired.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) to_string - Convert a specified value into a string with specified format.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) translator - Represents translator class.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) type - Represents type declarations: class types, interface types, array types, value types, enumeration types, type parameters, generic type definitions, and open or closed constructed generic types.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) underflow_exception - The exception that is thrown when an arithmetic, casting, or conversion operation in a checked context results in an underflow.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) unused - It may be used to suppress the "unused variable" or "unused local typedefs" compiler warnings when the variable or typedef can't be removed or commented out, e.g. when some blocks of the code are conditionally activated.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) uri - Provides an object representation of a uniform resource identifier (URI) and easy access to the parts of the URI.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) ustring - Represents text as a sequence of UTF-8 code units.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) version - Represents the version number of an assembly, operating system, or the xtd.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) xml_syntax_exception - The exception that is thrown when there is a syntax error in XML parsing

### Collections

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) any_pair - Implements a std::pair with the key and the value strongly typed to be std::any.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) key_not_found_exception - The exception that is thrown when the key specified for accessing an element in a collection does not match any key in the collection.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) vector_list - Represents a collection of std::any.

#### Specialized

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) string_map - Implements a std::map with the key and the value strongly typed to be strings.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) string_pair - Implements a std::pair with the key and the value strongly typed to be strings.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) string_vector - Represents a collection of strings.

### Diagnostics

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) assert_dialog - Implement an assert dialog box.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) boolean_switch - Provides a simple on/off switch that controls debugging and tracing output.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) console_trace_listener - Directs tracing or debugging output to either the standard output or the standard error stream.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) debug - Provides a set of methods and properties that help you debug the execution of your code.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) debugger - Enables communication with a debugger.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) default_trace_listener - Provides the default output methods and behavior for tracing.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) ostream_trace_listener - Directs tracing or debugging output to a std::ostream, such as std::fstream, std::stream...
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) process - Provides access to local and remote processes and enables you to start and stop local system processes.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) source_filter - Indicates whether a listener should trace a message based on the source of a trace.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) source_switch - Provides a multilevel switch to control tracing and debug output without recompiling your code.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) stack_frame - Provides information about a xtd::diagnostics::stack_frame, which represents a function call on the call stack for the current thread.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) stack_trace - Represents a stack trace, which is an ordered collection of one or more stack frames.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) stopwatch - Provides a set of methods and properties that you can use to accurately measure elapsed time.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) switch_base - Provides an abstract base class to create new debugging and tracing switches.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) trace - Provides a set of methods and properties that help you debug the execution of your code.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) trace_event_cache - Provides trace event data specific to a thread and a process.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) trace_filter - Provides the base class for trace filter implementations.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) trace_listener - Provides the abstract base class for the listeners who monitor trace and debug output.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) trace_listener_collection - Represents a collection of xtd::diagnostics::trace_listener.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) trace_source - Provides a set of methods and properties that enable applications to trace the execution of code and associate trace messages with their source.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) trace_switch - Provides a multilevel switch to control tracing and debug output without recompiling your code.

### IO

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) binary_reader - Reads primitive data types as binary values in a specific encoding.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) binary_writer - Writes primitive types in binary to a stream and supports writing strings in a specific encoding.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) directory - Provides static methods for the creation, copying, deletion, moving, and opening of directories, and aids in the creation of xtd::io::directory_dtream objects.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) directory_info - Exposes instance methods for creating, moving, and enumerating through directories and subdirectories.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) directory_not_found_exception - The exception that is thrown when part of a file or directory cannot be found.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) drive_info - Provides access to information on a drive.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) drive_not_found_exception - The exception that is thrown when trying to access a drive or share that is not available.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) end_of_stream_exception - The exception that is thrown when reading is attempted past the end of a stream.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) file - Provides static methods for the creation, copying, deletion, moving, and opening of files, and aids in the creation of std::fstream objects.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) file_format_exception - The exception that is thrown when the format of an argument does not meet the parameter specifications of the invoked method.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) file_info - Provides properties and instance methods for the creation, copying, deletion, moving, and opening of files, and aids in the creation of std::fstream objects.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) file_load_exception - The exception that is thrown when a managed assembly is found but cannot be loaded.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) file_not_found_exception - The exception that is thrown when an attempt to access a file that does not exist on disk fails.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) io_exception - The exception that is thrown when an I/O error occurs.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) path - Performs operations on std::basic_string instances that contain file or directory path information. These operations are performed in a cross-platform manner.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) path_too_long_exception - The exception that is thrown when a path or file name is longer than the system-defined maximum length.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) stream_reader - Implements a xtd::io::text_reader that reads characters from a byte stream.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) stream_writer - Implements a xtd::io::text_writer for writing characters to a stream.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) string_reader - Implements a xtd::io::text_reader that reads from a string.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) string_writer - Implements a xtd::io::text_writer for writing characters to a string.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) text_reader - Represents a reader that can read a sequential series of characters.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) text_writer - Represents a writer that can write a sequential series of characters.

#### Memory mapped files

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) memory_mapped_file - Represents a memory-mapped file.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) memory_mapped_view_accessor - Represents a randomly accessed view of a memory-mapped file.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) memory_mapped_view_stream - Represents a view of a memory-mapped file as a sequentially accessed stream.

### Media

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) sound_player - Controls playback of a sound from a .wav file.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) system_sound - Represents a system sound type.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) system_sounds - Retrieves sounds associated with a set of Windows operating system sound-event types.

### Microsoft

#### Win32
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) registry - Provides xtd::microsoft::win32::registry_key objects that represent the root keys in the Windows registry, and static methods to access key/value pairs.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) registry_key - Represents a key-level node in the Windows registry. This class is a registry encapsulation.

### Net

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) cookie_exception - The exception that is thrown when an error is made adding a xtd::net::cookie to a xtd::net::cookie_container.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) dns - Provides simple domain name resolution functionality.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) dns_end_point - Represents a network endpoint as a host name or a string representation of an IP address and a port number.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) end_point - Identifies a network address.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) ip_address - Provides an Internet Protocol (IP) address.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) ip_end_point - Represents a network endpoint as an IP address and a port number.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) ip_host_entry - Provides a container class for Internet host address information.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) network_credential - Provides credentials for password-based authentication schemes such as basic, digest, NTLM, and Kerberos authentication.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) protocol_violation_exception - The exception that is thrown when an error is made adding a xtd::net::cookie to a xtd::net::cookie_container.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) socket_address - Stores serialized information from end_point derived classes.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) web_exception - The exception that is thrown when an error is made adding a xtd::net::cookie to a xtd::net::cookie_container.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) web_request - Makes a request to a Uniform Resource Identifier (URI).
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) web_response - Provides a response from a Uniform Resource Identifier (URI).

#### Sockets

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) ip_packet_information - Gets the network interface information that is associated with a call to xtd::net::sockets::socket::receive_message_from or xtd::net::sockets::socket::end_receive_message_from.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) ip_v6_multicast_option - Contains option values for joining an IPv6 multicast group.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) linger_option - Specifies whether a xtd::net::sockets::socket will remain connected after a call to the xtd::net::sockets::socket::close or xtd::net::sockets::tcp_client::close methods and the length of time it will remain connected, if data remains to be sent.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) multicast_option - Contains IPAddress values used to join and drop multicast groups.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) network_stream - Provides the underlying stream of data for network access.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) send_packet_element - Represents an element in a xtd::net::sockets::send_packets_element array.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) socket - Implements the Berkeley sockets interface.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) socket_exception - The exception that is thrown when a socket error occurs.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) socket_information - Encapsulates the information that is necessary to duplicate a xtd::net::sockets::socket.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) tcp_client - Provides client connections for TCP network services.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) tcp_listener - Listens for connections from TCP network clients.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) udp_client - Provides User Datagram Protocol (UDP) network services.

##### web sockets

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) client_web_socket - Provides a client for connecting to WebSocket services.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) web_socket - The xtd::net::sockets::web_sockets::web_socket class allows applications to send and receive data after the WebSocket upgrade has completed.

### Security

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) secure_string - Represents text that should be kept confidential, such as by deleting it from computer memory when no longer needed.

### Text

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) string_builder - Represents a mutable string of characters.

### Threading

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) auto_reset_event - Notifies a waiting thread that an event has occurred.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) barrier - Enables multiple tasks to cooperatively work on an algorithm in parallel through multiple phases.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) event_wait_handle - Represents a thread synchronization event.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) interlocked - Provides atomic operations for variables that are shared by multiple threads.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) manual_reset_event - Notifies a waiting thread that an event has occurred.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) monitor - Provides a mechanism that synchronizes access to objects.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) mutex - A synchronization primitive that can also be used for interprocess synchronization.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) registered_wait_handle - Represents a handle that has been registered when calling xtd::threading::register_wait_for_single_object.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) semaphore - Limits the number of threads that can access a resource or pool of resources concurrently.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) spin_lock - Provides a mechanism for executing a method at specified intervals.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) thread_local - Provides thread-local storage of data.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) thread_pool - Provides a pool of threads that can be used to post work items, process asynchronous I/O, wait on behalf of other threads, and process timers.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) timer - Provides a mechanism for executing a method at specified intervals.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) timer_callback - Represents the method that handles calls from a xtd::threading::timer.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) wait_callback - Represents a method to be called when a xtd::threading::wait_handle is signaled or times out.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) wait_handle - Encapsulates operating system specific objects that wait for exclusive access to shared resources.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) wait_or_timer_callback - Represents a method to be called when a xtd::threading::wait_handle is signaled or times out.

### Timers

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) timer - Generates an event after a set interval, with an option to generate recurring events.

### Web

#### CSS

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) css_reader - Represent a css reader class.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) css_writer - Represent a css writer class.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) property - Represented a css property class.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) property_map - Represent a css property collection.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) selector - Represent a css selector class.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) selector_map - Represent a css selector collection.

## xtd.drawing

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) bitmap - Encapsulates a GDI+ bitmap, which consists of the pixel data for a graphics image and its attributes. A bitmap is an object used to work with images defined by pixel data.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) brush - Defines objects used to fill the interiors of graphical shapes such as rectangles, ellipses, pies, polygons, and paths.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) brushes - brushes for all the standard colors.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) buffered_graphics - Provides a graphics buffer for double buffering.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) color - Represents an ARGB (alpha, red, green, blue) color.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) colors - colors for all the standard colors.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) font - Defines a particular format for text, including font face, size, and style attributes.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) font_family - Defines a group of type faces having a similar basic design and certain variations in styles.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) graphics - Defines an object used to draw lines and curves.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) icon - Represents a Windows icon, which is a small bitmap image that is used to represent an object. Icons can be thought of as transparent bitmaps, although their size is determined by the system.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) image - An abstract base class that provides functionality for the bitmap and metafile descended classes.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) pen - Defines an object used to draw lines and curves.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) pens - pens for all the standard colors.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) point - Represents an ordered pair of integer x- and y-coordinates that defines a point in a two-dimensional plane.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) point_f - Represents an ordered pair of floating-point x- and y-coordinates that defines a point in a two-dimensional plane.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) rectangle - Stores a set of four integers that represent the location and size of a rectangle.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) rectangle_f - Stores a set of four floating-points that represent the location and size of a rectangle.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) size - Stores an ordered pair of integers, which specify a height and width.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) size_f - Stores an ordered pair of floating-point, which specify a height and width.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) solid_brush - Defines a xtd::drawing::brush of a single color. Brushes are used to fill graphics shapes, such as rectangles, ellipses, pies, polygons, and paths.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) string_format - Encapsulates text layout information (such as alignment, orientation and tab stops) display manipulations (such as ellipsis insertion and national digit substitution) and OpenType features.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) system_brushes - Each property of the xtd::drawing::system_brushes class is a xtd::drawing::solid_brush that is the color of a Windows display element.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) system_colors - Each property of the xtd::drawing::system_colors class is a xtd::drawing::color structure that is the color of a Windows display element.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) system_fonts - Specifies the fonts used to display text in Windows display elements.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) system_icons - Each property of the xtd::drawing::system_icons class is an xtd::drawing::icon object for Windows system-wide icons.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) system_images - Each property of the xtd::drawing::system_images class is an xtd::drawing::image object for Windows system-wide images.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) system_pens - Each property of the xtd::drawing::system_pens class is a xtd::drawing::pen that is the color of a Windows display element and that has a width of 1 pixel.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) texture_brush - Each property of the xtd::drawing::texture_brush class is a xtd::drawing::brush object that uses an image to fill the interior of a shape.

### Drawing 2d

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) hatch_brush - Defines a rectangular xtd::drawing::brush with a hatch style, a foreground color, and a background color
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) linear_gradient_brush - Encapsulates a xtd::drawing::brush with a linear gradient.

### Imaging

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) color_palette - Defines an array of colors that make up a color palette. The colors are 32-bit ARGB colors.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) frame_dimension - Provides properties that get the frame dimensions of an image.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) image_format - Specifies the file format of the image
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) property_item - Encapsulates a metadata property to be included in an image file.

### Text

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) font_collection - Provides a base class for installed and private font collections.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) installed_font_collection - Represents the fonts installed on the system.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) private_font_collection - Provides a collection of font families built from font files that are provided by the client application.

## xtd.forms

### Application

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) application - Provides static methods and properties to manage an application, such as methods to start and stop an application, to process Windows messages, and methods to get information about an application.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) application_context - Specifies the contextual information about an application thread.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) application_information - Specifies the application informations.

### Dialog

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) about_dialog - Represents a dialog box that displays about dialog.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) busy_dialog - Represents a dialog box that displays busy dialog.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) color_dialog - Represents a common dialog box that displays available colors along with controls that enable the user to define custom colors.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) exception_dialog - Represents a common dialog box that displays exception dialog.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) find_dialog - Represents a dialog box that displays find dialog.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) folder_browser_dialog - Prompts the user to select a folder.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) font_dialog - Prompts the user to choose a font from among those installed on the local computer.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) input_dialog - Represents a common dialog box that displays input dialog.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) message_dialog - Displays a message window, also known as a dialog box, which presents a message to the user.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) open_file_dialog - Displays a standard dialog box that prompts the user to open a file.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) progress_dialog - Represents a common dialog box that displays progress dialog.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) replace_dialog - Represents a dialog box that displays replace dialog.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) save_file_dialog - Prompts the user to select a location for saving a file.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) about_box - Represents a dialog box that displays about box.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) busy_box - Represents a dialog box that displays busy box.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) color_box - Represents a common dialog box that displays available colors along with controls that enable the user to define custom colors.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) debug_message_box - Displays a dialog box and write debug.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) exception_box - Represents a common dialog box that displays exception box.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) find_box - Represents a dialog box that displays find box.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) folder_browser_box - Prompts the user to select a folder.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) font_box - Prompts the user to choose a font from among those installed on the local computer.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) input_box - Represents a common dialog box that displays input box.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) message_box - Displays a message window, also known as a dialog box, which presents a message to the user.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) open_file_box - Displays a standard dialog box that prompts the user to open a file.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) progress_box - Represents a common dialog box that displays progress box.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) replace_box - Represents a dialog box that displays replace box.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) save_file_box - Prompts the user to select a location for saving a file.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) trace_message_box - Displays a dialog box and write trace.

### Forms

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) debug_form - Represents a form that displays debug form.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) form - Represents a window or dialog box that makes up an application's user interface.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) trace_form - Represents a form that displays trace form.

### Menus and toolbars

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) context_menu - Represents a shortcut menu.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) context_menu_strip - Represents a shortcut menu.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) main_menu - Represents the menu structure of a form.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) menu_strip - Provides a menu system for a form.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) ribbon_bar - Represents a Windows ribbon bar control.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) status_bar - Represents a Windows status bar control.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) status_strip - Represents a Windows status bar control.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) tool_bar - Represents a Windows tool bar control.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) tool_strip - Provides a container for Windows toolbar objects.

### Containers

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) collapsible_panel - Used to group collections of controls in a collapsible panel.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) flow_layout_panel - Used to group collections of fixed aligned controls.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) group_box - Represents a Windows control that displays a frame around a group of controls with an optional caption.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) horizontal_layout_panel - Used to group collections of horizontally aligned controls.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) panel - Used to group collections of controls.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) split_container - Represents a control consisting of a movable bar that divides a container's display area into two resizable panels.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) tab_control - Manages a related set of tab pages.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) tab_page - Represents a single tab page in a tab_control.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) table_layout_panel - Used to group collections of fixed aligned controls.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) tool_strip_container - Provides panels on each side of the form and a central panel that can hold one or more controls.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) tool_strip_panel - Creates a container within which other controls can share horizontal or vertical space.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) vertical_layout_panel - Used to group collections of vertically aligned controls.

### Controls

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) animation - Represents an animation control.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) button - Represents a Windows button control.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) check_box - Represents a Windows check_box.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) checked_list_box - Displays a xtd::forms::list_box in which a check box is displayed to the left of each item.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) choice - Represents a choice control.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) color_picker - Represents a picker control that displays available colors along with controls that enable the user to define custom colors.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) combo_box - Represents a Windows combo box control.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) command_link_button - Represents a Windows command link button control.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) control - Defines the base class for controls, which are components with visual representation.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) date_time_picker - Represents a picker control that displays available date time along with controls.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) dial - Represents a dial control.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) domain_up_down - Represents a Windows spin box (also known as an up-down control) that displays string values.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) dot_matrix_display - Represents a dot matrix display class.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) font_picker - Represents a picker control that displays available fonts along with controls.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) fourteen_segment_display - Represents a nine segment display class.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) h_scroll_bar - Represents a standard Windows horizontal scroll bar.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) label - Represents a standard Windows label.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) lcd_label - Represents a lcd label.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) light_button - Represents a light button control.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) link_label - Represents a Windows label control that can display hyperlinks.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) list_box - Represents a standard Windows list box.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) list_view - Represents a Windows list view control, which displays a collection of items that can be displayed using one of four different views.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) loading_indicator - Represents a loading indicator control.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) masked_text_box - Uses a mask to distinguish between proper and improper user input.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) media_player - Represents a media player control.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) month_calender - Represents a Windows control that enables the user to select a date using a visual monthly calendar display.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) notify_icon - Specifies a component that creates an icon in the notification area.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) nine_segment_display - Represents a nine segment display class.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) numeric_up_down - Represents a standard Windows numeric up down.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) picture_box - Represents a standard Windows picture box.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) progress_bar - Represents a Windows progress bar control.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) property_grid - Provides a user interface for browsing the properties of an object.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) radio_button - Enables the user to select a single option from a group of choices when paired with other xtd::forms::radio_button controls.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) rich_text_box - Represents a Windows rich text box control.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) roller - Represents a roller control.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) seven_segment_display - Represents a seven segment display class.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) sixteen_segment_display - Represents a sixteen segment display class.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) splitter - Represents a splitter control that enables the user to resize docked controls.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) switch_button - Represents a standard Windows switch button.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) text_box - Represents a standard Windows text box.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) toggle_button - Represents a Windows toggle_button.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) tool_tip - Represents a small rectangular pop-up window that displays a brief description of a control's purpose when the user rests the pointer on the control.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) tool_strip_progress_bar - Represents a tool strip progress bar class.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) track_bar - Represents a standard Windows track bar.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) tree_view - Displays a hierarchical collection of labeled items, each represented by a xtd::forms::tree_node.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) up_down_button - Represents a standard Windows up down button.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) user_control - Represents a standard Windows user control.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) v_scroll_bar - Represents a standard Windows horizontal scroll bar.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) web_browser - Enables the user to navigate Web pages inside your form.

### Components

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) background_worker - Executes an operation on a separate thread.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) button_images - Provides a button images factories for use by a button control.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) countries - Provides a collection of xtd::forms::country for all countries in the world.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) country - Represent a country with name, alpha codes, numeric code, emoticon and flag.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) cursor - Represents the image used to paint the mouse pointer.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) cursors - Provides a collection of xtd::forms::cursor objects for use by a Windows Forms application.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) emoticon - Represent a emoticon with name and codepoints.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) emoticons - Provides a collection of xtd::forms:emoticon for all known emoticons.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) error_provider - Provides a user interface for indicating that a control on a form has an error associated with it
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) file_system_watcher - Listens to the file system change notifications and raises events when a directory, or file in a directory, changes.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) help_provider - Provides pop-up or online Help for controls.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) image_list - Provides methods to manage a collection of xtd::drawing::image objects. This class cannot be inherited.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) performance_counter - Represents a Windows NT performance counter component.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) screen - Represents a display device or multiple display devices on a single system.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) settings - Represent settings associate to the application
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) system_texts - Provides a collection of string objects for use by a Windows Forms application.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) timer - Implements a timer that raises an event at user-defined intervals. This timer is optimized for use in Windows Forms applications and must be used in a window.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) use_wait_cursor - Creates a use wait cursor class.

### Data

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) binding_navigator - Represents the navigation and manipulation user interface (UI) for controls on a form that are bound to data.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) binding_source - Encapsulates the data source for a form.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) chart - Displays data in a customizable chart.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) data_grid_view - Displays data in a customizable grid.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) data_set - Represents an in-memory cache of data.

### Printing

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) page_setup_dialog - Enables users to change page-related print settings, including margins and paper orientation.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) print_dialog - Lets users select a printer and choose which sections of the document to print from a Windows Forms application.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) print_document - Defines a reusable object that sends output to a printer, when printing from a Windows Forms application.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) print_preview_control - Represents the raw preview part of print previewing from a Windows Forms application, without any dialog boxes or buttons. Most xtd::forms::print_preview_control objects are found on xtd::forms::print_preview_dialog objects, but they do not have to be.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) print_preview_dialog - Represents a dialog box form that contains a xtd::forms::print_preview_control for printing from a Windows Forms application.

### Clipboard and Drag & Drop

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) clipboard - Provides methods to place data on and retrieve data from the system Clipboard. This class cannot be inherited.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) data_format - Provides static, predefined xtd::forms::clipboard format names. Use them to identify the format of data that you store in an xtd::forms::idata_object.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) data_object - Implements a basic data transfer mechanism.

### Renderers

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) button_renderers - Provides button renderer methods.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) check_box_renderer - Provides check box renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) checked_list_box_renderer - Provides checked list box renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) choice_renderer - Provides choice renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) color_picker_renderer - Provides color picker renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) combo_box_renderer - Provides combo box renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) command_link_button_renderer - Provides link button renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) date_time_picker_renderer - Provides data time picker renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) dial_renderer - Provides dial renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) domain_up_down_renderer - Provides up down renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) dot_matrix_display_renderer - Provides dot matrix display renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) font_picker_renderer - Provides font picker renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) fourteen_segment_display_renderer - Provides fourteen segment display renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) h_scroll_bar_renderer - Provides horizont scroll bar renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) label_renderer - Provides label renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) lcd_label_renderer - Provides lcd label renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) light_button - Provides light button renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) link_label_renderer - Provides link label renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) list_box_renderer - Provides list box renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) list_view_renderer - Provides list view renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) loading_indicator_renderer - Provides loading indicator renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) masked_text_box_renderer - Provides masked text box renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) media_player_renderer - Provides media player renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) month_calendar_renderer - Provides month calendar renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) nine_segment_display_renderer - Provides nine segment display renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) numeric_up_down_renderer - Provides numeric up down renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) picture_box_renderer - Provides picture box renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) progress_bar_renderer - Provides progress bar renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) property_grid_renderer - Provides property grid renderer methods.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) radio_button_renderer - Provides radio button renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) rich_text_box_renderer - Provides text box renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) roller_renderer - Provides roller renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) sevent_segment_display_renderer - Provides seven segment display renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) sixteen_segment_display_renderer - Provides sixteen segment display renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) splitter_renderer - Provides splitter renderer methods.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) switch_button_renderer - Provides switch button renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) text_box_renderer - Provides text box renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) tool_tip_renderer - Provides tool tip renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) tool_strip_progress_bar_renderer - Provides strip progress bar renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) toggle_button_renderer - Provides toggle button renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) track_bar_renderer - Provides track bar renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) tree_view_renderer - Provides tree view renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) up_down_button_renderer - Provides up down button renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) v_scroll_bar_renderer - Provides vertical scroll bar renderer methods.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) web_browser_renderer - Provides web browser renderer methods.

## xtd.tunit

### Tests

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) test - Represents the test.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) test_class - Represents the test class.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) unit_test_base - Represents the test base.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) ostream_unit_test - Represents ostream unit test.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) console_unit_test - Represents console unit test.

### Event listeners

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) event_listener - Represents event listener.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) ostream_event_listener - Represents ostream event listener.

### Assertions

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) assert - Contains generic assertions.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) collection_assert - Contains collection assertions.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) directory_assert - Contains specific directory assertions.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) file_assert - Contains specific file assertions.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) string_assert - Contains specific string assertions.

### Validations

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) valid - Contains generic validations.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) collection_valid - Contains specific collection validations.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) directory_valid - Contains specific directory validations.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) file_valid - Contains specific file validations.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) string_valid - Contains specific string validations.

### Assumptions

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) assume - Contains generic assumptions.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) collection_assume - Contains specific collection assumptions.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) directory_assume - Contains specific directory assumptions.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) file_assume - Contains specific file assumptions.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) string_assume - Contains specific string assumptions.

### Settings

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) tests selection - Contains tests selection settings.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) tests execution - Contains tests execution settings.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) tests output - Contains tests output settings.

## Tools

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) guigen - Guid generator command line tool.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) guigen-gui - Guid generator GUI application.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) sleepfor - Sleep for duration command line tool.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) xtdc - Project management command line tool.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) xtdc-gui - Project management GUI application.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) xtd-code - Forms builder and c++ code generator.

## Translations

* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) english - English language.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) french - French language.

## Themes

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) gnome dark - Gnome dark theme css files.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) gnome light - Gnome light theme css files.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) kde dark - kde dark theme css files.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) kde light - kde light theme css files.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) macos dark - macOS dark theme css files.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) macos light - macOS light theme css files.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) windows dark - Windows dark theme css files.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) windows light - Windows light theme css files.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) xtd dark - xtd dark theme css files.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) xtd light - xtd light theme css files.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) light - Light color theme css files.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) dark - Dark color theme css files.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) white - White color theme css files.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) black - Black color theme css files.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) blue - Blue color theme css files.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) green - Green color theme css files.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) red - Red color theme css files.

## Toolkits

* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) cocoa - Apple AppKit toolkit.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) fltk - FLTK toolkit.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) gtk4 - Gtk4 toolkit.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) qt6 - Qt6 toolkit.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) sdl2 - Sdl2 toolkit.
* ![todo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/todo.png) win32 - Win32 API toolkit.
* ![added](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/releases/status/added.png) wxwidgets - wxWidgets toolkit.

______________________________________________________________________________________________

© 2022 Gammasoft.
