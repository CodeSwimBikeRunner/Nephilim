# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("Nephilim")

# setting CMAKE module path for cmake scripts currently for
# SDL2 and SDL_image
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# setting sdl2_image locations pita.
set(SDL2_IMAGE_DIR ${PROJECT_SOURCE_DIR}/SDL2_image)
set(SDL2_IMAGE_LIBRARY ${PROJECT_SOURCE_DIR}/SDL2_image/lib/x86/SDL2_image.lib)
set(SDL2_IMAGE_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/SDL2_image/include)

# setting sdl2 locations pita.
set(SDL2_LIBRARY ${PROJECT_SOURCE_DIR}/SDL2/lib/x86/SDL2.lib)
set(SDL2_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/SDL2/include)
set(SDL2MAIN_LIBRARY ${PROJECT_SOURCE_DIR}/SDL2/lib/x86/SDL2main.lib)


find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_DIRS})

add_executable(neph WIN32 "neph/neph.c")
target_link_libraries(neph ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})


add_custom_command(TARGET neph POST_BUILD
     COMMAND ${CMAKE_COMMAND} -E copy_if_different
         "${PROJECT_SOURCE_DIR}/SDL2/lib/x86/SDL2.dll"
         "${PROJECT_SOURCE_DIR}/SDL2_image/lib/x86/SDL2_image.dll"
         $<TARGET_FILE_DIR:neph>)
