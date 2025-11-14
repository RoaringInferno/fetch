#include "scryfall.hpp"

#include <string_view>
#include <string>

#include <simdjson/simdjson.h>
#include <curl/curl.h>

size_t write_file_callback(void* ptr, size_t size, size_t nmemb, void* userdata) {
    std::ofstream* ofs = static_cast<std::ofstream*>(userdata);
    size_t totalSize = size * nmemb;
    ofs -> write(static_cast<char*>(ptr), totalSize);
    return totalSize;
}

int download(
        scryfall_download_result_t &output,
        std::filesystem::path download_directory,
        progress_update_t progress_function
        )
{
    float status{0.0f};
    progress_function(status);
}
