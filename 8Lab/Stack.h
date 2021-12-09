#ifndef GOOGLE_TESTS_STACK_H
#define GOOGLE_TESTS_STACK_H


#include <ostream>

template<typename T>
class Stack {
private:
    T *stackBase = new T[0];
    int size = 0;

public:
    friend Stack<T> &operator<<(Stack<T> &stack, T el){
        stack.push(el);
        return stack;
    }

    friend void operator>>(Stack<T> &stack, T &el){
        el = stack.pop();
    }

    Stack<T> &operator=(Stack<T> stack){
        this->size = stack.size;
        delete[] this->stackBase;
        this->stackBase = new T[stack.size];
        int temp;
        for (int i = 0; i < stack.size; ++i) {
            temp = stack.stackBase[i];
            stackBase[i] = temp;
        }
        stack.stackBase = nullptr;
        return *this;
    }

    friend bool operator<(Stack<T> &stack, Stack<T> &stack1){
        return (stack.size < stack1.size);
    }

    friend bool operator>(Stack<T> &stack, Stack<T> &stack1) {
        return (stack.size > stack1.size);
    }

    friend bool operator==(Stack<T> &stack, Stack<T> &stack1) {
        return (stack.size == stack1.size);
    }

    T operator[](int i) {
        Stack<T> stack = *this;
        for (int q = 0; q < i - 1; ++q) {
            stack.pop();
        }
        T out = stack.pop();
        return out;
    }


    int getSize() {
        return size;
    }

    T top() {
        return stackBase[size - 1];
    }

    T pop() {
        --size;
        return stackBase[size];
    }

    void push(T value) {
        if (size != 0) {
            T temp[size];
            for (int i = 0; i < size; ++i) {
                temp[i] = stackBase[i];
            }
            delete[] stackBase;
            stackBase = new T[++size];
            for (int i = 0; i < size - 1; ++i) {
                stackBase[i] = temp[i];
            }
        } else {
            delete[] stackBase;
            stackBase = new T[++size];
        }
        stackBase[size - 1] = value;
    }

    void print(std::ostream &out) {
        for (int i = 0; i < size; ++i) {
            out << stackBase[i] << " ";
        }
        out << std::endl;
    }

    bool isEmpty() {
        return size;
    }

    void resize() {
        T temp[size];
        for (int i = 0; i < size; ++i) {
            temp[i] = stackBase[i];
        }
        delete[] stackBase;
        stackBase = new T[size];
        for (int i = 0; i < size; ++i) {
            stackBase[i] = temp[i];
        }
    }

    ~Stack() {
        delete[] stackBase;
    }

};


#endif //GOOGLE_TESTS_STACK_H
