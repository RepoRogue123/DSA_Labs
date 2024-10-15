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
    
    void insert_sorted(int val) {
        node* x = new node(val, NULL);
        
        if (head == NULL) {
            head = x;
            return;
        }

        node* curr = head;
        node* prev = NULL;

       
        while (curr != NULL && curr->val < val) {
            prev = curr;
            curr = curr->next;
        }

        if (prev == NULL) {
            x->next = head;
            head = x;
        } else { 
            x->next = prev->next;
            prev->next = x;
        }
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

int main() {
    LinkedList list;
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        list.insert_sorted(val);
    }
   
    list.printLinkedList();

    return 0;
}
