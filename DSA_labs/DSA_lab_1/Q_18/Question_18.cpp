#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n][n];
    vector<int> final_arr;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int sum_1 = 0;
    int sum_2 = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= i) {
                sum_1 += arr[i][j];  // Sum of upper triangular part
            }
            if (i >= j) {
                sum_2 += arr[i][j];  // Sum of lower triangular part
            }
        }
    }

    final_arr.push_back(sum_1);
    final_arr.push_back(sum_2);

    for (auto it : final_arr) {
        cout << it << " ";
    }

    return 0;
}
