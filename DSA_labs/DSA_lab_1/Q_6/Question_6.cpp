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
        M = vvi(n, vi(m, 0));  // Initialize matrix with zeros
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
        int sum_1 = 0;
        int sum_2 = 0;
        int sum_3 = 0;
        int sum = 0;
        int n = mat.n;
        int m = mat.m;

        for (int i = 0; i < m; i++) {  // Loop over columns
            sum_1 += mat.M[0][i];       // Sum of first row
        }

        if (n>1){
            
            for(int i=0;i<m;i++){
                sum_2+=mat.M[n-1][i];
            }

            for (int i = 1; i < n - 1; i++) {  // Loop over rows excluding first and last
                sum_3 += mat.M[i][(m - 1) / 2];  // Sum of the middle column
            }
            
        }


        sum = sum_1 + sum_2 + sum_3;
        return sum;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    // 1. Instantiate a Matrix object with the input shape taken.
    Matrix Mat(n, m);

    // 2. Use for loop to set its elements.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> Mat.M[i][j];
        }
    }

   

    // 3. Create a Solution object and call its member function solve.
    Solution S;
    int result = S.solve(Mat);

    // 4. Print the value returned by the member solve.
    cout << result << endl;

    return 0;
}
