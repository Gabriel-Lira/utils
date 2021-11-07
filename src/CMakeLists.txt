cmake_minimum_required(VERSION 3.21)

add_executable(
    ${PROJECT_NAME}

    main.c
)

target_compile_features(
    ${PROJECT_NAME}

    PUBLIC
    c_std_11
)

target_include_directories(
    ${PROJECT_NAME}

    PUBLIC
    ../include
)
