
cmake_minimum_required (VERSION 2.8.0)
set(CMAKE_BUILD_TYPE "Release")
project (AUD-WS201415)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    LIST(APPEND CMAKE_C_FLAGS "-std=c11 -Wall -Werror")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    LIST(APPEND CMAKE_C_FLAGS "-std=c11 -Wall -Werror")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory (e04)
add_subdirectory (e05)
add_subdirectory (e06)
add_subdirectory (e07)
add_subdirectory (e08)

