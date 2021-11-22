#include "Student.h"

string Student::toHex(int dec) {
    assert(dec < 16);
    string hex;
    if (dec > 9){
        hex = dec%10 + 97;
    } else {
        hex = dec + 48;
    }
    return hex;
}

string Student::createUUID() {
    random_device rdGen;
    mt19937 gen(rdGen());
    uniform_int_distribution<> dis0_15(0, 15);
    uniform_int_distribution<> dis8_11(8, 11);
    string UUID;
    int i;
    for (i = 0; i < 8; i++) {
        UUID += toHex(dis0_15(gen));
    }
    UUID += '-';
    for (i = 0; i < 4; i++) {
        UUID += toHex(dis0_15(gen));
    }
    UUID += "-4";
    for (i = 0; i < 3; i++) {
        UUID += toHex(dis0_15(gen));
    }
    UUID += "-";
    UUID += toHex(dis8_11(gen));
    for (i = 0; i < 4; i++) {
        UUID += toHex(dis0_15(gen));
    }
    UUID += "-";
    for (i = 0; i < 12; i++) {
        UUID += toHex(dis0_15(gen));
    }
    return UUID;
}




Student::Student(int studentNum, char *name, int curs, int group) {
    UUID = createUUID();
    this->studentNum = studentNum;
    this->name = name;
    this->curs = curs;
    this->group = group;
}

Student::Student(Student *studentClass) {
    this->UUID = studentClass->UUID;
    this->studentNum = studentClass->studentNum;
    this->name = studentClass->name;
    this->curs = studentClass->curs;
    this->group = studentClass->group;
}

void Student::setName(char *name) {
    this->name = name;
}

void Student::setCurs(int curs) {
    this->curs = curs;
}

void Student::setGroup(int group) {
    this->group = group;
}

string Student::getUUID() {
    return UUID;
}

int Student::getStudentNum() {
    return studentNum;
}

char *Student::getName() {
    return name;
}

int Student::getCurs() {
    return curs;
}

int Student::getGroup() {
    return group;
}

ostream &operator<<(ostream &out, const Student& studentClass) {
    out << "UUID: " << studentClass.UUID << endl;
    out << "Student number: " << studentClass.studentNum << endl;
    out << "Name: " << studentClass.name << endl;
    out << "Curs: " << studentClass.curs << endl;
    out << "Group: " << studentClass.group << endl;
    return out;
}

double Student::getAverageMark() {
    return 0;
}
