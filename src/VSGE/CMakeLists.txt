# add VSGE source paths
#include_directories(${PROJECT_SOURCE_DIR}/src)

# set the output directory for VSGE libraries
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# add module subdirectories
add_subdirectory(window)
