cmake_minimum_required(VERSION 3.20)
project(labs_1st_term)

set(CMAKE_CXX_STANDARD 14)

add_executable(labs_1st_term fourth_lab_v7/4.7.A.cpp fourth_lab_v7/main4.6.cpp fourth_lab_v7/4.7.A.h fourth_lab_v7/tests4.7.h fourth_lab_v7/4.7.B.h fourth_lab_v7/4.7.B.cpp)

project(first_lab)
add_executable(first_lab first_lab_var7/lab_1.7.cpp)

project(second_lab)
add_executable(second_lab second_lab_var7/lab_2.7.cpp)

project(third_lab)
add_executable(third_lab third_lab_var7/lab3.7.cpp)

project(fourth_lab)
add_executable(fourth_lab fourth_lab_v7/4.7.A.cpp fourth_lab_v7/4.7.B.cpp fourth_lab_v7/4.7.A.h fourth_lab_v7/4.7.B.h fourth_lab_v7/tests4.7.h)

project(fifth_lab)
add_executable(fifth_lab fifth_lab_var7/5.7.cpp)

project(sixth_lab)
add_executable(sixth_lab sixth_lab/6.cpp sixth_lab/CorrectFraction.cpp sixth_lab/CorrectFraction.h)

project(Google_tests_six_lab)

# 'lib' is the folder with Google Test sources
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_six_lab_run sixth_lab/tests.cpp sixth_lab/CorrectFraction.cpp sixth_lab/CorrectFraction.h sixth_lab/tests.h)
target_link_libraries(Google_Tests_six_lab_run gtest gtest_main)