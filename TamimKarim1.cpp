#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

string kthDistinctString(const vector<string>& arr, int k) {
    unordered_map<string, int> freq;

    for (const string& s : arr) {
        freq[s]++;
    }
    
    int distinctCount = 0;
    for (const string& s : arr) {
        if (freq[s] == 1) {
            distinctCount++;
            if (distinctCount == k) {
                return s;
            }
        }
    }
    return "";
}

int main() {
     vector<string> arr1 = {"d", "b","c", "b", "c", "a"};
     int k1 = 2;
     cout << "Output for Test Case 1: " <<kthDistinctString(arr1, k1) << endl;

     vector<string> arr2 = {"aaa", "aa", "a"};
     int k2 = 1;
     cout << "Output for Test Case 2: " << kthDistinctString(arr2, k2) << endl;

     vector<string> arr3 = {"a", "b", "a"};
     int k3 = 3;
     cout << "Output for Test Case 3: " <<kthDistinctString(arr3, k3) << endl;

     return 0;
}
// Output for Test Case 1: a
// Output for Test Case 2: aaa
// Output for Test Case 3:     