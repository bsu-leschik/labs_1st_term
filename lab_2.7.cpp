#include <iostream>
#include <random>
#include <iomanip>
#include <cmath>

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
    int id, lim1, lim2;
    while(input){
        cout << "For random filling enter 1, for custom 2" << endl;
        cin >> id;
        switch (id) {
            case 1: {
                cout << "Enter the limits of random filling like this:-10 10" << endl;
                cin >> lim1 >> lim2;
                input = false;
                break;
            }
            case 2: {
                input = false;
                cout << "Enter values one by one. After you entered one value press enter. Use dots instead of commas" << endl;
                for (int i = 0; i < MAX; ++i){
                    cout << i << " : ";
                    cin >> *(arr + i);
                }
                break;
            }
            default: {
                cout << "Something went  wrong): Check out accuracy of input data." << endl;
            }
        }
    }
    //Filing with random numbers
    if (id == 1){
        random_device rd;
        mt19937 rng(rd());
        uniform_int_distribution<> dist6(lim1 * 7, lim2 * 7);
        for (int i = 0; i < MAX; ++i){
            double temp;
            temp = (double) dist6(rng);
            temp = temp / 7;
            *(arr + i) = temp;
        }
    }
    //finding max value
    double  cur;
    double lmax;
    for (int i = 0; i < MAX; ++i) {
        cur = *(arr + i);
        if(i == 0){
            lmax = cur;
            continue;
        }
        if (fabs(lmax) < fabs(cur)){
            lmax = cur;
        }
    }
    cout << "The maximum modulo element of the array:" << fixed << setprecision(5) << lmax << endl;



}