#include "Stack.h"

    int Stack::getSize() {
        return size;
    }

    double Stack::top() {
        return stackBase[size - 1];
    }
    double Stack::pop() {
        --size;
        return stackBase[size];
    }
    void Stack::push(double value) {
        if (size != 0) {
            double temp[size];
            for (int i = 0; i < size; ++i) {
                temp[i] = stackBase[i];
            }
            delete[] stackBase;
            stackBase = new double[++size];
            for (int i = 0; i < size - 1; ++i) {
                stackBase[i] = temp[i];
            }
        } else {
            delete[] stackBase;
            stackBase = new double[++size];
        }
        stackBase[size - 1] = value;
    }
    void Stack::print(std::ostream &out) {
        for (int i = 0; i < size; ++i) {
            out << stackBase[i] << " ";
        }
        out << std::endl;
    }

    bool Stack::isEmpty() {
        return size;
    }
    void Stack::resize() {
        double temp[size];
        for (int i = 0; i < size; ++i) {
            temp[i] = stackBase[i];
        }
        delete[] stackBase;
        stackBase = new double[size];
        for (int i = 0; i < size; ++i) {
            stackBase[i] = temp[i];
        }
    }

Stack::~Stack() {
    delete[] stackBase;
}

Stack& operator<<(Stack& stack, double el) {
    stack.push(el);
    return stack;
}

void operator>>(Stack &stack, double &el) {
    el = stack.pop();
}

Stack &Stack::operator=(Stack &stack) {
    this->size = stack.size;
    delete[] this->stackBase;
    this->stackBase = new double[stack.size];
    for (int i = 0; i < stack.size; ++i) {
        &stackBase[i] = &(stack.stackBase[i]);
    }
    return *this;
}

bool operator<(Stack &stack, Stack &stack1) {
    return (stack.size < stack1.size);
}

bool operator>(Stack &stack, Stack &stack1) {
    return (stack.size > stack1.size);
}

bool operator==(Stack &stack, Stack &stack1) {
    return (stack.size == stack1.size);
}

double Stack::operator[](int i) {
    Stack stack = *this;
    for (int q = 0; q < i - 1; ++q) {
        stack.pop();
    }
    return stack.pop();
}
















