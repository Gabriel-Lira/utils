# Cmake required
cmake_minimum_required(VERSION 3.21)

# Lib source
set(LIB_NAME ${PROJECT_NAME}_LIB)

add_library(
    ${LIB_NAME} OBJECT

    stream/input/input_stream_buffer.c
    stream/input/input_stream_memory.c
    stream/input/input_stream_type.c

    stream/output/output_stream_buffer.c
    stream/output/output_stream_memory.c
    stream/output/output_stream_type.c
    
    stream/stream_type.c
)

add_library(GALI::utils ALIAS ${LIB_NAME})

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

target_compile_options(
    ${LIB_NAME}

    PRIVATE
    $<$<C_COMPILER_ID:MSVC>:/W4 /Wall>
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

# Run Executable Command
add_custom_target(
    ${PROJECT_NAME}_run 
    COMMAND "$<TARGET_FILE:${PROJECT_NAME}>"
)

# Static Analysis
## Cppcheck
add_custom_target(
    ${PROJECT_NAME}_cppcheck 
    COMMAND cppcheck --project="${CMAKE_BINARY_DIR}/compile_commands.json" -i "${CMAKE_SOURCE_DIR}/test" -I "${CMAKE_SOURCE_DIR}/include" -q --force --cppcheck-build-dir="${CMAKE_SOURCE_DIR}/tools/cppcheck/build"  --enable=missingInclude,information,portability,performance,style,warning
)
