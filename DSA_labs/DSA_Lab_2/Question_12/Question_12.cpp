#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode* sublist;

    ListNode(int x) : val(x), next(nullptr), sublist(nullptr) {}
};


ListNode* combineListsLevelByLevel(vector<ListNode*>& subLists) {
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;

    // Initialize a queue for level-wise traversal
    queue<ListNode*> q;

    // Add all the head nodes of sublists to the queue
    for (ListNode* head : subLists) {
        if (head) q.push(head);
    }

    // Perform level-order traversal
    while (!q.empty()) {
        ListNode* node = q.front();
        q.pop();

        // Append the current node to the combined list
        tail->next = new ListNode(node->val);
        tail = tail->next;

         // If this node has a sublist, add it to the queue
        if (node->next) {
            q.push(node->next);
        }

        // If this node has a next node, add it to the queue
        if (node->sublist) {
            q.push(node->sublist);
        }
    }


    return dummy->next;
}


void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;

    cin >> n;

    vector<ListNode*> subLists(n, nullptr);

    for (int i = 0; i < n; ++i) {
        int size;
        cin >> size;

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        for (int j = 0; j < size; ++j) {
            int val;
          
            cin >> val;
            current->next = new ListNode(val);
            current = current->next;
        }

        subLists[i] = dummy->next;
    }

    ListNode* combinedHead = combineListsLevelByLevel(subLists);

   
    printList(combinedHead);

    return 0;
}