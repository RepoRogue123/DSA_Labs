#include <iostream>
using namespace std;

int arr[101][101];

void col_wise_sum_of_transpose(int r, int c) {
    int final_arr[100];  // Array to store column-wise sums

    // Calculate column-wise sum of the transpose
    for(int i = 0; i < r; i++) {
        int sum = 0;
        for(int j = 0; j < c; j++) {
           sum+=arr[i][j];
        }
        final_arr[i] = sum;
    }

    // Print the resulting sums
    for(int i = 0; i < r; i++) {
        cout << final_arr[i] << " ";
    }
}

int main() {
    int rows, columns;
    
    cin >> rows >> columns;
    
    // Get the matrix
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cin >> arr[i][j];
        }
    }
    
    // Call the function to compute column-wise sums of the transpose
    col_wise_sum_of_transpose(rows, columns);

    return 0;
}
