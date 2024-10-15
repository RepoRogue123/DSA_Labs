#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;

    int arr[100][100];

    // Input the array elements
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int row_start = 0, row_end = n - 1;
    int col_start = 0, col_end = m - 1;

    // Using a set of `for` loops to handle spiral printing
    for (; row_start <= row_end && col_start <= col_end; row_start++, col_end--, row_end--, col_start++) {
        
        // Print the top row
        for (int i = col_start; i <= col_end; i++) {
            cout << arr[row_start][i] << " ";
        }

        // Print the right column
        for (int i = row_start + 1; i <= row_end; i++) {
            cout << arr[i][col_end] << " ";
        }

        // Print the bottom row
        if (row_start < row_end) {
            for (int i = col_end - 1; i >= col_start; i--) {
                cout << arr[row_end][i] << " ";
            }
        }

        // Print the left column
        if (col_start < col_end) {
            for (int i = row_end - 1; i > row_start; i--) {
                cout << arr[i][col_start] << " ";
            }
        }
    }

    return 0;
}
