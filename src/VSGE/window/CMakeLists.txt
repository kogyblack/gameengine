set (INCROOT ${PROJECT_SOURCE_DIR}/include/VSGE/window)
set (SRCROOT ${PROJECT_SOURCE_DIR}/src/VSGE/window)

# all source files
set(SRC
    ${INCROOT}/window.h
    ${SRCROOT}/window.cpp
    ${INCROOT}/displayMode.h
    ${SRCROOT}/displayMode.cpp
)

# TODO(naum): create a macro like SFML

# create library
add_library(vsge_window ${SRC})
target_link_libraries(vsge_window ${SDL2_LIBRARY})
