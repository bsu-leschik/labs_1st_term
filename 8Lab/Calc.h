#ifndef GOOGLE_TESTS_CALC_H
#define GOOGLE_TESTS_CALC_H
#include <string>
#include <vector>
#include "Stack.h"



class Calc {
private:
    std::string getNumber(const std::string &expression, int &start);
    double charToDouble(const char* charNum);
    bool isValidChar(char el);
    bool isExpression(std::string &expression);
    std::vector<std::string> toPolish(std::string &expression);
    double calc(double first, const std::string &op, const std::string &second);


public:
    double calculate(std::string &expression);

};


#endif //GOOGLE_TESTS_CALC_H
