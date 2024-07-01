cmake_minimum_required(VERSION 3.22)
project(MyProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Include Header Files
include_directories(include)

# Source Files
set(SOURCE
    src/main.cpp
)

# Add your source files
add_executable(${PROJECT_NAME} ${SOURCE})

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/dist
)

# Add tests
enable_testing()
add_subdirectory(test)
