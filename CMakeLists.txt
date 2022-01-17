# Cmake required
cmake_minimum_required(VERSION 3.21)

# Project
project(
    GALI_utils
    
    VERSION 0.1
    DESCRIPTION "A general utils lib made by Gabriel Al. Lira (GALI)"
    LANGUAGES 
        C
        CXX
)

# Source
add_subdirectory(src)
add_subdirectory(test)
