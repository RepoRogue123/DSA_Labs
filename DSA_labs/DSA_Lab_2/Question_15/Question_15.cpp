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
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to delete all occurrences of a key if it appears at least twice in the doubly linked list.
void deleteIfOccursTwice(Node*& head, int key) {
    if (!head) return;

    // Count occurrences of the key
    int count = 0;
    Node* temp = head;
    while (temp) {
        if (temp->data == key) count++;
        temp = temp->next;
    }

    // If key appears less than twice, return
    if (count < 2) return;

    // Delete all occurrences of the key
    temp = head;
    while (temp) {
        if (temp->data == key) {
            if (temp == head) {
                head = temp->next;
                if (head) head->prev = nullptr;
                delete temp;
                temp = head;
            } else {
                Node* x = temp;
                temp->prev->next = temp->next;
                if (temp->next) temp->next->prev = temp->prev;
                temp = temp->next;
                delete x;
            }
        } else {
            temp = temp->next;
        }
    }
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