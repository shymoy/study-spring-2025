cmake_minimum_required(VERSION 3.20)
project(cs106l_spring_2025 LANGUAGES CXX)

# Spring 2025 A7 starter: d6340bb351e2c36bad6efb64a5d2a681b24b7a8e
add_executable(unique_pointer EXCLUDE_FROM_ALL
    assignment7/main.cpp
    assignment7/unique_ptr.h
)
target_compile_features(unique_pointer PRIVATE cxx_std_20)
set_target_properties(unique_pointer PROPERTIES
    CXX_EXTENSIONS OFF
    OUTPUT_NAME main
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/assignment7"
)

# Spring 2025 A6 starter: 7183144fde4e96a9b2ca5a9c5ebaf63a5755226c
# Keep the unfinished starter out of the default all-target build.
add_executable(explore_courses EXCLUDE_FROM_ALL assignment6/main.cpp)
target_compile_features(explore_courses PRIVATE cxx_std_23)
set_target_properties(explore_courses PROPERTIES
    CXX_EXTENSIONS OFF
    OUTPUT_NAME main
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/assignment6"
)

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

# Spring 2025 A5 starter: de3ebf91e5dbb80faaf4358b29e0a409120d9372
add_executable(treebook
    assignment5/main.cpp
    assignment5/user.cpp
    assignment5/user.h
)
target_compile_features(treebook PRIVATE cxx_std_20)
set_target_properties(treebook PROPERTIES
    CXX_EXTENSIONS OFF
    OUTPUT_NAME main
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/assignment5"
)
