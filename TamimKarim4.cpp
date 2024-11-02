#include <iostream>
#include <vector>
using namespace std;

bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    bool noOverlap = (rec1[2] <= rec2[0] || rec2[2] <= rec1[0] ||
                      rec1[3] <= rec2[1] || rec2[3] <= rec1[1]);

    return !noOverlap;                   
}

int main() {
    vector<int> rec1 = {0, 0, 2, 2};
    vector<int> rec2 = {1, 1, 3, 3};
    cout << "Example 1: " << boolalpha << isRectangleOverlap(rec1, rec2) << endl;

    rec1 = {0, 0, 1, 1};
    rec2 = {1, 0, 2, 1};
    cout << "Example 2: " << boolalpha << isRectangleOverlap(rec1, rec2) << endl;

    rec1 = {0, 0, 1, 1};
    rec2 = {2, 2, 3, 3};
    cout << "Example 3: " << boolalpha << isRectangleOverlap(rec1, rec2) << endl;

    return 0;
}
// Example 1: true
// Example 2: false
// Example 3: false