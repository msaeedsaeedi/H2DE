cmake_minimum_required(VERSION 3.30)
project(H2DE VERSION 0.01 DESCRIPTION "Harmony 2D Engine" LANGUAGES CXX)

# Set Environment Variables
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_SHARED_LIBS OFF)

# Install Packages
find_package(SFML 2.6.1 COMPONENTS graphics window system REQUIRED)
find_package(libconfig REQUIRED)

# Include Header Files
include_directories(include/public)
include_directories(include/private)

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
        ${libconfig_SOURCE_DIR}/lib
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/private
)

# Set output directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/dist
)

# Add tests
enable_testing()
add_subdirectory(test)
