//
// Created by skalem on 19.11.21.
//

#ifndef INC_7LAB_STUDENTAFTER2SESSION_H
#define INC_7LAB_STUDENTAFTER2SESSION_H

#include "StudentAfter1Session.h"

class StudentAfter2Session : public StudentAfter1Session {

protected:
    int marks2Session[5];
public:
    StudentAfter2Session(int studentNum, string &name, int curs1, int group, const int marks[4],
                         const int marks2Session[5]);

    StudentAfter2Session(StudentAfter2Session *exClass);

    void set2SessionMarks(int *marks);

    int *get2SessionMarks();

    double getAverageMark() override;

    friend ostream &operator<<(ostream &out, const StudentAfter2Session &classEx);

};


#endif //INC_7LAB_STUDENTAFTER2SESSION_H
