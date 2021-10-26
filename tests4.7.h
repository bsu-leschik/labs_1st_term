//
// Created by skalem on 26.10.21.
//

#ifndef LABS_1ST_TERM_TESTS4_7_H
#define LABS_1ST_TERM_TESTS4_7_H

#include "4.7.A.h"
#include "4.7.B.h"
#include <cassert>
#include <string>
#include <iostream>

void strchrTest(){
    char* line = new char[110];
    line = "Let’s start by adding an existing Git repository as a submodule of the repository that we’re working on.";
    assert(strchr(line, 'd') == &(line[18]));
    std::cout << "Passed strcharTest" << std::endl;
}

void dataTest1(){
    char* line = new char[200];
    line = "Let’s start by ad20/12/2003ding an existing Git repository as a submodule of the repository that we’re working on.";
    assert(datas(line) == 1);
    std::cout << "Passed dataTest1" << std::endl;
}

void dataTest2(){
    char* line = new char[200];
    line = "Let’s start by 20/12/2003adding an existing Git repository as a submodule of the repository that we’re working on.";
    assert(datas(line) == 1);
    std::cout << "Passed dataTest2" << std::endl;
}

void dataTest3(){
    char* line = new char[200];
    line = "Let’s start by adding an existing Git20/12/2003 repository as a submodule of the repository that we’re working on.";
    assert(datas(line) == 1);
    std::cout << "Passed dataTest3" << std::endl;
}

void dataTest4(){
    char* line = new char[200];
    line = "Let’s start by 20 /12/2003 adding an existing Git repository as a submodule of the repository that we’re working on.";
    assert(datas(line) == 0);
    std::cout << "Passed dataTest4" << std::endl;
}

void dataTest5(){
    char* line = new char[200];
    line = "Let’s start by 20/ 12/2003 adding an existing Git repository as a submodule of the repository that we’re working on.";
    assert(datas(line) == 0);
    std::cout << "Passed dataTest5" << std::endl;
}

void dataTest6(){
    char* line = new char[200];
    line = "Let’s start by 20/12 /2003 adding an existing Git repository as a submodule of the repository that we’re working on.";
    assert(datas(line) == 0);
    std::cout << "Passed dataTest6" << std::endl;
}

void dataTest7(){
    char* line = new char[200];
    line = "Let’s start by 20/12/ 2003 adding an existing Git repository as a submodule of the repository that we’re working on.";
    assert(datas(line) == 0);
    std::cout << "Passed dataTest7" << std::endl;
}

void dataTest8(){
    char* line = new char[200];
    line = "Let’s start by a0/12/2003 adding an existing Git repository as a submodule of the repository that we’re working on.";
    assert(datas(line) == 0);
    std::cout << "Passed dataTest8" << std::endl;
}

void dataTest9(){
    char* line = new char[200];
    line = "Let’s start by 2a/12/2003 adding an existing Git repository as a submodule of the repository that we’re working on.";
    assert(datas(line) == 0);
    std::cout << "Passed dataTest9" << std::endl;
}

void dataTest10(){
    char* line = new char[200];
    line = "Let’s start by 20a12/2003 adding an existing Git repository as a submodule of the repository that we’re working on.";
    assert(datas(line) == 0);
    std::cout << "Passed dataTest10" << std::endl;
}

void dataTest11(){
    char* line = new char[200];
    line = "Let’s start by 20/a2/2003 adding an existing Git repository as a submodule of the repository that we’re working on.";
    assert(datas(line) == 0);
    std::cout << "Passed dataTest11" << std::endl;
}

void dataTest12(){
    char* line = new char[200];
    line = "Let’s start by 20/1a/2003 adding an existing Git repository as a submodule of the repository that we’re working on.";
    assert(datas(line) == 0);
    std::cout << "Passed dataTest12" << std::endl;
}

void dataTest13(){
    char* line = new char[200];
    line = "Let’s start by 20/12a2003 adding an existing Git repository as a submodule of the repository that we’re working on.";
    assert(datas(line) == 0);
    std::cout << "Passed dataTest13" << std::endl;
}

void dataTest14(){
    char* line = new char[200];
    line = "Let’s start by 20/12/a003 adding an existing Git repository as a submodule of the repository that we’re working on.";
    assert(datas(line) == 0);
    std::cout << "Passed dataTest14" << std::endl;
}
void dataTest15(){
    char* line = new char[200];
    line = "Let’s start by 20/12/2a03 adding an existing Git repository as a submodule of the repository that we’re working on.";
    assert(datas(line) == 0);
    std::cout << "Passed dataTest15" << std::endl;
}
void dataTest16(){
    char* line = new char[200];
    line = "Let’s start by 20/12/20a3 adding an existing Git repository as a submodule of the repository that we’re working on.";
    assert(datas(line) == 0);
    std::cout << "Passed dataTest16" << std::endl;
}
void dataTest17(){
    char* line = new char[200];
    line = "Let’s start by 20/12/200a adding an existing Git repository as a submodule of the repository that we’re working on.";
    assert(datas(line) == 0);
    std::cout << "Passed dataTest17" << std::endl;
}

void dataTest18(){
    char* line = new char[200];
    line = "Let’s start by 20/12/2003 adding an existing Git repository as a submodule of the repository that we’re working on.";
    assert(datas(line) == 0);
    std::cout << "Passed dataTest18" << std::endl;
}



void runTests(){
    strchrTest();
    dataTest1();
    dataTest2();
    dataTest3();
    dataTest4();
    dataTest5();
    dataTest6();
    dataTest7();
    dataTest8();
    dataTest9();
    dataTest10();
    dataTest11();
    dataTest12();
    dataTest13();
    dataTest14();
    dataTest15();
    dataTest16();
    dataTest17();
    dataTest18();
}


#endif //LABS_1ST_TERM_TESTS4_7_H
