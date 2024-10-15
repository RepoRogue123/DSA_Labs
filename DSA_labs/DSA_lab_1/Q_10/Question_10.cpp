#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

class matrix {
public:
    int n, m;
    vvi M;
    matrix(int shape0, int shape1) {
        n = shape0;
        m = shape1;
        M = vvi(n, vi(m, 0));
    }
    void displayMatrix() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cout << M[i][j] << ' ';
            cout << '\n';
        }
    }
};

class solution {
public:
    void solve(matrix& mat) {
        int n = mat.n;
        int m = mat.m;
        m=n;
        int count_zero_rows = 0;
        int count_zero_cols = 0;

        vector<int> zero_row(n, 0);
        vector<int> zero_col(m, 0);

        // Counting and marking zero rows
        for (int i = 0; i < n; i++) {
            int x = 0;
            for (int j = 0; j < m; j++) {
                if (mat.M[i][j] == 0) {
                    x++;
                }
            }
            if (x == m) {
                zero_row[i] = 1;  // Mark the row as zero
                count_zero_rows++;
            }
        }

        // Counting and marking zero columns
        for (int i = 0; i < m; i++) {
            int y = 0;
            for (int j = 0; j < n; j++) {
                if (mat.M[j][i] == 0) {
                    y++;
                }
            }
            if (y == n) {
                zero_col[i] = 1;  // Mark the column as zero
                count_zero_cols++;
            }
        }

        int new_n = n - count_zero_rows;
        int new_m = m - count_zero_cols;

        vvi final_arr(new_n, vi(new_m, 0));

        int ni = 0;
        for (int i = 0; i < n; i++) {
            if (zero_row[i]) continue; // Skip the marked row
            int nj = 0;
            for (int j = 0; j < m; j++) {
                if (zero_col[j]) continue; // Skip the marked column
                final_arr[ni][nj] = mat.M[i][j];
                nj++;
            }
            ni++;
        }

        mat.M = final_arr;
        mat.n = new_n;
        mat.m = new_m;
    }
};

int main() {
    int n;
    cin >> n ;
    matrix Mat(n, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> Mat.M[i][j];
        }
    }

    solution S;
    S.solve(Mat);

    Mat.displayMatrix();

    return 0;
}
