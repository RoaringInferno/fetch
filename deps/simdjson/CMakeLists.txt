# simdjson
message(STATUS "Fetching simdjson ...")
FetchContent_Declare(
    simdjson
    GIT_REPOSITORY https://github.com/simdjson/simdjson.git
    GIT_TAG        v4.0.7
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
    EXCLUDE_FROM_ALL
)
FetchContent_MakeAvailable(simdjson)

target_link_libraries(${EXEC_NAME}
    PRIVATE simdjson
)

