#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

char *takePath() {
    char *path = new char[100];
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

vector<vector<int>> equalStrings(vector<string> text){
    int equalAmount = 1;
    vector<vector<int>> IndexAmount;
    for (int i = 1; i < text.size(); ++i) {
        if (text[i] == text[i - 1]){
            int j = i;
            vector<int> temp;
            temp.push_back(i);
                while (text[j] == text[j - 1]) {
                    ++equalAmount;
                    ++j;
                }
                i = j;
            temp.push_back(equalAmount);
            IndexAmount.push_back(temp);
            equalAmount = 1;
        }
    }
    return IndexAmount;
}

char* pathToPackage(const char* path){
    int i = 0, j = 0;
    while (path[i] != '\0'){
        ++i;
    }
    char* pathPackage = new char[i + 1];
    for (int k = i; path[k - 1] != '/'; --k) {
        ++j;
    }

    i -= j;
    for (int k = 0; k < i; ++k) {
        pathPackage[k] = path[k];
    }
    pathPackage[i + 1] = '\0';
    return pathPackage;
}

void output(const vector<vector<int>>& IndexAmount, vector<string> text,char* pathPackage){
    string file = "output.txt";
    string path = pathPackage + file;
    ofstream fout(path);
    for (int i = 0; i < IndexAmount.size(); ++i) {
        int index = IndexAmount[i][0];
        int amount = IndexAmount[i][1];
        string line = text[index];
        fout << "Line \"" << line << "\" starting from line " << index << " appeared to repeat " << amount << " times" << endl;
    }
    cout << "The file lies in: " << path;
}

int main() {
    char *path;
    path = takePath();
    vector<string> text = read(path);
    vector<vector<int>> IndexAmount = equalStrings(text);
    char *pathPackage = pathToPackage(path);
    output(IndexAmount, text, pathPackage);
    return 0;
}
