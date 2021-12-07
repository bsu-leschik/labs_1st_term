#include <iostream>
#include "Stack.h"

using namespace std;

int main(){
    Stack<double> stack;
    cout << stack.isEmpty() << endl;
    stack << 5;
    cout << stack.getSize() << " ";
    stack.push(5.6);
    cout << stack.getSize() << " ";
    stack.push(3.24);
    cout << stack.getSize() << " ";
    stack.push(9.712);
    cout << stack.getSize() << endl;
    cout << stack.pop() << endl;
    cout << stack.top() << endl;
    stack.print(cout);
    cout << stack.isEmpty() << endl;
    //cout << "Second: " << stack[2] << endl;
    Stack<double> stack1;
    stack1 << 220 << 6 << 7 << 8 << 9;
    double poped;
    stack1 >> poped;
    cout << "Poped: " << poped;
    cout << "Logical operations: " << (stack < stack1) << " " << (stack > stack1) << " " << (stack == stack1) << endl;
    stack = stack1;
}