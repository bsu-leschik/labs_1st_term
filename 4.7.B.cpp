#include <iostream>
#include <vector>

using namespace std;

int slash(const char* string){
    int i = 0;
    while(string[i] != '\0'){
        if (string[i] == '/'){
            return i;
        }
        i++;
    }
    return -1;
}

vector<int> charVectorToInt(const vector<vector<char>>& numV){
    vector<int> nums = {0,0,0};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < numV[i].size(); ++j) {
            if (isdigit(numV[i][j])) {
                nums[i] = nums[i] * 10 + numV[i][j] - '0';
            } else {
                vector<int> temp = {-1,-1,-1};
                return temp;
            }
        }
    }
    return nums;
}

bool trueData(vector<int>& data){
    if (data[0] > 0 && data[0] < 32){
        if (data[1] > 0 && data[1] < 13){
            return true;
        }
    }
    return false;
}

int datas(char* string){
    int amount = 0;
    vector<vector<char>> data(3);

    while (slash(string) != -1) {
        int i = slash(string);
            data[0].push_back(string[i - 2]);
            data[0].push_back(string[i - 1]);
            int j = 0;
        while (string[i + j] != '\0'){
            ++j;
        }
        if (j <= i + 7){
            if (string[i + 3] == '/' && (string[i + 7] == ' ' || string[i + 7] == '\0')) {
                if (i - 2 == 0) {
                    string[i] = 'q';
                    continue;
                } else if (string[i - 3] == ' ') {
                    string[i] = 'q';
                    continue;
                }
            }


        }
        if (string[i + 3] == '/') {
            data[1].push_back(string[i + 1]);
            data[1].push_back(string[i + 2]);
        } else {
            string[i] = 'q';
            continue;
        }
            data[2].push_back(string[i + 4]);
            data[2].push_back(string[i + 5]);
            data[2].push_back(string[i + 6]);
            data[2].push_back(string[i + 7]);
            string[i] = 'q';
            string[i + 3] = 'q';

        vector<int> dataI = charVectorToInt(data);
        if (trueData(dataI)){
            ++amount;
        }
        data.clear();
        data.resize(3);
    }
    return amount;
}

int main(){
    char* string = new char[301];
    cout << "Enter the string:" << endl;
    cin.getline(string, 301);
    cout << "Amount of true datas: " << datas(string);
    delete[] string;
}