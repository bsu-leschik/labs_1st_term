#include <iostream>
#include "Stack.h"

using namespace std;

int main(){
    Stack stack;
    cout << stack.isEmpty() << endl;
    stack.push(5);
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

}