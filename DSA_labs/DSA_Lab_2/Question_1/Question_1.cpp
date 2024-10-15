#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int val;
    node* next;
    node(int v = 0, node* nxt = NULL) {
        val = v;
        next = nxt;
    }
};

class LinkedList {
public:
    node* head;
    LinkedList(node* h = NULL) {
        head = h;
    }
    
    void insert(int val) {
        node* x = new node(val, NULL);
        if (head == NULL) {
            head = x;
            return;
        }
        node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = x;
    }

    void printLinkedList() {
        if (head == NULL) {
            cout << "EMPTY\n";
            return;
        }
        node* curr = head;
        while (curr) {
            cout << curr->val << ' ';
            curr = curr->next;
        }
        cout << "NULL\n";
    }
};

node* concatenate(node* head1, node* head2) {
    if (head1 == NULL) return head2;
    node* curr = head1;
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = head2;
    return head1;
}

int main() {
    LinkedList L1, L2;

    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        L1.insert(val);
    }

    for (int i = 0; i < m; i++) {
        int val;
        cin >> val;
        L2.insert(val);
    }
    
    L1.head = concatenate(L1.head, L2.head);
    
    L1.printLinkedList();

    return 0;
}
