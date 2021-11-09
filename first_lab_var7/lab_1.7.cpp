#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

int main() {

    int k;
    double x;
    double result = 1;
    double temp_result, ideal_result;
    double limit;
    bool plus = false;


    cout << "Write x, k" << endl;
    cin >> x >> k;
    if (x >= 1 || x <= -1) {
        cout << "x and k which you entered cannot be used. Use values only from (-1;1)" << endl;
        return 1;
    }

    double i = 2;
    limit = pow(10, -k);

    do {
        temp_result = (i * (i + 1) * pow(x, i - 1)) / 2;

        if (plus) {
            result = result + temp_result;
            plus = false;
        } else {
            result = result - temp_result;
            plus = true;
        }
        i++;
    } while (temp_result > limit || temp_result < 0);

    cout << x << endl;

    ideal_result = 1/pow((1+x),3);
    cout << fixed << setprecision(k) <<  ideal_result << endl;


    cout << "Result calculated with help of Taylor series: " << fixed << setprecision(k) <<  result << endl;
    cout << "Result calculated with simple formula: " << fixed << setprecision(k) << 1/ideal_result << endl;
    cout << "Difference: " << fixed << setprecision(k) << result - ideal_result << endl;
    return 0;
}
