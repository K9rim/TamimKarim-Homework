#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> row(rowIndex + 1, 1);

    for (int i = 1; i < rowIndex; i++) {
        for (int j = i; j > 0; j--) {
            row[j] = row[j] + row[j - 1];
        }
    }

    return row;
}

int main() {
    int rowIndex1 = 3;
    vector<int> result1 = getRow(rowIndex1);
    cout << "Output for rowIndex = 3: ";
    for (int num : result1) cout << num << " ";
    cout << endl;

    int rowIndex2 = 0;
    vector<int> result2 = getRow(rowIndex2);
    cout << "Output for rowIndex = 0: ";
    for (int num : result2) cout << num <<" ";
    cout << endl;

    int rowIndex3 = 1;
    vector<int> result3 = getRow(rowIndex3);
    cout << "Output for rowIndex = 1: ";
    for (int num : result3) cout << num <<" ";
    cout << endl;

    return 0;
}
// Output for rowIndex = 3: 1 3 3 1 
// Output for rowIndex = 0: 1
// Output for rowIndex = 1: 1 1