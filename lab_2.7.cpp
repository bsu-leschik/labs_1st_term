#include <iostream>

using namespace std;

int main(){
    //Instead of taking a lot of memory space, which might not even be used,
    //I allow user to define max and real amount of elements in one.
    cout << "Enter amount of doubles in array" << endl;
    int max;
    cin >> max;

    const int MAX = max;
    auto *arr = new double[MAX];

    bool input = true;
    int id;
    while(input){
        cout << "For random filling enter 1, for custom 2" << endl;
        cin >> id;
        if(id == 1 || id == 2){
            input = false;
        }
    }



}