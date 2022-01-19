#include <iostream>
#include <random>
#include <iomanip>
#include <cmath>

void sort(double *arr, const int *size);
void max_freq(double *arr, const int *size);
int exists(double element, double* arr, const int* size);
double* sorting(double* mas, int length);


using namespace std;

bool isIn(double element, const double* mas, int length){
    for (int i = 0; i < length; ++i) {
        if (mas[i] == element){
            return true;
        }
    }
    return false;
}




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


    sorting(arr, max);


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
    delete[] arr;
}

double* sorting(double* mas, int length) {

    //statistics
    int last = 0;
    double *masInts = new double[length];
    double *masStat = new double[length];
    for (int i = 0; i < length; ++i) {
        double cur = mas[i];
        if (!isIn(cur, masInts, length)){
            masInts[last] = cur;
            last++;
        } else {
            continue;
        }
        for (int j = i; j < length; ++j) {
            if (mas[j] == cur) {
                masStat[last - 1]++;
            }
        }
    }

    //sorting
    for (int i = 0; i < last; ++i) {
        for (int j = 1; j < last; ++j) {
            if (masStat[i + j - 1] < masStat[i + j]){
                swap(masStat[i + j - 1], masStat[i + j]);
                swap(masInts[i + j - 1], masInts[i + j]);
            }
        }
    }

    //sorting main array
    int num = 0;
    for (int i = 0; i < last; ++i) {
        double cur = masInts[i];
        for (int j = 0; j < masStat[i]; ++j) {
            mas[num] = cur;
            num++;
        }
    }

    cout << endl;
    for (int i = 0; i < length; ++i) {
        cout << mas[i] << " ";
    }

    delete[] masInts;
    delete[] masStat;
    return mas;
}

void sort(double *arr, const int* size) {
    for (int i = 0; i < *size; ++i) {
        for (int j = 1; j < *size; ++j) {
            if (*(arr + j - 1) < *(arr + j)) {
                swap(*(arr + j - 1), *(arr + j));
            }
        }
    }
}

int exists(double element, double* arr, const int* size){
    for (int i = 0; i < *size; ++i) {
        if (element == arr[i]){
            return i;
        }
    }
    return -1;
}