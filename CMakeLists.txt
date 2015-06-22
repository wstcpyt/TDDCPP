cmake_minimum_required(VERSION 3.1)
project(TDDCPP)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules)

enable_testing()

include(gmock)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(SoundexCore)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(TDDCPP ${SOURCE_FILES})


set(CONFIGURED_ONCE TRUE CACHE INTERNAL
    "A flag showing that CMake has configured at least once.")