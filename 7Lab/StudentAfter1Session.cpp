#include "StudentAfter1Session.h"

StudentAfter1Session::StudentAfter1Session(int studentNum, char *name, int curs1, int group, const int *marks) : Student(studentNum, name, curs1, group){
    for (int i = 0; i < 4; ++i) {
        this->marks[i] = marks[i];
    }
}

StudentAfter1Session::StudentAfter1Session(StudentAfter1Session *exClass) : Student(exClass) {
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
    Student student(classEx);
    cout << student;
    out << "Marks after 1st session:  " << classEx.marks << endl;
    return out;
}

double StudentAfter1Session::getAverageMark() {
    double sum = 0;
    for (int mark : this->marks) {
        sum += mark;
    }
    return sum / 4;
}
