#pragma once

#include "progress.hpp"

#include <string_view>

// The .fetch directory contains global settings and the card database.
// The directory itself is used for deck-specific data storage.
// Every directory passed to a function should be the parent directory
// (not including the ".fetch")
// Assume every function appends ".fetch/" to every path.
// e.x. pass "~/" instead of "~/.fetch/".
constexpr std::string_view appdata_dirname{".fetch"};
struct card_database_t {
};
int load_card_database(
        card_database_t &output,
        std::filesystem::path directory,
        progress_update_t progress
        );
