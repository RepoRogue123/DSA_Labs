#include <iostream>
#include <string>
using namespace std;

class LinkedList {
public:
    class Node {
    public:
        string data;  // Use string to handle 'x1', 'o1', etc.
        Node *next;
        Node(string value) {
            this->data = value;
            this->next = nullptr;
        }
    };
    
    int size;
    Node *root;
    
    LinkedList() {
        this->size = 0;
        this->root = nullptr;
    }
    
    ~LinkedList() {
        if (root == nullptr) return;
        Node* current = root->next;
        while (current != root) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        delete root;
    }
    
    void enqueue(string value) {
        Node* newNode = new Node(value);
        if(root == nullptr) {
            root = newNode;
            root->next = root;
        }
        else {
            newNode->next = root->next;
            root->next = newNode;
            root = newNode;
        }
        this->size += 1;
    }
    
    void dequeue() {
        if (root == nullptr) return;  
        
        if(root->next == root) {  
            delete root;
            root = nullptr;
        }
        else {  
            Node *deleted = root->next;
            root->next = deleted->next;
            delete deleted;
        }
        this->size--;
    }
/*The logic follows a simple principle: for a given set of n numbers, there should always be n-1 operations. This means that, in the postfix expression, there will always be a difference of 1 between the number of numbers (x) and the number of operations (o).

At each step, we count the numbers (x) and operations (o). If the difference between x and o is not equal to 1 when we add an operation (o), it indicates that an operation should occur. Otherwise, we increase x, which means creating a new number, followed by a corresponding operation. Once the number of operations exceeds the number of numbers in the expression, we stop the loop, and the count is finalized.*/
    void solution() {
    int countNum = 0, countOp = 0;
    
    /*countNum -->>  This variable tracks the number of numbers (or "x" symbols) that have been processed and printed in the postfix expression so far.*/
    
    /*countOp --->> This variable tracks the number of operators (or "o" symbols) that have been processed and printed in the postfix expression.*/
    
    
    Node* current = root->next;
    
    for (int i = 1; i <= size; i++) {
        if (current->data == "x") {
            cout << "x" << ++countNum << " ";
            if (countOp >= size - 1) {
                break;  // Since for n numbers, there should be n-1 operations
            }
            if (countNum - countOp != 1) {
                cout << "o" << ++countOp << " ";
            } else {
                cout << "x" << ++countNum << " ";
            }
            current = current->next;
        } else {
            cout << "o" << ++countOp << " ";
            if (countOp >= size - 1) {
                break;
            }
            if (countNum - countOp != 1) {
                cout << "o" << ++countOp << " ";
            } else {
                cout << "x" << ++countNum << " ";
            }
            current = current->next;
        }
    }
}

};

int main() {
    int size;
    cin >> size;

    LinkedList L;
    for(int i = 0; i < size; i++) {
        char x; 
        cin >> x;
        string s(1,x);
        L.enqueue(s);
    }
    L.solution();
    
    return 0;
}