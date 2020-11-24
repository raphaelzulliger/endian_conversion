cmake_minimum_required(VERSION 3.0.0)
project(endian_fpr)

SET(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(endian_fpr endian_fpr.cpp)
target_link_libraries(endian_fpr ${CONAN_LIBS})
