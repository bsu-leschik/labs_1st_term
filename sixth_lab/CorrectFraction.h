//
// Created by skalem on 2.11.21.
//

#ifndef LABS_1ST_TERM_CORRECTFRACTION_H
#define LABS_1ST_TERM_CORRECTFRACTION_H
#include <cassert>

class CorrectFraction {
public:
    CorrectFraction(int num, int denum);
    CorrectFraction(CorrectFraction& frac);

    CorrectFraction cut();
    int getNumerator();
    int getDenominator();
    CorrectFraction sum(CorrectFraction first, CorrectFraction second);
    CorrectFraction multiply(CorrectFraction first, CorrectFraction second);
    CorrectFraction divide(CorrectFraction first, CorrectFraction second);
    void output();
private:
    int num;
    int denum;
};


#endif //LABS_1ST_TERM_CORRECTFRACTION_H
