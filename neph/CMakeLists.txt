cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (neph WIN32 "neph.c" "neph.h")

include_directories(${CMAKE_INSTALL_PREFIX}/SDL2)

target_link_libraries(neph SDL2)
target_link_libraries(neph SDL2main)