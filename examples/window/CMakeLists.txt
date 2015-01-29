set(SRCROOT ${PROJECT_SOURCE_DIR}/examples/window)

# all source files
set(SRC
    ${SRCROOT}/window.cpp
)

# TODO(naum): Create macro like SFML
add_executable(window ${SRC})
target_link_libraries(window ${SDL2_LIBRARY})
target_link_libraries(window vsge_window)
