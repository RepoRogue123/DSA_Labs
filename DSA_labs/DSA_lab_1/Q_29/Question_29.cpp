#include<bits/stdc++.h>
using namespace std;

int main(){
    int size1;
    cin>>size1;
	vector<int> A(size1);
	for (int i = 0; i < size1; i++) cin>>A[i];
    
    vector<vector<int>> final_arr(size1,vector<int>(8,0));
    for(int i=0;i<size1;i++){
        int n=A[i];
        for(int j=0;j<8;j++){
            int rem=n%2;
            final_arr[i][8-j-1]=rem;
            n=n/2;       
        }
    }
    for(int i=0;i<size1;i++){
        for(int j=0;j<8;j++){
            cout<<final_arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}