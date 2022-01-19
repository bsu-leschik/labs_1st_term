#include "StudentAfter2Session.h"
#include "gtest/gtest.h"
#include "string"
#include "functions.h"

string name = "aboba";
int marks1[4] = {1, 3, 5, 7};
int marks11[4] = {1, 4, 5, 7};
int marks2[5] = {2, 4, 6, 8, 10};
int marks21[5] = {2, 4, 9, 8, 10};

Student student1(225401, name, 1, 4);
Student student2(225402, name, 1, 4);
StudentAfter1Session studentAfter1Session(student1.getStudentNum(), name, student1.getCurs(), student1.getGroup(), marks1);
StudentAfter1Session studentAfter1Session1(student1.getStudentNum(), name, student1.getCurs(), 5, marks11);
StudentAfter2Session studentAfter2Session(student1.getStudentNum(), name, student1.getCurs(), student1.getGroup(), marks1, marks2);
StudentAfter2Session studentAfter2Session1(student1.getStudentNum(), name, student1.getCurs(), 5, marks11, marks21);


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
    ASSERT_EQ(student1.getCurs(), 1);
}

TEST(Student, getGroup){
    ASSERT_EQ(student1.getGroup(), 4);
}

TEST(StudentAfter1Session, getMarks){
    for (int i = 0; i < 4; ++i) {
        ASSERT_EQ(studentAfter1Session.getMarks()[i], marks1[i]);
    }
}

TEST(StudentAfter1Session, getAverageMark){
    ASSERT_EQ(studentAfter1Session.getAverageMark(), 4);
}

TEST(StudentAfter2Session, getMarks){
    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(studentAfter2Session.get2SessionMarks()[i], marks2[i]);
    }
}

TEST(StudentAfter2Session, getAverageMark){
    ASSERT_EQ(studentAfter2Session.getAverageMark(), 5);
}

TEST(Functions, groupAvgAfter1Session){
    vector<StudentAfter1Session*> students;
    students.push_back(&studentAfter1Session);
    students.push_back(&studentAfter1Session1);

    ASSERT_EQ(groupAvgAfter1Session(students, 4), 4);
}

TEST(Functions, groupAvgAfter2Session){
    vector<StudentAfter2Session*> students;
    students.push_back(&studentAfter2Session);
    students.push_back(&studentAfter2Session1);
    ASSERT_EQ(groupAvgAfter2Session(students, 4), 5);
}