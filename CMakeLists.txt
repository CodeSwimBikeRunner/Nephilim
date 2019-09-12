# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("Nephilim")
set(PROJECT_NAME "Nephilim")
# TODO:: Set the Relase version of the suite to provide maximum optimization Wall flags etc.

# Include sub-projects.
add_subdirectory ("neph")

# Include the libraries
# add_subdirectory ("n_core")
# add_subdirectory ("n_common")
# add_subdirectory ("n_characters")
# add_subdirectory ("n_skills")
# add_subdirectory ("n_gear")
# add_subdirectory ("n_enemies")
# add_subdirectory ("n_maps")
# add_subdirectory ("n_gameplay")
# add_subdirectory ("n_state")
# add_subdirectory ("n_models")
# add_subdirectory ("n_animations")
# add_subdirectory ("n_sounds")
# add_subdirectory ("n_render")

add_subdirectory ("SDL2")