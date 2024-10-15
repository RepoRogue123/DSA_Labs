#include <bits/stdc++.h>
using namespace std;

int calculateDiagonalSum(int n, const vector<vector<int>>& matrix) {
    int sum_1 = 0;  // Sum of the primary diagonal (left diagonal)
    int sum_2 = 0;  // Sum of the secondary diagonal (right diagonal)

    for (int i = 0; i < n; ++i) {
        sum_1 += matrix[i][i];         // Elements of the primary diagonal
        if(n>1){
            sum_2 += matrix[i][n - 1 - i];   // Elements of the secondary diagonal
        }
       
    }

    return sum_1+sum_2;

}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    // Input matrix elements
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Calculate and print the diagonal sum
    int result = calculateDiagonalSum(n, matrix);
    cout << result << endl;

    return 0;
}
