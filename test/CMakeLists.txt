# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Include
include(GoogleTest)

# Source Files
file(GLOB_RECURSE TEST_SOURCES "*.cpp")

# Create Executable
add_executable(${PROJECT_NAME}_test ${TEST_SOURCES})

# Include Directories
target_include_directories(${PROJECT_NAME}_test PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include/private
)

# Link Libraries
target_link_libraries(${PROJECT_NAME}_test ${GTEST_LIBRARIES} ${PROJECT_NAME} pthread config++ sfml-graphics sfml-window sfml-system)
gtest_discover_tests(${PROJECT_NAME}_test 
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin/test
)

# Set output directory
set_target_properties(${PROJECT_NAME}_test PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/test
)
