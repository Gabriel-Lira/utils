# Cmake required
cmake_minimum_required(VERSION 3.21)

# Lib source
set(LIB_NAME ${PROJECT_NAME}_LIB)

add_library(
    ${LIB_NAME} STATIC

    stream/input/input_stream_buffer.c
    stream/input/input_stream_memory.c
    stream/input/input_stream_type.c

    stream/output/output_stream_buffer.c
    stream/output/output_stream_type.c
)

target_compile_features(
    ${LIB_NAME}

    PUBLIC
    c_std_11
)

target_include_directories(
    ${LIB_NAME}

    PUBLIC
    ../include
)

# Executable source
add_executable(
    ${PROJECT_NAME}

    main.c
)

target_link_libraries(
    ${PROJECT_NAME}

    PUBLIC
    ${LIB_NAME}
)
