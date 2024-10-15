#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> spiralMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0)); // Initialize the matrix with 0s
    int row_start = 0;
    int row_end = n - 1;
    int col_start = 0;
    int col_end = n - 1;
    int start_num = 1;

    
    for (; row_start <= row_end && col_start <= col_end; row_start++, row_end--, col_start++, col_end--) {
        // Fill the top row
        for (int i = col_start; i <= col_end; i++) {
            matrix[row_start][i] = start_num++;
        }

        // Fill the right column
        for (int i = row_start + 1; i <= row_end; i++) {
            matrix[i][col_end] = start_num++;
        }

        // Fill the bottom row 
        if (row_start <= row_end) {
            for (int i = col_end - 1; i >= col_start; i--) {
                matrix[row_end][i] = start_num++;
            }
        }

        // Fill the left column 
        if (col_start <= col_end) {
            for (int i = row_end - 1; i > row_start; i--) {
                matrix[i][col_start] = start_num++;
            }
        }
    }

    return matrix;
}

int main() {
    int n;

    // Taking input for the size of the matrix
    cin >> n;

    // Function call to generate the spiral matrix
    vector<vector<int>> result = spiralMatrix(n);

    // Printing the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
