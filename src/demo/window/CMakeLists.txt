cmake_minimum_required(VERSION 3.2)

set(INSTALL_LOCATION bin/window)

project(window)

add_executable(window main.cpp)

target_link_libraries(window common)

install(TARGETS window RUNTIME DESTINATION ${INSTALL_LOCATION})
install(FILES test.txt DESTINATION ${INSTALL_LOCATION})