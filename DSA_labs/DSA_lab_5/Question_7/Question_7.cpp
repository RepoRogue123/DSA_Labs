#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) : data(d), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    Node* returnHead() {
        return head;
    }

    void append(int new_data) {
        Node* new_node = new Node(new_data);
        if (head == nullptr) {
            head = new_node;
            return;
        }
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = new_node;
    }
};

/*The countConsecutive function finds consecutive elements in both a sorted ids list and a linked list, calculating the total number of consecutive groups using the sum of group sizes. It tracks and sums group sizes when consecutive matches are found.*/

// Function to count consecutive sets from sorted ids
int countConsecutive(Node* head, vector<int>& ids) {
    sort(ids.begin(), ids.end());  // Sort ids
    int consecutiveGroups = 0;
    int groupSize = 0;

    for (int i = 0; i < ids.size(); i++) {
        // Traverse the linked list using a for loop
        bool found = false;
        for (Node* current = head; current != nullptr; current = current->next) {
            if (current->data == ids[i]) {
                found = true;
                break;  // Found the corresponding node, exit the inner loop
            }
        }

        // If the current id is consecutive with the previous one in sorted ids
        if (i > 0 && ids[i] == ids[i - 1] + 1 && found) {
            groupSize++;
        } else {
            if (groupSize > 0) {
                consecutiveGroups += (groupSize * (groupSize + 1)) / 2;
            }
            groupSize = 0;  // Reset the group size
        }
    }

    if (groupSize > 0) {
        consecutiveGroups += (groupSize * (groupSize + 1)) / 2;
    }

return consecutiveGroups;
}

int main() {
    int n, m;
    cin >> n;

    LinkedList linkedList;

    for (int i = 0; i < n; i++) {
        linkedList.append(i);
    }

    cin >> m;
    vector<int> ids(m);
    for (int i = 0; i < m; i++) {
        cin >> ids[i];
    }

    // Calculate and print the count of consecutive elements
    cout << countConsecutive(linkedList.returnHead(), ids) << endl;

    return 0;
}