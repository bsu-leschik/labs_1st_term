#include "Stack.h"

template<typename T>
int Stack<T>::getSize() {
    return size;
}

template<typename T>
T Stack<T>::top() {
    return stackBase[size - 1];
}

template<typename T>
T Stack<T>::pop() {
    --size;
    return stackBase[size];
}

template<typename T>
void Stack<T>::push(T value) {
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

template<typename T>
void Stack<T>::print(std::ostream &out) {
    for (int i = 0; i < size; ++i) {
        out << stackBase[i] << " ";
    }
    out << std::endl;
}

template<typename T>
bool Stack<T>::isEmpty() {
    return size;
}

template<typename T>
void Stack<T>::resize() {
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

template<typename T>
Stack<T>::~Stack() {
    delete[] stackBase;
}

template<typename T>
Stack<T> &operator<<(Stack<T> &stack, T el) {
    stack.push(el);
    return stack;
}

template<typename T>
void operator>>(Stack<T> &stack, T &el) {
    el = stack.pop();
}

template<typename T>
Stack<T> &Stack<T>::operator=(Stack<T> &stack) {
    this->size = stack.size;
    delete[] this->stackBase;
    this->stackBase = new T[stack.size];
    for (int i = 0; i < stack.size; ++i) {
        &stackBase[i] = &(stack.stackBase[i]);
    }
    return *this;
}

template<typename T>
bool operator<(Stack<T> &stack, Stack<T> &stack1) {
    return (stack.size < stack1.size);
}

template<typename T>
bool operator>(Stack<T> &stack, Stack<T> &stack1) {
    return (stack.size > stack1.size);
}

template<typename T>
bool operator==(Stack<T> &stack, Stack<T> &stack1) {
    return (stack.size == stack1.size);
}

template<typename T>
T Stack<T>::operator[](int i) {
    Stack stack = *this;
    for (int q = 0; q < i - 1; ++q) {
        stack.pop();
    }
    return stack.pop();
}

