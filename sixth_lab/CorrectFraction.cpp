//
// Created by skalem on 2.11.21.
//

#include "CorrectFraction.h"
#include <iostream>
#include <cmath>

using namespace std;

CorrectFraction::CorrectFraction(int num, int denum) {
        assert(denum != 0);

        this->num = num;
        this->denum = denum;
}

CorrectFraction::CorrectFraction(CorrectFraction& frac) {
    assert(frac.getDenominator() != 0);

    this->num = frac.getNumerator();
    this->denum = frac.getDenominator();
}

int CorrectFraction::getNumerator() {
    return num;
}

int CorrectFraction::getDenominator() {
    return denum;
}

CorrectFraction CorrectFraction::cut() {
    for(int i = min(sqrt(num), sqrt(denum)) + 1; i > 0 ; --i){
        if (num % i == 0 && denum % i == 0){
            num = num / i;
            denum = denum / i;
        }
    }
    return *this;
}

CorrectFraction CorrectFraction::sum(CorrectFraction first, CorrectFraction second) {
    CorrectFraction output(first.getNumerator() * second.getDenominator()
    + second.getNumerator() * first.getDenominator(),first.getDenominator() * second.getDenominator());
    output.cut();
    return output;
}

CorrectFraction CorrectFraction::multiply(CorrectFraction first, CorrectFraction second) {
    CorrectFraction output(first.getNumerator() * second.getNumerator(),
                           first.getDenominator() * second.getDenominator());
    output.cut();
    return output;
}

CorrectFraction CorrectFraction::divide(CorrectFraction first, CorrectFraction second) {
    CorrectFraction output(first.getNumerator() * second.getDenominator(),
                           first.getDenominator() * second.getNumerator());
    output.cut();
    return output;
}

void CorrectFraction::output() {
    cout << num << "/" << denum;
}