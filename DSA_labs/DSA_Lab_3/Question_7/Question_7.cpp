#include <iostream>
using namespace std;

// Node class representing each element in the stack
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize node
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Stack class to handle stack operations
class Stack {
private:
    Node* topNode; // Pointer to the top node in the stack
    int size;

public:
    // Constructor to initialize stack
    Stack() {
        topNode = nullptr;
        size=0;
    }

    // Function to check if stack is empty
    bool isEmpty() {
        return topNode == nullptr;
    }

    // Function to push an element onto the stack
    void push(int x) {
        if(topNode==nullptr){
            Node*temp=new Node(x);
            topNode=temp;
        }
        Node*temp=new Node(x);
        temp->next=topNode;
        topNode=temp;
        size=size+1;
    }

    // Function to pop the top element from the stack
    void pop() {

        if(topNode==nullptr){
            cout<< "Stack is empty\n";
        }
        Node*temp=topNode;
        topNode=topNode->next;
        delete temp;
        size--;
    }

    // Function to get the top element of the stack
    int top() {
        return topNode->data;
    }

    // Function to print all elements of the stack
    void printStack() {
        Node*curr=topNode;
        while(curr->next){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
    }
};

// Main function to process queries
int main() {
    Stack stack;
    int q;
    cin >> q; // Number of queries

    for(int i=0;i<q;i++){
        int val;
        cin>>val;
        if(val==1){
            int x;
            cin>>x;
            stack.push(x);
        }

        else if(val==2){
            stack.pop();
        }

        else if(val==3){
            cout<<stack.top()<<endl;
        }
        else if(val==4){
            stack.printStack();
            cout<<endl;
        }
    }
    
    
    return 0;
}