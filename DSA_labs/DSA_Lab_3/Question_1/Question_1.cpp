#include <bits/stdc++.h>

using namespace std;

#define MX_SIZE 1000

class Stack{
    int top = -1;
    int v[MX_SIZE];
    int max_size;

public:
    Stack(int size){
        max_size=size;      

    }
    
    /* Check if the stack is empty */
    int isEmpty(){
    // ADD YOUR CODE
        if(top==-1){
            return 1;
        }
        else{
            return 0;
        }
    
    
    }

    /* Check if the stack is full */
    int isFull(){
    //ADD YOUR CODE
        if(top==(max_size-1)){
            return 1;
        }
        else{
            return 0;
        }
    }

    /* Function to return the topmost element in the stack */
    int peek(){
    //ADD YOUR CODE
        return v[top];

    }

    /* Function to delete from the stack */
    int pop(){
    //ADD YOUR CODE
        int x;
        if(top==-1){
            perror("Stack is empty");
        }
        x=v[top--];
        return x;

    }

    /* Function to insert into the stack */
    int push(int data){
    //ADD YOUR CODE
        if(top==(max_size-1)){
            perror("Stack is full");
        }
        v[++top]=data;
    }

    void printWholeStack(){
        for(int i=top;i>=0;i--){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

};

/* Main function */
int main(){
   
   int n,x,i;
   cin>>n;
   Stack s(n);
   for(i=0;i<n;i++){
        cin>>x;
        s.push(x);
   }
   x=s.peek();
   cout<<x<<endl;
   s.printWholeStack();
   x=s.pop();
   cout<<x<<endl;
   cout<<s.isFull()<<endl;
   cout<<s.isEmpty()<<endl;
   return 0;
}