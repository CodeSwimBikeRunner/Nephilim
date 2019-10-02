# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("Nephilim")

# setting properties based on OS
if(WIN32)
    if("$ENV{PROCESSOR_ARCHITECTURE}" STREQUAL "x86")
        set(LIB_SWITCHER "x86")
    else()
        set(LIB_SWITCHER "x64")
    endif()
endif()
message(${LIB_SWITCHER})

# setting CMAKE module path for cmake scripts.
# Currently:
# SDL2 
# SDL2_image
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# setting sdl2_image locations pita.
set(SDL2_IMAGE_DIR ${PROJECT_SOURCE_DIR}/SDL2_image)
set(SDL2_IMAGE_LIBRARY ${PROJECT_SOURCE_DIR}/SDL2_image/lib/${LIB_SWITCHER}/SDL2_image.lib)
set(SDL2_IMAGE_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/SDL2_image/include)

# setting sdl2 locations pita.
set(SDL2_LIBRARY ${PROJECT_SOURCE_DIR}/SDL2/lib/${LIB_SWITCHER}/SDL2.lib)
set(SDL2_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/SDL2/include)

# setting sdl2main.
if(WIN32)
    set(SDL2MAIN_LIBRARY ${PROJECT_SOURCE_DIR}/SDL2/lib/${LIB_SWITCHER}/SDL2main.lib)
    set(WINTHREAD_LIBRARY ${PROJECT_SOURCE_DIR}/WinThread/lib/${LIB_SWITCHER}/pthreadVC2.lib)
endif()
# find required packages
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_INCLUDE_DIR})

# setting asset directory
set(ASSET_DIRECTORY "${PROJECT_SOURCE_DIR}/assets")

# add subdirectories
add_subdirectory("core/render")
add_subdirectory("core/observer")
# begin creating executable and linking.
# add_custom_target(
#    corange
#    COMMAND make
#    WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/corange"
# )
# add_executable(myexecutable myexcutable.c)
# target_link_libraries(myexecutable full_path_to_generated_library)
# add_dependencies(myexecutable extern_lib)

# add_custom_command(
#     OUTPUT ${PROJECT_SOURCE_DIR}/corange
#     COMMAND make
#     WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/corange
#     )
 
#  add_custom_target(
#     corange
#     DEPENDS ${PROJECT_SOURCE_DIR}/corange
#     )
 
#  add_executable(myexecutable myexcutable.c)
 
#  target_link_libraries(myexecutable full_path_to_generated_library)
 
#  add_dependencies(myexecutable extern_lib)
######################################################################
######                    Windows Defintion                     ######
######################################################################
if(WIN32)
    add_executable(neph "n_main/main.c")
    target_link_libraries(neph n_render n_observer ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${WINTHREAD_LIBRARY})
    # target_link_libraries(neph n_render n_observer ${PROJECT_SOURCE_DIR}/corange ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${WINTHREAD_LIBRARY})
    # add_dependencies(neph corange)

    add_custom_command(TARGET neph POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${PROJECT_SOURCE_DIR}/SDL2/lib/${LIB_SWITCHER}/SDL2.dll"
            "${PROJECT_SOURCE_DIR}/SDL2_image/lib/${LIB_SWITCHER}/SDL2_image.dll"
            "${PROJECT_SOURCE_DIR}/SDL2_image/lib/${LIB_SWITCHER}/libjpeg-9.dll"
            "${PROJECT_SOURCE_DIR}/WinThread/dll/${LIB_SWITCHER}/pthreadVC2.dll"
            $<TARGET_FILE_DIR:neph>)
endif()            

######################################################################
######                    Linux Defintion                       ######
######################################################################

######################################################################
######                    OSX Defintion                         ######
######################################################################

######################################################################
######                    Android Defintion                     ######
######################################################################

######################################################################
######                    iOS Defintion                         ######
######################################################################


# copy assets to build output and debug output
add_custom_command(TARGET neph POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${ASSET_DIRECTORY}/design.png"
            $<TARGET_FILE_DIR:neph>)