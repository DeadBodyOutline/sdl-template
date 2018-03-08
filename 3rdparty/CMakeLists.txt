cmake_minimum_required(VERSION 3.1)

include(ExternalProject)

set(3RDPARTY_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/../dependencies)

ExternalProject_Add(SDL2
    GIT_REPOSITORY https://github.com/SDL-mirror/SDL.git
    GIT_TAG release-2.0.7
    SOURCE_DIR ${3RDPARTY_PREFIX}/SDL
    CMAKE_ARGS -DCMAKE_BUILD_TYPE=Release
        -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_BINARY_DIR}
        -DSDL_SHARED=OFF -DSDL_STATIC=ON -DSDL_STATIC_PIC=ON <SOURCE_DIR>
    BUILD_IN_SOURCE 0
)

ExternalProject_Add(SDL2_image
    GIT_REPOSITORY https://github.com/SDL-mirror/SDL_image.git
    GIT_TAG release-2.0.2
    SOURCE_DIR ${3RDPARTY_PREFIX}/SDL_image
    DEPENDS SDL2
    CONFIGURE_COMMAND ./autogen.sh
        COMMAND ./configure --prefix=${CMAKE_BINARY_DIR} --enable-shared=no
        --enable-static=yes --with-sdl-prefix=${CMAKE_BINARY_DIR}
    BUILD_IN_SOURCE 1
)
