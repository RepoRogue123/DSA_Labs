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
        node* new_node = new node(val, NULL);
        if (head == NULL) {
            head = new_node;
            return;
        }
        node* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = new_node;
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

// Merging two sorted linked lists
node* sortedConcatenate(node* head1, node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    node* new_head = NULL; // Start of the new merged list
    node* curr = NULL;     // Current pointer for the new list

    if (head1->val <= head2->val) {
        new_head = head1;
        head1 = head1->next;
    } else {
        new_head = head2;
        head2 = head2->next;
    }

    curr = new_head;  // Set the current pointer

    // Continue merging the remaining nodes
    while (head1 && head2) {
        if (head1->val <= head2->val) {
            curr->next = head1;
            head1 = head1->next;
        } else {
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }

    // Attach the remaining nodes
    if (head1) {
        curr->next = head1;
    } else {
        curr->next = head2;
    }

    return new_head;
}

int main() {
    // Initialize two linked lists
    LinkedList L1;
    LinkedList L2;

    // Take input and make the linked lists
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

    // Call the sortedConcatenate function
    L1.head = sortedConcatenate(L1.head, L2.head);

    // Print the new sorted big linked list using printLinkedList
    L1.printLinkedList();

    return 0;
}
