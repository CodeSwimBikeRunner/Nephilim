set(N_OBSERVER_SOURCES "src/observer.c"
                    "src/subject.c"
                    )

add_library(n_observer ${N_OBSERVER_SOURCES})

install(TARGETS n_observer ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR})