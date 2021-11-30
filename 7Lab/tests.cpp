#include "StudentAfter2Session.h"
#include "gtest/gtest.h"
#include "string"

string name = "aboba";
int marks1[4] = {1, 3, 5, 7};
int marks2[5] = {2, 4, 6, 8, 10};

Student student1(225401, name, 1, 4);
Student student2(225402, name, 1, 4);
StudentAfter1Session studentAfter1Session(student1.getStudentNum(), name, student1.getCurs(), student1.getGroup(), marks1);
StudentAfter2Session studentAfter2Session(student1.getStudentNum(), name, student1.getCurs(), student1.getGroup(), marks1, marks2);

TEST(Student, getName){
    ASSERT_EQ(student1.getName(), name);
}

TEST(Student, getUUID){
    ASSERT_FALSE(student1.getUUID() == student2.getUUID());
}

TEST(Student, getStudentNum){
    ASSERT_EQ(student1.getStudentNum(), 225401);
}

TEST(Student, getCurs){
    ASSERT_EQ(student1.getCurs(), 225401);
}

TEST(Student, getGroup){
    ASSERT_EQ(student1.getGroup(), 225401);
}

TEST(StudentAfter1Session, getMarks){
    ASSERT_EQ(studentAfter1Session.getMarks(), marks1);
}

TEST(StudentAfter1Session, getAverageMark){
    ASSERT_EQ(studentAfter1Session.getAverageMark(), 4);
}

TEST(StudentAfter2Session, getMarks){
    ASSERT_EQ(studentAfter2Session.getMarks(), marks2);
}

TEST(StudentAfter2Session, getAverageMark){
    ASSERT_EQ(studentAfter2Session.getAverageMark(), 7);
}

