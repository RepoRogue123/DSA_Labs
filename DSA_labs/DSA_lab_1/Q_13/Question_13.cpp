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
    int solve(matrix& mat){
        //write your code here, return the answer in the end.
        int n=mat.n;
        int m=mat.m;
        int sum=0;

        for(int i=0;i<m;i++){
            if(i%2==0){
                for(int j=0;j<n;j++){
                    sum+=mat.M[j][i];
                }
            }
        }

        return sum;
    }
};

int main(){

    int n,m; 
    cin >> n >> m;
    matrix mat(n,m);
    
    for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
            cin >> mat.M[i][j];
            }

    }
    

    solution sol;
    cout << sol.solve(mat);

    return 0;
}