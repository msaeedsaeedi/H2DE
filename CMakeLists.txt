cmake_minimum_required(VERSION 3.30)
project(H2DE VERSION 0.01 DESCRIPTION "Harmony 2D Engine" LANGUAGES CXX)

# Set Environment Variables
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_EXAMPLES OFF)
set(BUILD_TESTS OFF)
set(BUILD_SHARED_LIBS OFF)

# Install Packages
add_subdirectory(external/SFML)
add_subdirectory(external/libconfig)

# Source Files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Create Library
add_library(${PROJECT_NAME} STATIC
    ${SOURCES}
)

# Link SFML
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
        config++
)

# Include Directories in the target
target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/public
    PRIVATE
        ${libconfig_SOURCE_DIR}/lib
        ${SFML_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/private
)

# Set output directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/dist
)

# Add tests
enable_testing()
add_subdirectory(test)
