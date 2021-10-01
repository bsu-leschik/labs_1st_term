#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool contains(const double& element, const double maximums[], unsigned long length){
    for (unsigned long i = 0; i < length; ++i) {
        if (maximums[i] == element){
            return true;
        }
    }
    return false;
}

double cin_element(const int& i,const int& j){
    double a;
    cout << "Enter " << j << " element from " << i << " string: ";
    cin >> a;
    return a;
}

vector<vector<double>> fill(const int& amount){
    vector<vector<double>> matrix(amount);

    for (int i = 0; i < matrix.size(); ++i) {
        matrix[i].resize(matrix.size());
    }

    for (int i = 0; i < amount; ++i) {
        for (int j = 0; j < amount; ++j) {
            matrix[i][j] = cin_element(i, j);
        }
    }
    return matrix;
}

void mout(const vector<vector<double>>& matrix){

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<double>> maxes(vector<vector<double>>& matrix){
    int i_max, j_max;
    double maximums[matrix.size()];
    bool first = true;
    for (int g = 0; g < matrix.size(); ++g) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix.size(); ++j) {
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


int main(){

    int amount;
    cout << "Enter amount of elements in string" << endl;
    cin >> amount;

    vector<vector<double>> matrix(amount);

    matrix = fill(amount);
    cout << "Original matrix" << endl;
    mout(matrix);

    matrix = maxes(matrix);
    cout << "Matrix with changed diagonal" << endl;
    mout(matrix);

    //cout << "First string, which has only negative elements: " << negativeString(matrix) << endl;
}