cmake_minimum_required(VERSION 3.10)

project(IMUSim LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---------------------------------
# Build a static library for shared code
# ---------------------------------
file(GLOB_RECURSE IMUSIM_SOURCES "src/*.cpp")

# Remove main.cpp from the library (so tests don't pull a main)
list(REMOVE_ITEM IMUSIM_SOURCES "${CMAKE_SOURCE_DIR}/src/main.cpp")

add_library(imusim_lib ${IMUSIM_SOURCES})
target_include_directories(imusim_lib PUBLIC "${CMAKE_SOURCE_DIR}/include")

# ---------------------------------
# Main executable
# ---------------------------------
add_executable(imusim src/main.cpp)
target_link_libraries(imusim imusim_lib)

# ---------------------------------
# GoogleTest / Unit tests
# ---------------------------------
add_subdirectory(extern/googletest googletest_build)
enable_testing()

file(GLOB TEST_SOURCES "tests/*.cpp")

add_executable(runTests ${TEST_SOURCES})
target_include_directories(runTests PRIVATE "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(runTests gtest gtest_main imusim_lib)

add_test(NAME AllTests COMMAND runTests)
