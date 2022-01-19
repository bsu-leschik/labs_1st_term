#include "functions.h"

double groupAvgAfter1Session(const vector<StudentAfter1Session*>& students, int group){
    double avg;
    int i = 0;
    for(StudentAfter1Session* student : students) {
        if (student->getGroup() == group) {
            avg += student->getAverageMark();
            ++i;
        }
    }
    return (double) avg / i;
}

double groupAvgAfter2Session(const vector<StudentAfter2Session*>& students, int group){
    double avg = 0;
    int i = 0;
    for(StudentAfter2Session* student : students) {
        if (student->getGroup() == group) {
            avg += student->getAverageMark();
            ++i;
        }
    }
    return (double) avg / i;
}

double MasAvg(){
    int session11[4] = {6, 7, 8, 10};
    int session12[4] = {6, 4, 9, 10};
    int session22[5] = {2, 9, 6, 1, 8};
    vector<Student*> students;
    string name = "student1";
    students.push_back(new StudentAfter2Session(6662282, name, 3, 2, session12, session22));
    name = "student2";
    students.push_back(new StudentAfter1Session(6662281, name, 1, 3, session11));
    name = "student3";
    students.push_back(new Student(6662280, name, 1, 4));

    double avg = 0;
    for (short i = 0; i < 3; ++i) {
        avg += students[i]->getAverageMark();
    }
    return avg / 3;//or 2)
}