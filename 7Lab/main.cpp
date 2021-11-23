#include "StudentAfter2Session.h"
int main() {
    string name = "Dmitry";
    Student Student(2563241, name, 1, 4);
    cout << Student;

    int marks1[4] = {5, 7, 4, 6};
    StudentAfter1Session after1Session(2563241, name, 1, 4, marks1);
    cout << endl;
    cout << after1Session;

    int marks2[5] = {5, 7, 4, 6, 9};
    StudentAfter2Session after2Session(2563241, name, 1, 4, marks1, marks2);
    cout << endl;
    cout << after2Session;

    cout << "/n";
    StudentAfter2Session after2SessionCopy(after2Session);
    cout << after2SessionCopy;


    return 0;
}

