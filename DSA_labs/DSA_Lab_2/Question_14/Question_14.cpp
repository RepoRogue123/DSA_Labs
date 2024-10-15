#include <iostream>
using namespace std;

struct ListNode {
    int value;
    ListNode *next;
    ListNode(int val) : value(val), next(nullptr) {}
};

void printList(ListNode *head) {
    ListNode *temp = head;
    while (temp) {
        cout << temp->value;
        if (temp->next) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

ListNode* reverseSegment(ListNode *head, int left, int right) {
    ListNode* curr = head;
    ListNode* prev = nullptr;

    // Move curr to the left position and prev to the node before left
    for (int i = 1; i < left; i++) {
        prev = curr;
        curr = curr->next;
    }

    ListNode* start = curr;
    ListNode* end = nullptr;

    // Reverse the sublist from left to right
    for (int i = left; i <= right; i++) {
        ListNode* next = curr->next;
        curr->next = end;
        end = curr;
        curr = next;
    }

    // Connect the reversed sublist back to the list
    if (prev != nullptr) {
        prev->next = end;
    } else {
        head = end;
    }
    start->next = curr;

    return head;
}

int main() {
    int value;
    ListNode *head = nullptr, *tail = nullptr;
    while (cin >> value) {
        if (value == -1) break;
        ListNode *newNode = new ListNode(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int left, right;
    cin >> left >> right;

    cout << "Original list: ";
    printList(head);

    head = reverseSegment(head, left, right);

    cout << "Modified list: ";
    printList(head);

    ListNode *temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
