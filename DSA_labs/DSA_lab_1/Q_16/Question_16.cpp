#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

class matrix{
public:
    int n,m;
    vvi M;
    matrix(int shape0, int shape1){
        n = shape0;
        m = shape1;
        M = vvi(n,vi(m,0));
    }
    void displayMatrix(){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cout << M[i][j] << ' ';
            cout << '\n';
        }
    }
};

class solution{
public:
    void solve(matrix& mat){
        int n=mat.n;
        int m=mat.m;
        // Write the code here, complete the function to modify the matrix in-place
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=j+1;k<m;k++){
                    if(mat.M[i][j]>mat.M[i][k]){
                        int temp=mat.M[i][j];
                        mat.M[i][j]=mat.M[i][k];
                        mat.M[i][k]=temp;
                    }
                }
            }
        }

    }
};

int main(){
   

    // 1. Instantiate a matrix object with the input shape taken
    int n,m;
    cin>>n>>m;

    matrix mat(n,m);
    // 2. use for loop to set it's elements
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat.M[i][j];
        }
    }
    // 3. Create a solution object and call its member function solve
    solution sol;
    sol.solve(mat);
    // 4. Member solve will modify the matrix. Now call the member function displayMatrix.
    mat.displayMatrix();

    return 0;
}