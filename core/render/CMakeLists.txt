set(N_RENDER_SOURCES 
            "src/render.c"
            )

add_library(n_render ${N_RENDER_SOURCES})

install(TARGETS n_render ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR})