/// @file
/// @brief Contains xtd::forms::native::checked_list_box API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../create_params.h"
#include <vector>
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

namespace xtd {
  namespace forms {
    namespace native {
      /// @brief Contains checked list box native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native
      /// @warning Internal use only
      class forms_native_export_ checked_list_box final static_ {
      public:
        /// @brief Maintains performance while items are added to the list_box one at a time by preventing the control from drawing until the end_update() method is called.
        /// @param control Chrecked list box window handle.
        /// @warning Internal use only
        static void begin_update(intptr_t control);
        /// @brief Sets check state to specified item index.
        /// @param control Chrecked list box window handle.
        /// @param index The item index to set the check state for.
        /// @param check_state The check state value : BST_UNCHECKED or BST_CHECKED or BST_INDETERMINATE.
        /// @warning Internal use only
        static void check_state(intptr_t control, size_t index, int32_t check_state);
        /// @brief Gets check state from specified item index.
        /// @param control Chrecked list box window handle.
        /// @return The check state value : BST_UNCHECKED or BST_CHECKED or BST_INDETERMINATE.
        /// @warning Internal use only
        static int32_t check_state(intptr_t control, size_t index);
        /// @brief
        /// @param control Chrecked list box window handle.
        /// @warning Internal use only
        static void delete_item(intptr_t control, size_t index);
        /// @brief
        /// @param control Chrecked list box window handle.
        /// @warning Internal use only
        static void end_update(intptr_t control);
        /// @brief
        /// @param control Chrecked list box window handle.
        /// @warning Internal use only
        static void insert_item(intptr_t control, size_t index, const std::string& value, bool checked);
        /// @brief
        /// @param control Chrecked list box window handle.
        /// @warning Internal use only
        static size_t selected_index(intptr_t control);
        /// @brief
        /// @param control Chrecked list box window handle.
        /// @warning Internal use only
        static void selected_index(intptr_t control, size_t index);
        /// @brief
        /// @param control Chrecked list box window handle.
        /// @warning Internal use only
        static std::vector<size_t> selected_indices(intptr_t control);
        /// @brief
        /// @param control Chrecked list box window handle.
        /// @warning Internal use only
        static void update_item(intptr_t control, size_t index, const std::string& value, bool checked);
      };
    }
  }
}
