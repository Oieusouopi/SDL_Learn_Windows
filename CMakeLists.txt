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

add_executable(04-optimized_surface_loading_and_soft_streching 04-optimized_surface_loading_and_soft_streching/main.c
        09-Clip-Rendering-and-Sprite-Sheets/main.c)
target_link_directories(04-optimized_surface_loading_and_soft_streching PRIVATE ${SDL2_LIBRARY_DIR})
target_link_directories(04-optimized_surface_loading_and_soft_streching PRIVATE ${SDL2_IMAGE_LIBRARY_DIR})
target_link_libraries(04-optimized_surface_loading_and_soft_streching
        SDL2
        SDL2main
        SDL2_image
)

add_executable(05_extension_libraries_and_loading_other_image_formats 05_extension_libraries_and_loading_other_image_formats/main.c)
target_link_directories(05_extension_libraries_and_loading_other_image_formats PRIVATE ${SDL2_LIBRARY_DIR})
target_link_directories(05_extension_libraries_and_loading_other_image_formats PRIVATE ${SDL2_IMAGE_LIBRARY_DIR})
target_link_libraries(05_extension_libraries_and_loading_other_image_formats
        SDL2
        SDL2main
        SDL2_image
)

add_executable(06_Geometry_rendering 06_Geometry_rendering/main.c)
target_link_directories(06_Geometry_rendering PRIVATE ${SDL2_LIBRARY_DIR})
target_link_directories(06_Geometry_rendering PRIVATE ${SDL2_IMAGE_LIBRARY_DIR})
target_link_libraries(06_Geometry_rendering
        SDL2
        SDL2main
        SDL2_image
)

add_executable(07_ViewPort 07_ViewPort/main.c)
target_link_directories(07_ViewPort PRIVATE ${SDL2_LIBRARY_DIR})
target_link_directories(07_ViewPort PRIVATE ${SDL2_IMAGE_LIBRARY_DIR})
target_link_libraries(07_ViewPort
        SDL2
        SDL2main
        SDL2_image
)

add_executable(08-color-keying 08-color-keying/main.c 08-color-keying/headers/LTexture.h
        08-color-keying/LTexture.c)
target_link_directories(08-color-keying PRIVATE ${SDL2_LIBRARY_DIR})
target_link_directories(08-color-keying PRIVATE ${SDL2_IMAGE_LIBRARY_DIR})
target_link_libraries(08-color-keying
        SDL2
        SDL2main
        SDL2_image
)

add_executable(09-Clip-Rendering-and-Sprite-Sheets 09-Clip-Rendering-and-Sprite-Sheets/main.c
        09-Clip-Rendering-and-Sprite-Sheets/LTexture/LTexture.c
        09-Clip-Rendering-and-Sprite-Sheets/LTexture/LTexture.h)
target_link_directories(09-Clip-Rendering-and-Sprite-Sheets PRIVATE ${SDL2_LIBRARY_DIR})
target_link_directories(09-Clip-Rendering-and-Sprite-Sheets PRIVATE ${SDL2_IMAGE_LIBRARY_DIR})
target_link_libraries(09-Clip-Rendering-and-Sprite-Sheets
        SDL2
        SDL2main
        SDL2_image
)
add_executable(10-Color-Modulation 10-Color-Modulation/main.c
        10-Color-Modulation/LTexture/LTexture.c
        10-Color-Modulation/LTexture/LTexture.h)
target_link_directories(10-Color-Modulation PRIVATE ${SDL2_LIBRARY_DIR})
target_link_directories(10-Color-Modulation PRIVATE ${SDL2_IMAGE_LIBRARY_DIR})
target_link_libraries(10-Color-Modulation
    SDL2
    SDL2main
    SDL2_image
)

add_executable(11-Alpha-Blending 11-Alpha-Blending/main.c)
target_link_directories(11-Alpha-Blending PRIVATE ${SDL2_LIBRARY_DIR})
target_link_directories(11-Alpha-Blending PRIVATE ${SDL2_IMAGE_LIBRARY_DIR})
target_link_libraries(11-Alpha-Blending
    SDL2
    SDL2main
    SDL2_image
)