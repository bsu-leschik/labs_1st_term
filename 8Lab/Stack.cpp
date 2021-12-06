#include <iostream>
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
            stackBase = new double[size++];
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
            std::cout << stackBase[i] << " ";
        }
        std::cout << std::endl;
    }

    bool Stack::isEmpty() {
        return size;
    }

Stack::~Stack() {
    delete[] stackBase;
}











