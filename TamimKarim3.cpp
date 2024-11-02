#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values [0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}
vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    vector<vector<int>> matrix(m, vector<int>(n, -1));
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    int i = 0, j = 0, dir = 0;

    while (head) {
        matrix[i][j] = head->val;
        head = head->next;

        int ni = i + directions[dir][0];
        int nj = j + directions[dir][1];

        if (ni < top || ni > bottom || nj < left || nj > right || matrix[ni][nj] != -1) {
            if(dir == 0) top++;
            else if (dir == 1) right--;
            else if (dir == 2) bottom --;
            else if (dir == 3) left++;
            dir = (dir + 1) % 4;
            ni = i + directions[dir][0];
            nj = j + directions[dir][1];
        }
        i = ni;
        j = nj;
    }

    return matrix;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row){
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> values1 = {3, 0, 2, 6, 8, 1, 7, 9, 4, 2, 5, 5, 0};
    ListNode* head1 = createLinkedList(values1);
    int m1 = 3, n1 = 5;
    vector<vector<int>> result1 = spiralMatrix(m1, n1, head1);
    cout << "Output for Example 1 (m=3, m=5):" << endl;
    printMatrix(result1);

vector<int> values2 = {0, 1, 2};
ListNode* head2 = createLinkedList(values2);
int m2= 1, n2 = 4;
vector<vector<int>> result2 = spiralMatrix(m2, n2, head2);
cout << "Output for Example 2 (m=1, n=4):" << endl;
printMatrix(result2);

ListNode* temp;
while (head1 != nullptr) {
    temp = head1;
    head1 = head1->next;
    delete temp;
}

while (head2 != nullptr) {
    temp = head2;
    head2 = head2->next;
    delete temp;
    }

    return 0;
}
// Output for Example 1 (m=3, m=5):
// 3 0 2 6 8 
// 5 0 -1 -1 1
// 5 2 4 9 7

// Output for Example 2 (m=1, n=4):
//0 1 2 -1