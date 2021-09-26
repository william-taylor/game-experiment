cmake_minimum_required(VERSION 3.20)
project(opengl-workbench)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_INSTALL_PREFIX ..)

include(conanbuildinfo.cmake)
conan_basic_setup()

# Sub projects
add_subdirectory(src/common)
add_subdirectory(src/demo/triangle)
