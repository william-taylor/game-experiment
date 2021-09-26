cmake_minimum_required(VERSION 3.2)

set(INSTALL_LOCATION bin/triangle)

project(triangle)

add_executable(triangle main.cpp)

target_link_libraries(triangle common)

install(TARGETS triangle RUNTIME DESTINATION ${INSTALL_LOCATION})
install(FILES shaders/fragment.glsl DESTINATION ${INSTALL_LOCATION}/shaders)
install(FILES shaders/vertex.glsl DESTINATION ${INSTALL_LOCATION}/shaders)