#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

bool compare(string line1, string line2) {
    if (line1 == line2) {
        return true;
    }
    return false;
}

char *takePath() {
    char *path = new char[50];
    cout << "Enter the address to the file" << endl;
    cin >> path;
    ifstream reader(path);
    if (!reader) {
        cout << "Oops, something went wrong, check the accuracy of input data" << endl;
        return takePath();
    }
    return path;
}

int lineAmount(char *path) {
    ifstream file(path);
    int i = 0;
    vector<string> text;
    while (file) {
        string temp;
        getline(file, temp);
        ++i;
    }
    return --i;
}

vector<string> read(char *path) {
    ifstream fin(path);
    int length = lineAmount(path);
    vector<string> text(length);
    for (int i = 0; i < length ; ++i) {
        fin >> text[i];
    }
    return text;
}

int main() {
    char *path;
    path = takePath();
    vector<string> text = read(path);




    return 0;
}
