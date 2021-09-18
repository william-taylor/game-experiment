cmake_minimum_required(VERSION 3.2)

project(window)

add_executable(window main.cpp)

target_link_libraries(window ${CONAN_LIBS})

install(TARGETS window RUNTIME DESTINATION bin)