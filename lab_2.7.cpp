#include <iostream>
#include <random>
#include <iomanip>
#include <cmath>

void sort(double *arr, const int *size);
void max_freq(double *arr, const int *size);
int exists(double element, double* arr, const int* size);



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

    int unique_count = 0;
    sort(arr, &MAX);
    for (int i = 0; i < MAX; ++i) {
        if (i == 0){
            unique_count++;
            continue;
        }
        if (arr[i] != arr[i-1]){
            unique_count++;
        }
    }
    cout << unique_count << endl;
    for (int i = 0; i < unique_count; ++i) {
        max_freq(arr, &MAX);
    }
}

static int zeros;
static bool zero_first = true;
void max_freq(double* arr, const int* size) {

    int nulls = 0, amount = 0, max_amount = 0, i_max = 0;
    for (int i = 0; i < *size; ++i) {
        if (arr[i] == 0){
            ++nulls;
        }
    }
    if(zero_first){
        zeros = nulls;
        zero_first = false;
    }
    bool first = true;
    for (int i = 0; i < *size; ++i) {
        if (first && arr[i] != 0){
            first = false;
            amount++;
            continue;
        }
        if (arr[i] == 0){
            if (!first){
                if (amount > max_amount){
                    max_amount = amount;
                    i_max = i - 1;
                    amount = 0;
                } else {
                    amount = 0;
                }
            }
            continue;
        }
        while(arr[i] == arr[i - 1])  {
            amount ++;
            i ++;
        }
        if (arr[i] != arr[i - 1] || arr[i] != 0){
            if (amount > max_amount){
                max_amount = amount;
                i_max = i - 1;
                amount = 0;
            } else {
                amount = 0;
            }
        }
    }
    double temp = arr[i_max];
    if (zeros > max_amount) {
        cout << 0 << " ";
    } else {
        int temp_i = exists(temp, arr, size);
        cout << temp << " ";
        while (temp_i != -1) {
            arr[temp_i] = 0;
            temp_i = exists(temp, arr, size);
        }
    }
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