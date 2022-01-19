# Cmake required
cmake_minimum_required(VERSION 3.21)

# Test source
set(TEST_NAME ${PROJECT_NAME}_test)

add_executable(
    ${TEST_NAME}

    src/main.cpp

    src/utils_test.cpp

    src/stream/stream_type_test.cpp
    # src/stream/input/input_stream_type_test.cpp
)

target_include_directories(
    ${TEST_NAME}

    PUBLIC
    ./include
)

target_compile_features(
    ${TEST_NAME}

    PUBLIC
    cxx_std_23
)

target_link_libraries(
    ${TEST_NAME}

    PUBLIC
    ${PROJECT_NAME}_LIB
)

# Run Tests Command
add_custom_target(
    ${TEST_NAME}_run 
    COMMAND "$<TARGET_FILE:${TEST_NAME}>"
)
