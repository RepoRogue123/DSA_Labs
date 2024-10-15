#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

class Matrix {
public:
    int n, m;
    vvi M;

    Matrix(int shape0, int shape1) {
        n = shape0;
        m = shape1;
        M = vvi(n, vi(m, 0));
    }

    void displayMatrix() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) 
                cout << M[i][j] << ' ';
            cout << '\n';
        }
    }
};

class Solution {
public:
    int solve(Matrix &mat) {
        int n = mat.n;
        int m = mat.m;
        int flag = 0;

        // Check the four corners of the matrix
        if (n > 1 && m > 1) {
            if (mat.M[0][0] == 1 && mat.M[0][m - 1] == 1 && mat.M[n - 1][0] == 1 && mat.M[n - 1][m - 1] == 1) {
                flag = 1;
            }
        }

        return flag;
    }
};

int main() {
    // 1. Instantiate a matrix object with the input shape taken.
    int n, m;
    cin >> n >> m;
    Matrix mat(n, m);

    // 2. Use for loop to set its elements.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat.M[i][j];
        }
    }

    // 3. Create a Solution object and call its member function solve.
    Solution sol;
    int result = sol.solve(mat);

    // 4. Print the value returned by the member solve.
    cout << result << endl;

    return 0;
}
