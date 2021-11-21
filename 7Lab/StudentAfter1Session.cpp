//
// Created by skalem on 19.11.21.
//

#include "StudentAfter1Session.h"

StudentAfter1Session::StudentAfter1Session(int studentNum, char *name, int curs1, int group, const int *marks) : student(studentNum, name, curs1, group){
    for (int i = 0; i < 4; ++i) {
        this->marks[i] = marks[i];
    }
}

StudentAfter1Session::StudentAfter1Session(StudentAfter1Session *exClass) : student(exClass->studentNum, exClass->name,
                                                                                    exClass->curs, exClass->group) {
    for (int i = 0; i < 4; ++i) {
        this->marks[i] = exClass->marks[i];
    }
}

void StudentAfter1Session::setMarks(int* marks) {
    for (int i = 0; i < 4; ++i) {
        this->marks[i] = marks[i];
    }
}

int* StudentAfter1Session::getMarks() {
    return marks;
}

ostream &operator<<(ostream &out, const StudentAfter1Session &classEx) {
    out << "Student number: " << classEx.studentNum << endl;
    out << "Name: " << classEx.name << endl;
    out << "Curs: " << classEx.curs << endl;
    out << "Group: " << classEx.group << endl;
    out << "Marks after 1st session:  " << classEx.marks << endl;
    out << "UUID: " << classEx.UUID << endl;
    return out;
}

int StudentAfter1Session::getAverageMark() {
    int sum = 0;
    for (int mark : this->marks) {
        sum += mark;
    }
    return sum / 4;
}
