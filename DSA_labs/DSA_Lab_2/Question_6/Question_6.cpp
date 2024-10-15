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
        node* temp = new node(val, NULL);
        if (head == NULL) {
            head = temp;
            return;
        }
        node* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = temp;
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

void insertion_operation(LinkedList &l, int elem) {
    node* temp = new node(elem, NULL);
    if (l.head == NULL) {
        l.head = temp;
        return;
    }
    node* curr = l.head;
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = temp;
}

node* deletion_operation(LinkedList &l) {
    if (l.head == NULL) {
        return NULL;
    }
    node* temp = l.head;
    l.head = l.head->next;
    delete temp;
    return l.head;
}

int main() {
    LinkedList L1;

    int n;
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        L1.insert(arr[i]);
    }

    int m;
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a>>b;
        if (a == 1) {
            insertion_operation(L1, b);
        } else if (a == 2 && b==-1) {
            L1.head = deletion_operation(L1);
        }
        L1.printLinkedList();
    }

   

    return 0;
}
