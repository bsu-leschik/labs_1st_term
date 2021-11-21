#include "student.h"

string student::toHex(int dec) {
    assert(dec < 16);
    string hex;
    if (dec > 9){
        hex = dec%10 + 97;
    } else {
        hex = dec + 48;
    }
    return hex;
}

string student::createUUID() {
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




student::student(int studentNum, char *name, int curs, int group) {
    UUID = createUUID();
    this->studentNum = studentNum;
    this->name = name;
    this->curs = curs;
    this->group = group;
}

student::student(student *studentClass) {
    this->UUID = studentClass->UUID;
    this->studentNum = studentClass->studentNum;
    this->name = studentClass->name;
    this->curs = studentClass->curs;
    this->group = studentClass->group;
}

void student::setName(char *name) {
    this->name = name;
}

void student::setCurs(int curs) {
    this->curs = curs;
}

void student::setGroup(int group) {
    this->group = group;
}

string student::getUUID() {
    return UUID;
}

int student::getStudentNum() {
    return studentNum;
}

char *student::getName() {
    return name;
}

int student::getCurs() {
    return curs;
}

int student::getGroup() {
    return group;
}

ostream &operator<<(ostream &out, const student& studentClass) {
    out << "Student number: " << studentClass.studentNum << endl;
    out << "Name: " << studentClass.name << endl;
    out << "Curs: " << studentClass.curs << endl;
    out << "Group: " << studentClass.group << endl;
    out << "UUID: " << studentClass.UUID << endl;
    return out;
}
