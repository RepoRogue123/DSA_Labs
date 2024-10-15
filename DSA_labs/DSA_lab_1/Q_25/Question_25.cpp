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

    void print_averages(int row, int col){
    // Complete the function here
    float sum_row=0;
    float sum_col=0;
    for(int i=0;i<m;i++){
        sum_row+=M[row][i];
    }
    for(int j=0;j<n;j++){
        sum_col+=M[j][col];
    }
    sum_row=(sum_row)/m;
    sum_col=(sum_col)/n;

    cout<<fixed<<setprecision(2)<<sum_row<<" ";
    cout<<fixed<<setprecision(2)<<sum_col;

        return;
    }
};


int main(){
    int n, m;
    
    // Input n and m here
    cin>>n>>m;
    
    Matrix mat(n,m);
    
    int row, col;
    // Input matrix and row and col here
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat.M[i][j];
        }
    }

    cin>>row>>col;
    
    mat.print_averages(row, col);
    
    return 0;
}