#include <iostream>
#include <random>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    //Instead of taking a lot of memory space, which might not even be used,
    //I allow user to define max and real amount of elements in one.
    cout << "Enter amount of doubles in array" << endl;
    int max;
    cin >> max;

    const int MAX = max;
    auto *arr = new double[MAX];

    bool input = true;
    int id, lim1, lim2;
    while (input) {
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
                cout << "Enter values one by one. After you entered one value press enter. Use dots instead of commas"
                     << endl;
                for (int i = 0; i < MAX; ++i) {
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
    if (id == 1) {
        random_device rd;
        mt19937 rng(rd());
        uniform_int_distribution<> dist6(lim1 * 7, lim2 * 7);
        for (int i = 0; i < MAX; ++i) {
            double temp;
            temp = (double) dist6(rng);
            temp = temp / 7;
            *(arr + i) = temp;
        }
    }
    //Output of array, just to be sure that everything is working
    for (int i = 0; i < MAX; ++i) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
    //finding max value
    double cur;
    double lmax;
    for (int i = 0; i < MAX; ++i) {
        cur = *(arr + i);
        if (i == 0) {
            lmax = cur;
            continue;
        }
        if (fabs(lmax) < fabs(cur)) {
            lmax = cur;
        }
    }
    cout << "The maximum modulo element of the array: " << fixed << setprecision(5) << lmax << endl;
    //The second question: sum of elements, which are between two elements greater then zero
    double sum = 0;
    bool plus_1 = true;
    for (int i = 0; i < MAX; ++i) {
        cur = *(arr + i);
        if (cur > 0 && plus_1) {
            plus_1 = false;
            continue;
        }
        if (cur > 0 && !plus_1) {
            break;
        }
        if (!plus_1) {
            sum = (double) sum + cur;
        }
    }
    cout << "Sum of elements, which are between two elements that are greater then zero " << fixed << setprecision(5)
         << sum << endl;
    //Arrange the elements in descending order of their frequency of occurrence

    for (int i = 0; i < MAX; ++i) {
        for (int j = 1; j < MAX; ++j) {
            if (*(arr + j - 1) < *(arr + j)) {
                swap(*(arr + j - 1), *(arr + j));
            }
        }
    }

    int arr_l = MAX,am = 0, am_max = 0, ii = 0 ,nulls = 0;
    for (int i = 0; i < MAX; ++i) {
        cout << *(arr + i) << " ";
        if (*(arr + i) == 0){
            ++nulls;
        }
    }
    cout << endl;
    for (int i = 0; i < MAX; ++i) {
        bool first = true;
        for(int j = 0; j < arr_l; ++j){
            if (*(arr + j) == 0){
                continue;
            }
            if (first){
                ++am;
                first = false;
                continue;
            }
            if (*(arr + j) != *(arr + j - 1)) {
                if (am > am_max) {
                am_max = am;
                ii = j - 1;
                }
                am = 1;
                continue;
            } else {
                ++am;
            }
            if (arr_l - 1 == j){
                am_max = am;
                ii = j - 1;
            }
        }
        if (nulls > ii) {
            cout << 0 << " ";
        } else {
            cout << *(arr + ii) << " ";
        }
        for (int t = 0; t > ii - am_max; --t) {
            *(arr + t) = 0;
        }
        ii = 0;
        am_max = 0;
    }
}
