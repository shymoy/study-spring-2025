cmake_minimum_required(VERSION 3.20)
project(cs106l_spring_2025 LANGUAGES CXX)

add_executable(simple_enroll assignment1/main.cpp)
target_compile_features(simple_enroll PRIVATE cxx_std_20)
set_target_properties(simple_enroll PROPERTIES CXX_EXTENSIONS OFF)

add_executable(marriage_pact assignment2/main.cpp)
target_compile_features(marriage_pact PRIVATE cxx_std_20)
set_target_properties(marriage_pact PROPERTIES CXX_EXTENSIONS OFF)

# Spring 2025 A3 starter: f318ccdea16c4700f2dfcfc7737d99ec8288ea94
add_executable(make_a_class assignment3/main.cpp assignment3/class.cpp)
target_compile_features(make_a_class PRIVATE cxx_std_20)
set_target_properties(make_a_class PROPERTIES CXX_EXTENSIONS OFF)
