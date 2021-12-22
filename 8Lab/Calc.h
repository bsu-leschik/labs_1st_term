#ifndef GOOGLE_TESTS_CALC_H
#define GOOGLE_TESTS_CALC_H

#include <string>
#include <vector>
#include "Stack.h"


class Calc {
private:
    std::string getNumber(const std::string &expression, int &start);

    bool isValidChar(char el);

    bool isExpression(std::string &expression);

    std::vector<std::string> toPolish(std::string &expression);

    bool isNumber(std::string line);


public:
    double calculate(std::string &expression);
};


#endif //GOOGLE_TESTS_CALC_H
