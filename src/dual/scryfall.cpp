#include "scryfall.hpp"

int download(
        scryfall_download_result_t &output,
        std::filesystem::path directory,
        progress_update_t update_progress
        )
{
    float status{0.0f};
    update_progress(status);
}
