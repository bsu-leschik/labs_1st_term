#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool contains(const double &element, const double maximums[], unsigned long length) {
    for (unsigned long i = 0; i < length; ++i) {
        if (maximums[i] == element) {
            return true;
        }
    }
    return false;
}

double cin_element(const int &i, const int &j) {
    double a;
    cout << "Enter " << j << " element from " << i << " string: ";
    cin >> a;
    return a;
}

vector<vector<double>> fill(const int &amount) {
    vector<vector<double>> matrix(amount);

    for (int i = amount - 1; i < matrix.size(); --i) {
        matrix[amount - i - 1].resize(amount - i);
    }

    for (int i = amount - 1; i >= 0; --i) {
        for (int j = 0; j < amount - i; ++j) {
            matrix[amount - i - 1][j] = cin_element(amount - i - 1, j);
        }
    }
    return matrix;
}

void mout(const vector<vector<double>> &matrix) {

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {
            if (i >= j) {
                cout << matrix[i][j] << " ";
            } else {
                cout << matrix[j][i] << " ";
            }
        }
        cout << endl;
    }
}

vector<vector<double>> maxes(vector<vector<double>> &matrix) {
    int i_max, j_max;
    double maximums[matrix.size()];
    bool first = true;
    for (int g = 0; g < matrix.size(); ++g) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix.size(); ++j) {
                bool swaped = false;
                if (i < j) {
                    swap(i, j);
                    swaped = true;
                }
                if (first && !contains(matrix[i][j], maximums, matrix.size())) {
                    i_max = i;
                    j_max = j;
                    first = false;
                    continue;
                }
                if ((matrix[i_max][j_max] < matrix[i][j]) && !contains(matrix[i][j], maximums, matrix.size())) {
                    i_max = i;
                    j_max = j;
                }
                if (swaped) {
                    swap(i, j);
                }
            }
        }

        maximums[g] = matrix[i_max][j_max];
        cout << endl;
        swap(matrix[g][g], matrix[i_max][j_max]);
        i_max = 0;
        j_max = 0;
        first = true;
    }
    return matrix;
}

int negativeString(vector<vector<double>> matrix) {

    /* It is enough to chek only 3 elements tha are on the diagonal, because
     * they are the greatest of all and there can be only 3 cases:
     * 1. All of them are positive - then there is no fully negative string
     * 2. One of them, or more, are negative - the first to be negative on diagonal represents
     * the first fully negative string
    */
    for (int i = 0; i < matrix.size(); ++i) {
        if (matrix[i][i] <= 0){
            return i;
        }
    }
    return -1;
}

int main() {

    int amount = 0;
    while (amount > 10 || amount <= 0) {
        cout << "Enter amount of elements in string" << endl;
        cin >> amount;

        if (amount > 10 || amount < 0){
            cout << "Amount of elements can be only between 0 and 11" << endl;
        }
    }



    vector<vector<double>> matrix(amount);

    matrix = fill(amount);


    cout << "Original matrix" << endl;
    mout(matrix);

    matrix = maxes(matrix);
    cout << "Matrix with changed diagonal" << endl;
    mout(matrix);

    int string_n = negativeString(matrix);
    if (string_n != -1) {
        cout << "First string, which has only negative elements(or zero): " << string_n << endl;
    } else {
        cout << "There is no string which has only negative elements(or zero)" << endl;
    }
}