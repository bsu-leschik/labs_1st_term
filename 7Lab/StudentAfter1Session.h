#ifndef INC_7LAB_STUDENTAFTER1SESSION_H
#define INC_7LAB_STUDENTAFTER1SESSION_H

#include "student.h"

class StudentAfter1Session : public student {
protected:
    int marks[4];
public:
    StudentAfter1Session(int studentNum, char *name, int curs1, int group, const int marks[4]);

    StudentAfter1Session(StudentAfter1Session *exClass);

    void setMarks(int *marks);

    int *getMarks();

    friend ostream &operator<<(ostream &out, const StudentAfter1Session &classEx);

    virtual int getAverageMark();

};


#endif //INC_7LAB_STUDENTAFTER1SESSION_H
