set(N_CHAR_SOURCES "src/ranger.c"
                    "src/fighter.c"
                    "src/acolyte.c"
                    "src/sorcerer.c"
                    "src/ancient.c"
                    "src/astral.c")

add_library(n_characters ${N_CHAR_SOURCES})

install(TARGETS n_characters ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR})