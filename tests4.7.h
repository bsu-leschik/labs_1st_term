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
    std::cout << "srtchrTest passed";
}

void dataTest1(){

}



void runTests(){
    strchrTest();
    dataTest1();
}


#endif //LABS_1ST_TERM_TESTS4_7_H
