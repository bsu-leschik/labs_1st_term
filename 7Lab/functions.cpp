#include "functions.h"

int groupAvgAfter1Session(vector<StudentAfter1Session> students, int group){
    int avg, i = 0;
    for(StudentAfter1Session student : students) {
        if (student.getGroup() == group) {
            avg += student.getAverageMark();
            ++i;
        }
    }
    return avg / i;
}

int groupAvgAfter2Session(vector<StudentAfter2Session> students, int group){
    int avg, i = 0;
    for(StudentAfter2Session student : students) {
        if (student.getGroup() == group) {
            avg += student.getAverageMark();
            ++i;
        }
    }
}

int MasAvg(){
    int session11[4] = {6, 7, 8, 10};
    int session12[4] = {6, 4, 9, 10};
    int session22[5] = {2, 9, 6, 1, 8};
    vector<Student*> students;
    students.push_back(new StudentAfter2Session(6662282, "student3", 3, 2, session12, session22));
    students.push_back(new StudentAfter1Session(6662281, "student2", 1, 3, session11));
    students.push_back(new Student(6662280, "student1", 1, 4));

    int avg = 0;
    for (short i = 0; i < 3; ++i) {
        avg += students[i]->getAverageMark();
    }
    return avg / 3;//or 2)
}