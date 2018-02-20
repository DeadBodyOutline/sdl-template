set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

# FindSDL2.cmake provided by https://github.com/tcbrindle/sdl2-cmake-scripts
set(CMAKE_MODULE_PATH
    ${CMAKE_SOURCE_DIR}/cmake/modules ${CMAKE_MODULE_PATH})

# SDL2 stuff
find_package(SDL2 REQUIRED)
if(SDL2_FOUND)
    include_directories(${SDL2_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})
elseif(NOT SDL2_FOUND)
    set(SDL2_PATH "" CACHE PATH "SDL2 installation path")
    message("\n-> SDL2 directory not found. Set SDL2_PATH to SDL2 installation path (containing \"include\", \"lib\", directories).")
endif(SDL2_FOUND)

# additional linking
target_link_libraries(${PROJECT_NAME} dl)
