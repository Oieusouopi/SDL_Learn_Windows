cmake_minimum_required(VERSION 3.31)
project(SDL2_PROJECT C)

add_definitions(-DSDL_MAIN_HANDLED)

set(CMAKE_C_STANDARD 23)
set(SDL2_INCLUDE_DIR "C:/mingw_dev_lib/SDL2/include/SDL2")
set(SDL2_LIBRARY_DIR "C:/mingw_dev_lib/SDL2/lib")
set(SDL2_IMAGE_INCLUDE_DIR "C:/mingw_dev_lib/SDL2_IMAGE/include/SDL2")
set(SDL2_IMAGE_LIBRARY_DIR "C:/mingw_dev_lib/SDL2_IMAGE/lib")

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR})

add_executable(SDL2_PROJECT main.c)
target_link_directories(SDL2_PROJECT PRIVATE ${SDL2_LIBRARY_DIR})
target_link_libraries(SDL2_PROJECT SDL2 SDL2main)

add_executable(Aula-2-Close-window Aula-2-Close-window/main.c)
target_link_directories(Aula-2-Close-window PRIVATE ${SDL2_LIBRARY_DIR})
target_link_libraries(Aula-2-Close-window SDL2 SDL2main)

add_executable(Aula-3-Background Aula-3-Background/main.c)
target_link_directories(Aula-3-Background PRIVATE ${SDL2_LIBRARY_DIR})
target_link_directories(Aula-3-Background PRIVATE ${SDL2_IMAGE_LIBRARY_DIR})
target_link_libraries(Aula-3-Background
        SDL2
        SDL2main
        SDL2_image
)
