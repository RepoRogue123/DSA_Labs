#include <iostream>
using namespace std;


int grid(int n ){
    
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }

    return grid(n-1)+ grid(n-4);
}

int main(){
    int n; 
    cin>>n;
    cout<<grid(n);
}