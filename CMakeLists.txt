cmake_minimum_required(VERSION 3.20)
project(cs106l_spring_2025 LANGUAGES CXX)

add_executable(simple_enroll assignment1/main.cpp)
target_compile_features(simple_enroll PRIVATE cxx_std_20)
set_target_properties(simple_enroll PROPERTIES CXX_EXTENSIONS OFF)

add_executable(marriage_pact assignment2/main.cpp)
target_compile_features(marriage_pact PRIVATE cxx_std_20)
set_target_properties(marriage_pact PROPERTIES CXX_EXTENSIONS OFF)

# Spring 2025 A3 starter: f318ccdea16c4700f2dfcfc7737d99ec8288ea94
add_executable(make_a_class
    assignment3/main.cpp
    assignment3/class.cpp
    assignment3/class.h
    assignment3/sandbox.cpp
)
# main.cpp includes sandbox.cpp; expose it to the IDE without compiling it twice.
set_source_files_properties(assignment3/sandbox.cpp PROPERTIES HEADER_FILE_ONLY TRUE)
target_compile_features(make_a_class PRIVATE cxx_std_20)
set_target_properties(make_a_class PROPERTIES CXX_EXTENSIONS OFF)

# Spring 2025 A4 starter: d24b18fd658b4b30c40b8b65b7b334a10928f6cf
add_executable(ispell
    assignment4/main.cpp
    assignment4/spellcheck.cpp
    assignment4/spellcheck.h
    assignment4/utils.cpp
)
# spellcheck.cpp includes utils.cpp; do not compile the helper file twice.
set_source_files_properties(assignment4/utils.cpp PROPERTIES HEADER_FILE_ONLY TRUE)
target_compile_features(ispell PRIVATE cxx_std_20)
set_target_properties(ispell PROPERTIES
    CXX_EXTENSIONS OFF
    OUTPUT_NAME main
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/assignment4"
)
