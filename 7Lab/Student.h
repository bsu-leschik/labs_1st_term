#ifndef GOOGLE_TESTS_SIX_LAB_STUDENT_H
#define GOOGLE_TESTS_SIX_LAB_STUDENT_H

#include <string>
#include <iostream>
#include <random>
#include <cassert>

using namespace std;

class Student {

protected:

    string UUID;
    int studentNum;
    char *name;
    int curs;
    int group;

    string toHex(int dec);
    string createUUID();

public:

    Student(int studentNum, char *name, int curs, int group);

    Student(Student *studentClass);

    void setName(char *name);

    void setCurs(int curs);

    void setGroup(int group);

    string getUUID();

    int getStudentNum();

    char *getName();

    int getCurs();

    int getGroup();

    friend ostream &operator<<(ostream &out, const Student& studentClass);

    virtual int getAverageMark();

};


#endif //GOOGLE_TESTS_SIX_LAB_STUDENT_H
