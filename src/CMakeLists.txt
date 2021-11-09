# Cmake required
cmake_minimum_required(VERSION 3.21)

# Lib source
set(LIB_NAME ${PROJECT_NAME}_LIB)

add_library(
    ${LIB_NAME} STATIC

    stream/input_stream_buffer.c
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
