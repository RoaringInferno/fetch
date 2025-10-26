#pragma once

#include "progress.hpp"

struct scryfall_download_result_t {
    std::filesystem::path json_path;
};
int download(
        scryfall_download_result_t &output,
        std::filesystem::path directory,
        progress_update_t progress
        );
