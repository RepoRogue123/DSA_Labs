#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int arr[100][100];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int count_ones = 0;
    int count_zeros = 0;
    int diagonal_ones = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 1) {
                count_ones++;
            }
            if(arr[i][j] == 0) {
                count_zeros++;
            }
        }
    }

    // Check the main diagonal if the matrix is square (n == m)
    if(n == m) {
        for(int i = 0; i < n; i++) {
            if(arr[i][i] == 1) {
                diagonal_ones++;
            }
        }
    }

    if(count_ones == (n * m)) {
        cout << 1;
    } else if(count_zeros == (n * m)) {
        cout << 0;
    } else if(diagonal_ones == n && n == m) {
        cout << 2;
    } else {
        cout << -1;
    }

    return 0;
}










