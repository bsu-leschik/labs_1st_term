#include "Calc.h"

using namespace std;

bool Calc::isExpression(string &expression) {
    char current;
    if (!isdigit(expression[0]) && expression[0] != '(' && expression[0] != ')' && expression[0] != '-'){ return false;}
    if (!isValidChar(expression[0])) {
        return false;
    }
    for (int i = 1; i < expression.length(); ++i) {
        current = expression[i];
        if (isValidChar(current)) {
            if ((!isdigit(current) && isdigit(expression[i - 1])) ||
                (isdigit(current) && !isdigit(expression[i - 1]))) {
                if (current == '(') {
                    if (i < expression.find(')')) {
                        continue;
                    } else {
                        return false;
                    }
                } else {
                    continue;
                }
            }
        }
        return false;
    }
    return true;
}

vector<string> Calc::toPolish(string &expression) {
    Stack<double> elements;
    vector<string> polish;
    Stack<char> operations;


    if (expression[0] == '-'){
        expression.erase(0);
        expression.insert(0, "-1*");
    }
    for (int i = 1; i < expression.size(); ++i) {
        if (expression[i] == '-' && expression[i - 1]){
            expression.erase(i);
            expression.insert(i, "-1*");
        }
    }

    string temp;
    for (int i = 0; i < expression.size(); ++i) {
        if (isdigit(expression[i])) {
            polish.push_back(getNumber(expression, i));
            continue;
        } else {
            switch (expression[i]) {
                case ')':
                    while(operations.top() != '(') {
                        temp = {operations.pop()};
                        polish.push_back(temp);
                        operations.pop();
                    }
                    operations.pop();
                    break;
                case '(':
                    operations.push('(');
                    break;
                case '*':
                    if (operations.top() == '/'){
                        temp = {operations.pop()};
                        polish.push_back(temp);
                    }
                    operations.push('*');
                    break;
                case '/':
                    if (operations.top() == '*'){
                        temp = {operations.pop()};
                        polish.push_back(temp);
                    }
                    operations.push('/');
                    break;
                case '+':
                    if (operations.top() == '*' || operations.top() == '/' || operations.top() == '-'){
                        temp = {operations.pop()};
                        polish.push_back(temp);
                    }
                    operations.push('+');
                    break;
                case '-':
                    if (operations.top() == '*' || operations.top() == '/' || operations.top() == '+'){
                        temp = {operations.pop()};
                        polish.push_back(temp);
                    }
                    operations.push('-');
                    break;
            }
            operations.push(expression[i]);
        }
    }
    while(!operations.isEmpty()){
        temp = {operations.pop()};
        polish.push_back(temp);
    }
    operations.resize();
    return polish;
}

double Calc::calculate(std::string &expression) {
    if (!isExpression(expression)) {
        throw logic_error("Invalid expression");
    }
    vector<string> line= toPolish(expression);


    return 0;
}

bool Calc::isValidChar(char el) {
    if (isdigit(el) || el == '/' || el == '+' || el == '-' || el == '*' || el == '.' || el == ',' || el == '(' ||
        el == ')') {
        return true;
    }
    return false;
}

double Calc::charToDouble(const char *charNum) {
    int i = 0;
    int number = 0;
    while (charNum[i] != '.' || charNum[i] != '\0') {
        number += charNum[i] - 48;
        ++i;
    }
    if (charNum[i] == '.') {
        int j = 10;
        while (charNum[i] != '\0') {
            number += (charNum[i] - 48) % j;
            ++i;
            j += 10;
        }
    }
    return number;
}

string Calc::getNumber(const string &expression, int& start) {
    int j = 0;
    string number;
    while (isdigit(expression[start]) || expression[start] != '\0') {
        number[j] = expression[start];
        ++j;
        ++start;
    }
    if (expression[start] == '.') {
        number[j] = '.';
        ++start;
        ++j;
        while (isdigit(expression[start]) || expression[start] != '\0') {
            number[j] = expression[start];
            ++start;
            ++j;
        }
    }
    return number;
}
