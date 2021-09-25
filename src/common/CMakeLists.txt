cmake_minimum_required(VERSION 3.2)

project(common)

add_library(common logger/Log.cpp demo/Demo.cpp)

target_link_libraries(common ${CONAN_LIBS})