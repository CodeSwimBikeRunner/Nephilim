cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (neph WIN32 "neph.c" "neph.h")

include_directories(${CMAKE_INSTALL_PREFIX}/SDL2)

add_custom_command(TARGET neph POST_BUILD
     COMMAND ${CMAKE_COMMAND} -E copy_if_different
         "${ROOT_PROJECT_DIR}/Build/SDL2/SDL2d.dll"
         $<TARGET_FILE_DIR:neph>)

add_custom_command(TARGET neph POST_BUILD
     COMMAND ${CMAKE_COMMAND} -E copy_if_different
         "${ROOT_PROJECT_DIR}/Build/SDL2/SDL2maind.lib"
         $<TARGET_FILE_DIR:neph>)
         
target_link_libraries(neph SDL2)
target_link_libraries(neph SDL2main)