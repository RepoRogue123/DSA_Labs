#include <iostream>
#include <vector>
#include <algorithm>  // Include this for sort function

using namespace std;

int main() {
    int size1; 
    cin >> size1;
    int size2 = size1;
    vector<int> A(size1);
    vector<int> B(size2);

    for (int i = 0; i < size1; i++) 
        cin >> A[i];
    for (int i = 0; i < size2; i++) 
        cin >> B[i];

    vector<int> arr;

    // Find elements in A that are not in B
    for (int i = 0; i < size1; i++) {
        int flag = 0;
        for (int j = 0; j < size2; j++) {
            if (A[i] == B[j]) {  
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            arr.push_back(A[i]);
        }
    }

    // Find elements in B that are not in A
    for (int i = 0; i < size2; i++) {
        int flag = 0;
        for (int j = 0; j < size1; j++) {
            if (B[i] == A[j]) {  
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            arr.push_back(B[i]);
        }
    }

    // Sort the array
    sort(arr.begin(), arr.end());

    // Print the result
    for (auto it : arr) {
        cout << it << " ";
    }
    return 0;
}
