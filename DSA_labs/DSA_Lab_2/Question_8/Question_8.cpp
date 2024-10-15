#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int val;
    node* next;
    node(int data = 0, node* nxt = NULL) {
        val = data;
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

    int Distinct_elements(node* h, int n) {
        node* curr = h;
        int distinctCount = 0;


        while (curr) {
            node* front = h;
            int isDuplicate = 0;
            while (front != curr) {
                if (front->val == curr->val) {
                    isDuplicate = 1;
                    break;
                }
                front = front->next;
            }
            if (!isDuplicate) {
                distinctCount++;
            }
            curr = curr->next;
        }
        return distinctCount; // Return the number of distinct elements
    }

    node* second_highest(int n) {
        if (Distinct_elements(head, n) < 2 || head == NULL) {
            return NULL;
        }

        // Manual sorting in descending order
        node* curr = head;
        int arr[100];
        int i = 0;
        while (curr) {
            arr[i] = curr->val;
            i++;
            curr = curr->next;
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] < arr[j]) { 
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }

        // Identify the second distinct highest element
        int highest = arr[0];
        for (int j = 1; j < n; j++) {
            if (arr[j] < highest) {
                return new node(arr[j]);
            }
        }
        return new node(arr[n-2],NULL);
    }
};

int main() {
    LinkedList list;
    int n;
    cin >> n;

    // Take the input for the linked list
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        list.insert(val);
    }

    node* result = list.second_highest(n);

    if (result) {
        cout << result->val << endl;
    } else {
        cout << "NULL" << endl;
    }

    return 0;
}
