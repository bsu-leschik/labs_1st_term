#include "Calc.h"

using namespace std;

bool Calc::isExpression(string &expression) {
    char current;
    if (!isdigit(expression[0]) && expression[0] != '(' && expression[0] != '-') { return false; }
    for (int i = 0; i < expression.length(); ++i) {
        current = expression[i];
        if (isValidChar(current)) {
            if (current == '(') {
                if (expression.find(')', i) == -1) {
                    return false;
                } else {
                    continue;
                }
            }
            if (expression[i] == '-') {
                if (i > 0) {
                    if (!isdigit(expression[i - 1]) && expression[i - 1] != '-' && expression[i - 1] != '(' &&
                        expression[i - 1] != ')') {
                        return false;
                    }
                }
                if (expression[i + 1] != '-' && !isdigit(expression[i + 1]) && expression[i + 1] != '(') {
                    return false;
                }
                continue;
            }
            if (!isdigit(expression[i]) && !isdigit(expression[i + 1]) && expression[i + 1] != '\0' &&
                expression[i + 1] != '(' && expression[i] != ')') {
                return false;
            } else if (!isdigit(expression[i])) {
                continue;
            }
            getNumber(expression, i);
        }
    }
    return true;
}

vector<string> Calc::toPolish(string &expression) {
    Stack<double> elements;
    vector<string> polish;
    Stack<char> operations;


    if (expression[0] == '-' && (isdigit(expression[1]) || expression[1] == '(')) {
        expression.erase(0, 1);
        expression.insert(0, "~");
    }
    for (int i = 1; i < expression.size(); ++i) {
        if (expression[i] == '-' && !isdigit(expression[i - 1]) && expression[i - 1] != ')') {
            expression.erase(i, 1);
            expression.insert(i, "~");
        }
    }

    string temp;
    for (int i = 0; i < expression.size(); ++i) {
        if (isdigit(expression[i])) {
            polish.push_back(getNumber(expression, i));
            continue;
        } else {
            switch (expression[i]) {
                case '~':
                    operations.push('~');
                    break;
                case ')':
                    while (operations.top() != '(') {
                        temp = {operations.pop()};
                        polish.push_back(temp);
                    }
                    operations.pop();
                    break;
                case '(':
                    operations.push('(');
                    break;
                case '*':
                    while (operations.top() == '~' || operations.top() == '/') {
                        temp = {operations.pop()};
                        polish.push_back(temp);
                    }
                    operations.push('*');
                    break;
                case '/':
                    while (operations.top() == '~' || operations.top() == '*') {
                        temp = {operations.pop()};
                        polish.push_back(temp);
                    }
                    operations.push('/');
                    break;
                case '+':
                    while (operations.top() == '*' || operations.top() == '/' || operations.top() == '-' ||
                           operations.top() == '~' || operations.top() == '+') {
                        temp = {operations.pop()};
                        polish.push_back(temp);
                    }
                    operations.push('+');
                    break;
                case '-':
                    while (operations.top() == '*' || operations.top() == '/' || operations.top() == '+' ||
                           operations.top() == '~' || operations.top() == '-') {
                        temp = {operations.pop()};
                        polish.push_back(temp);
                    }
                    operations.push('-');
                    break;
            }
        }
    }
    while (!operations.isEmpty()) {
        temp = {operations.pop()};
        polish.push_back(temp);
    }
    operations.resize();
    return polish;
}

bool Calc::isNumber(string line) {
    for (char c: line) {
        if (!isdigit(c) && c != '.') {
            return false;
        }
    }
    return true;
}

double Calc::calculate(std::string &expression) {
    if (!isExpression(expression)) {
        throw logic_error("Invalid expression");
    }
    vector<string> line = toPolish(expression);
    Stack<double> stack;
    for (string s : line) {
        if (isNumber(s)) {
            stack.push(stod(s));
        } else {
            const char *opC = s.c_str();

            double a;
            switch (*opC) {
                case '~':
                    stack.push(-stack.pop());
                    break;
                case '+':
                    stack.push(stack.pop() + stack.pop());
                    break;
                case '*':
                    stack.push(stack.pop() * stack.pop());
                    break;
                case '-':
                    a = stack.pop();
                    stack.push((double) (stack.pop() - a));
                    break;
                case '/':
                    a = stack.pop();
                    stack.push((double) (stack.pop() / a));
                    break;
            }
        }
    }
    return stack.pop();
}

bool Calc::isValidChar(char el) {
    if (isdigit(el) || el == '/' || el == '+' || el == '-' || el == '*' || el == '.' || el == ',' || el == '(' ||
        el == ')') {
        return true;
    }
    return false;
}

string Calc::getNumber(const string &expression, int &start) {
    string number;
    while (isdigit(expression[start])) {
        number.push_back(expression[start]);
        ++start;
    }
    if (expression[start] == '.' || expression[start] == ',') {
        number.push_back('.');
        ++start;
        while (isdigit(expression[start])) {
            number.push_back(expression[start]);
            ++start;
        }
    }
    --start;
    return number;
}
