#pragma once

#include <functional>
#include <filesystem>

// A function that updates the progress bar Element
// under the pointer with a new float value.
// Pointer is void for compile speed.
using progress_update_t = std::function<void(float)>;

progress_update_t make_progress_update_t(void *progress_bar_ptr);
