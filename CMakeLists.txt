cmake_minimum_required(VERSION 3.20)

project(General_compilation)

set(CMAKE_CXX_STANDARD 14)

add_executable(1lab first_lab_var7/lab_1.7.cpp)
add_executable(2lab second_lab_var7/lab_2.7.cpp)
add_executable(3lab third_lab_var7/lab3.7.cpp)
add_executable(4lab fourth_lab_v7/4.7.A.cpp fourth_lab_v7/4.7.B.cpp fourth_lab_v7/4.7.A.h fourth_lab_v7/4.7.B.h fourth_lab_v7/tests4.7.h)
add_executable(5lab fifth_lab_var7/5.7.cpp)
add_executable(6lab sixth_lab/6.cpp sixth_lab/CorrectFraction.cpp sixth_lab/CorrectFraction.h)
add_executable(7Lab 7Lab/Student.cpp 7Lab/Student.h 7Lab/StudentAfter1Session.cpp 7Lab/StudentAfter1Session.h 7Lab/StudentAfter2Session.cpp 7Lab/StudentAfter2Session.h 7Lab/main.cpp 7Lab/functions.cpp 7Lab/functions.h)

project(Google_tests)

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Test_4lab_run fourth_lab_v7/4.7.A.h)

add_executable(Google_Tests_7Lab_run 7Lab/Student.cpp 7Lab/Student.h 7Lab/StudentAfter1Session.cpp 7Lab/StudentAfter1Session.h 7Lab/StudentAfter2Session.cpp 7Lab/StudentAfter2Session.h 7Lab/functions.cpp 7Lab/functions.h 7Lab/tests.cpp)

add_executable(Google_Tests_six_lab_run sixth_lab/tests.cpp sixth_lab/CorrectFraction.cpp sixth_lab/CorrectFraction.h sixth_lab/tests.h)

target_link_libraries(Google_Tests_six_lab_run gtest gtest_main)