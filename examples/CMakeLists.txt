# NOTE(naum): Changing runtime output directory while
#             we have no install
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

# add examples subdirectories
add_subdirectory(window)
