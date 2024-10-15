#include <iostream>
using namespace std;

// Definition for a doubly linked list node.
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Function to insert a node at the end of the doubly linked list.
void insert(Node*& head, int data) {
    // Complete this function.
}

// Function to delete all occurrences of a key if it appears at least twice in the doubly linked list.
void deleteIfOccursTwice(Node*& head, int key) {
    // Complete this function.
}

// Function to print the doubly linked list.
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    int n; cin >> n;
    Node* head = nullptr;
    for(int i=0; i<n; i++){
        int t; cin >> t;
        insert(head, t);
    }

    int key; cin >> key;
    deleteIfOccursTwice(head, key);

    printList(head);

    return 0;
}