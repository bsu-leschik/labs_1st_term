#include <iostream>

using namespace std;


char * strchr(char* string, int symbol){

    int i = 0;
     do {
        if (*(string + i) == symbol){
            return string + i;
        }
        ++i;
    }while (string[i - 1] != '\0');
    return nullptr;
}


int main(){
    int amount;
    char symbol;
    cout << "Enter amount of elements in the string: ";
    cin >> amount;
    char* string = new char[amount + 1];
    cout << "Enter the string: ";
    cin >> string;
    cout << "Enter the symbol, which you want to find: ";
    cin >> symbol;
    cout << *strchr(string, symbol);

}


