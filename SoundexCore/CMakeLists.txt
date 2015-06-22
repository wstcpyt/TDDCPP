set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_library(soundexCore Soundex.cpp)
add_subdirectory(unit_test)