#pragma once

#include "progress.hpp"

struct scryfall_download_result_t {
    std::filesystem::path json_path;
};
struct scryfall_download_opts_t {
};
int download(
        scryfall_download_result_t &output,
        std::filesystem::path download_directory,
        progress_update_t progress_function,
        scryfall_download_opts_t opts = {}
        );
