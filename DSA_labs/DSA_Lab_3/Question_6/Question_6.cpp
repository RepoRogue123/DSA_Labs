#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Helper function to reverse first B nodes of the linked list
ListNode* reverseList(ListNode* head, int B) {
    ListNode* vprev = nullptr;
    ListNode* vcurr = head;
    ListNode* vnext = nullptr;
    int count = 0;
    
    while (vcurr != nullptr && count < B) {
        vnext = vcurr->next;
        vcurr->next = vprev;
        vprev = vcurr;
        vcurr = vnext;
        count++;
    }
 
    // head now points to the last node in the reversed segment, hence link it to the remaining list.
    if (head != nullptr) {
        head->next = vcurr;
    }

    return vprev; // vprev is the new head of the reversed segment
}

ListNode* reverseAlternateBNodes(ListNode* head, int B, int n) {
    if (B == 0 || B == 1 || B > n) {
        return head;  // If B is 0, 1, or greater than n, return the list unchanged
    }

    ListNode* vcurr = head;
    ListNode* vprev = nullptr;
    int x = n, y = 0;

    while (vcurr != nullptr && x >= B) {
        if (y % (2 * B) == 0) {
            ListNode* newh = reverseList(vcurr, B);

            if (vprev != nullptr) {
                vprev->next = newh; // Connect the new head of reversed segment to LL.
            } else {
                head = newh; // If it's the beginning of LL then head is the new head.
            }

            vprev = vcurr;
            vcurr = vcurr->next; // Moving current node (last node of reversed segment) to next.
        } else {
            int c = 0;
            while (vcurr != nullptr && c < B) { // Move vcurr forward by B nodes.
                vprev = vcurr;
                vcurr = vcurr->next;
                c++;
            }
        }
        y += B; x -= B;
    }
    return head;
}

void append(ListNode*& head, int new_data) {
    ListNode* new_node = new ListNode(new_data);
    if (head == nullptr) {
        head = new_node;
        return;
    }
    ListNode* last = head;
    while (last->next != nullptr) last = last->next;
    last->next = new_node;
}

void printList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = nullptr;
    int n, value, B;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> value;
        append(head, value);
    }
    cin >> B;
    head = reverseAlternateBNodes(head, B, n);

    printList(head);

    return 0;
}
