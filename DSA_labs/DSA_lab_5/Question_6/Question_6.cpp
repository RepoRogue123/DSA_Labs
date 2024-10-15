#include<bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;

    // Constructor to create a new node
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to delete duplicate elements from a sorted singly-linked list
ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* current = head;

    while (current && current->next) {
        if (current->val == current->next->val) {
            // Skip the next node because it is a duplicate
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;  // Move to the next node if no duplicate
        }
    }

    return head;
}

// Function to print the elements of a singly-linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

// Function to create a singly-linked list from a string of numbers
ListNode* createList(const string& numbers) {
    ListNode* head = nullptr;
    ListNode* current = nullptr;

    stringstream ss(numbers);
    int num;

    while (ss >> num) {
        ListNode* newNode = new ListNode(num);
        if (!head) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    return head;
}

// Function to free the memory allocated for a singly-linked list
void freeList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    string input;
    getline(cin, input);  // Input the numbers as a space-separated string

    // Create a linked list from the string of numbers
    ListNode* head = createList(input);

    // Print the original linked list
 
    printList(head);

    // Delete duplicates from the sorted list
    head = deleteDuplicates(head);

    // Print the final linked list without duplicates
   
    printList(head);

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}
