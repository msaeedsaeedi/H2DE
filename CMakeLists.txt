cmake_minimum_required(VERSION 3.30)
project(H2DE VERSION 0.01 DESCRIPTION "Harmony 2D Engine" LANGUAGES CXX)

# Set Environment Variables
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_SHARED_LIBS OFF)
set(BUILD_EXAMPLES OFF)
set(BUILD_TESTS OFF)

# Include FetchContent
include(FetchContent)
Set(FETCHCONTENT_QUIET FALSE)

# Install SFML
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML
    GIT_TAG        2.6.1
    GIT_PROGRESS   TRUE
)
include_directories(${SFML_SOURCE_DIR}/include)
FetchContent_MakeAvailable(sfml)

# Install Libconfig++
FetchContent_Declare(
  libconfig
  GIT_REPOSITORY https://github.com/hyperrealm/libconfig.git
  GIT_TAG        v1.7.3
)
set(BUILD_EXAMPLES OFF)
FetchContent_MakeAvailable(libconfig)

# Include Header Files
include_directories(include)

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
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${libconfig_SOURCE_DIR}/lib
)

# Set output directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/dist
)

# Add tests
enable_testing()
add_subdirectory(test)
