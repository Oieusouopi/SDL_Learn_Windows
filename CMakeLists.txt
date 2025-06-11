cmake_minimum_required(VERSION 3.31)
project(SDL2_PROJECT C)

add_definitions(-DSDL_MAIN_HANDLED)

set(CMAKE_C_STANDARD 23)
set(SDL2_INCLUDE_DIR "C:/mingw_dev_lib/include/SDL2")
set(SDL2_LIBRARY_DIR "C:/mingw_dev_lib/lib")

include_directories(${SDL2_INCLUDE_DIR})

add_executable(SDL2_PROJECT main.c)

target_link_directories(SDL2_PROJECT PRIVATE ${SDL2_LIBRARY_DIR})
target_link_libraries(SDL2_PROJECT SDL2 SDL2main)
