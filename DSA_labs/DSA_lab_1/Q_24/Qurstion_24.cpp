#include<bits/stdc++.h>

using namespace std;

class Matrix{
    private:
    
    public:
    int n, m;
    vector<vector<int>> M;
    
    Matrix(int rowsize, int colsize){
        n = rowsize;
        m = colsize;
        M = vector<vector<int>>(n, vector<int>(m, 0));
    }
    
    void printMatrix() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << M[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    void add_k_matrix(int k, int row1, int col1, int row2, int col2) {
        // Ensure that the row1, col1 is the top-left corner and row2, col2 is the bottom-right corner
        if(row1>row2){
            int temp=row1;
            row1=row2;
            row2=temp;
        }
        if(col1>col2){
            int temp=col1;
            col1=col2;
            col2=temp;

        }
        
        for(int i = row1; i <= row2; i++) {
            for(int j = col1; j <= col2; j++) {
                M[i][j] += k;
            }
        }
    }
};


int main(){
    int n = 0, m = 0;
    
    // Input n and m here
    cin >> n >> m;
    
    Matrix mat(n, m);
    
    int k, row1, col1, row2, col2;
    
    // Input M matrix here
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat.M[i][j];
        }
    }
    
    // Input k and submatrix boundaries here
    cin >> k >> row1 >> col1 >> row2 >> col2;
    
    // Apply addition to the submatrix
    mat.add_k_matrix(k, row1, col1, row2, col2);
    
    // Print the updated matrix
    mat.printMatrix();
    
    return 0;
}
