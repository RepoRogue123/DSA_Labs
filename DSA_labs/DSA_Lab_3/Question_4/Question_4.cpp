#include<bits/stdc++.h>
using namespace std;

// Function to reverse a string in place
class Stack{
    int top;
    int size;
    vector<char>v;

public:
    Stack(int max_size){
        size=max_size;
        top=-1;
        v=vector<char>(size,' ');
    }

    void push(char data){
        if(top==(size-1)){
            cout<<"Stack is full";
        }
        v[++top]=data;
    }

    char pop(){
        if(top==-1){
            cout<<"Stack is empty";
        }
        return v[top--];
    }

    void Print_reversed_array(){
        for(int i=top;i>=0;i--){
            cout<<v[i];
        }
    }
};

int main(){
    string input;
    cin>>input;
    int size=input.size();

    Stack S1(size);
    for(int i=0;i<size;i++){
        S1.push(input[i]);
    }

    S1.Print_reversed_array();

}