#include<bits/stdc++.h>

using namespace std;

class MatrixClass {
public:  
    int n;
    vector<vector<int>> M;

    MatrixClass(int number, vector<vector<int>> matrix) {
        n = number;
        M = matrix;
    }

    void get_matrix() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << M[i][j] << " ";  // Displays the input matrix 
            }
            cout << endl;
        }
    }

    void extract_Lower_Upper() {
        vector<vector<int>> lower(n, vector<int>(n, 0));
        vector<vector<int>> upper(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i >= j) {
                    lower[i][j] = M[i][j];  // Lower triangular matrix
                }
                if(j >= i) {
                    upper[i][j] = M[i][j];  // Upper triangular matrix
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << lower[i][j] << " ";  // Print lower triangular matrix
            }
            for(int j = 0; j < n; j++) {
                cout << upper[i][j] << " ";  // Print upper triangular matrix
            }
            cout << endl;  // New line after each row
        }
    } 
};

int main() {
    
    vector<vector<int>> matrix(3, vector<int>(3, 0));

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> matrix[i][j];
        }
    }

    MatrixClass M(3, matrix);
    M.extract_Lower_Upper();

    return 0;
}
