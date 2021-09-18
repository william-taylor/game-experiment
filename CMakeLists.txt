cmake_minimum_required(VERSION 3.20)
project(basic_game)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_INSTALL_PREFIX ..)

include(conanbuildinfo.cmake)
conan_basic_setup()

add_executable(basic_game src/main.cpp src/core/Game.cpp src/core/Game.h)
target_link_libraries(basic_game ${CONAN_LIBS})
install(TARGETS basic_game RUNTIME DESTINATION bin)