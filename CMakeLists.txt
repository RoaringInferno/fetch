cmake_minimum_required(VERSION 3.21.0)

project(fetch
    VERSION 0.0.0
)
set(CMAKE_CXX_STANDARD 20)

set(EXEC_NAME fetch)

add_executable(${EXEC_NAME})

add_subdirectory(deps)
add_subdirectory(src)

target_compile_definitions(${EXEC_NAME} PRIVATE
    KVERSION_MAJOR=${PROJECT_VERSION_MAJOR}
    KVERSION_MINOR=${PROJECT_VERSION_MINOR}
    KVERSION_PATCH=${PROJECT_VERSION_PATCH}
)
