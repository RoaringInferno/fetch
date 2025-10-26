include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED OFF)
set(FETCHCONTENT_QUIET OFF)

add_subdirectory(ftxui)
add_subdirectory(curl)
add_subdirectory(simdjson)
