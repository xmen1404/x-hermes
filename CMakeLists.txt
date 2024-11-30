cmake_minimum_required(VERSION 3.22)

project (x-hermes)

# env path
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/build/build/Release/generators")

# core implementation
add_subdirectory(core/network)
add_subdirectory(core/config)

# tests
include(CTest)
enable_testing()

add_subdirectory(test/benchmark)
add_subdirectory(test/unit_test)



