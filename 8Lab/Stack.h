#ifndef GOOGLE_TESTS_STACK_H
#define GOOGLE_TESTS_STACK_H


#include <ostream>

class Stack {
private:
    double* stackBase = new double[0];
    int size = 0;

public:

    int getSize();
    double top();
    double pop();
    void push(double value);
    void print(std::ostream& out);
    bool isEmpty();
    void resize();
    ~Stack();

};


#endif //GOOGLE_TESTS_STACK_H
