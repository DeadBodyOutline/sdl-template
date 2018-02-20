cmake_minimum_required(VERSION 3.1)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/3rdparty/build)
# or more specific to sdl2:
#set(SDL2_PATH ${CMAKE_SOURCE_DIR}/3rdparty/build)

add_definitions(
    -Werror
    -Wall
)

set(PROJECT_NAME "sdl-template")
project(${PROJECT_NAME})

add_subdirectory(src)
