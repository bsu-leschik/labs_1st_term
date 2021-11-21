//
// Created by skalem on 19.11.21.
//

#include "StudentAfter2Session.h"

StudentAfter2Session::StudentAfter2Session(int studentNum, char *name, int curs1, int group, const int *marks,
                                           const int *marks2Session) : StudentAfter1Session(studentNum, name, curs1, group, marks){
    for (int i = 0; i < 5; ++i) {
        this->marks2Session[i] = marks2Session[i];
    }
}

StudentAfter2Session::StudentAfter2Session(StudentAfter2Session *exClass) : StudentAfter1Session(exClass){
    for (int i = 0; i < 5; ++i) {
        this->marks2Session[i] = marks2Session[i];
    }
}

void StudentAfter2Session::set2SessionMarks(int *marks) {
    for (int i = 0; i < 5; ++i) {
        this->marks2Session[i] = marks[i];
    }
}

int *StudentAfter2Session::get2SessionMarks() {
    return marks2Session;
}

int StudentAfter2Session::getAverageMark() {
    int sum = 0;
    for (int mark : this->marks2Session) {
        sum += mark;
    }
    for (int mark : this->marks) {
        sum += mark;
    }
    return sum / 9;
}

ostream &operator<<(ostream &out, const StudentAfter2Session &classEx) {
    out << "Student number: " << classEx.studentNum << endl;
    out << "Name: " << classEx.name << endl;
    out << "Curs: " << classEx.curs << endl;
    out << "Group: " << classEx.group << endl;
    out << "Marks after 1st session: " << classEx.marks << endl;
    out << "Marks after 2nd session: " << classEx.marks2Session << endl;
    out << "UUID: " << classEx.UUID << endl;
    return out;
}