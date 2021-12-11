#include "Calc.h"

using namespace std;

bool Calc::isExpression(string &expression) {
    char current;
    if (!isdigit(expression[0]) && expression[0] != '(' && expression[0] != ')'){ return false;}
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

    string temp;
    for (int i = 0; i < expression.size(); ++i) {
        if (isdigit(expression[i])) {
            polish.push_back(getNumber(expression, i));
            continue;
        } else {
            switch (expression[i]) {
                case ')':
                    temp = {operations.pop()};
                    polish.push_back(temp);
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
    return polish;
}

double Calc::calculate(std::string &expression) {
    if (!isExpression(expression)) {
        throw logic_error("Invalid expression");
    }
    pair<Stack<double>, Stack<char>> stacks = toPolish(expression);
    Stack<double> numbers = stacks.first;
    Stack<char> operators = stacks.second;

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
