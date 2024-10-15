#include <bits/stdc++.h>
using namespace std;

int main() {
    int size1; 
    cin >> size1;
    
    int size2 = size1;
    vector<int> A(size1);
    vector<int> B(size2);

    for (int i = 0; i < size1; i++) cin >> A[i];
    for (int i = 0; i < size2; i++) cin >> B[i];

    // Step 1: Sort both arrays
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Step 2: Remove duplicates from both arrays
    A.erase(unique(A.begin(), A.end()), A.end());
    B.erase(unique(B.begin(), B.end()), B.end());

    // Step 3: Find (A - B)
    vector<int> diffA;
    for (int i = 0; i < A.size(); i++) {
        int found = 0;
        for (int j = 0; j < B.size(); j++) {
            if (A[i] == B[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            diffA.push_back(A[i]);
        }
    }

    // Output (A - B)
    for (auto it : diffA) {
        cout << it << " ";
    }
    cout << endl;

    // Step 4: Find (B - A)
    vector<int> diffB;
    for (int i = 0; i < B.size(); i++) {
        int found = 0;
        for (int j = 0; j < A.size(); j++) {
            if (B[i] == A[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            diffB.push_back(B[i]);
        }
    }

    // Output (B - A)
    for (auto it : diffB) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
