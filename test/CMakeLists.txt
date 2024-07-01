# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Include
include(GoogleTest)

# Generate Test Files
add_executable(${PROJECT_NAME}_test test_main.cpp src/temp_test.cpp)
target_link_libraries(${PROJECT_NAME}_test ${GTEST_LIBRARIES} pthread)
gtest_discover_tests(${PROJECT_NAME}_test)

# Set output directory
set_target_properties(${PROJECT_NAME}_test PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/test
)
