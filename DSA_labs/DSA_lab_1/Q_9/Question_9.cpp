#include<bits/stdc++.h>
using namespace std;

#define rows 100
#define cols 100

void compute_matrix(int arr[rows][cols], int n, int m){
    // Complete this function
    int final_arr[n][m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int sum=0;
            int sum_1=0;
            int x=j+1;
            for(int k=i+1;k<n;k++){
                for(int l=0;l<m;l++){
                    sum+=arr[k][l];
                }
            }
            if(x==m){
                sum_1=0;
            }
            for(;x<m;x++){
                sum_1+=arr[i][x];
            }
            sum=sum+sum_1;
            final_arr[i][j]=sum;      
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<final_arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    // Feel free to create any helper function if needed.
    // Add your code here.
    int n,m;
    cin>>n>>m;
    int arr[rows][cols];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    compute_matrix(arr, n, m);
}