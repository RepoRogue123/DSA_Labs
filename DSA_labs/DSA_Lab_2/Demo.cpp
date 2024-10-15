#include<iostream>
#include<climits>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int v = 0, Node* p = nullptr, Node* n = nullptr) {
        data = v;
        prev = p;
        next = n;
    }
};

class DoubleLinkedList {
public:
    Node* head;
    DoubleLinkedList(Node* h = nullptr) {
        head = h;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->prev = curr;
    }

    void printLinkedList() {
        if (head == nullptr) {
            cout << "\n";
            return;
        }

        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << ' ';
            curr = curr->next;
        }
        cout << "\n";
    }
};

DoubleLinkedList concatenate(DoubleLinkedList& old, DoubleLinkedList& other) {
    if (old.head == nullptr) return other;
    if (other.head == nullptr) return old;

    Node* tail = old.head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    tail->next = other.head;
    other.head->prev = tail;

    return old;
}

DoubleLinkedList sortedConcatenate(DoubleLinkedList& l1, DoubleLinkedList& l2) {
    DoubleLinkedList result;
    Node* temp_1 = l1.head;
    Node* temp_2 = l2.head;

    while (temp_1 != nullptr && temp_2 != nullptr) {
        if (temp_1->data < temp_2->data) {
            result.insert(temp_1->data);
            temp_1 = temp_1->next;  // Corrected logic: should move to the next node of l1
        } else {
            result.insert(temp_2->data);
            temp_2 = temp_2->next;  // Corrected logic: should move to the next node of l2
        }
    }

    while (temp_1 != nullptr) {
        result.insert(temp_1->data);
        temp_1 = temp_1->next;  // Corrected logic: should move to the next node of l1
    }

    while (temp_2 != nullptr) {
        result.insert(temp_2->data);
        temp_2 = temp_2->next;  // Corrected logic: should move to the next node of l2
    }

    return result;
}

DoubleLinkedList insertSorted(DoubleLinkedList& l, int val) {
    Node* new_node = new Node(val);

    if (l.head == nullptr || l.head->data >= val) {
        new_node->next = l.head;
        if (l.head != nullptr) {
            l.head->prev = new_node;
        }
        l.head = new_node;
        return l;
    }

    Node* curr = l.head;
    while (curr->next != nullptr && curr->next->data < val) {
        curr = curr->next;
    }

    new_node->next = curr->next;
    if (curr->next != nullptr) {
        curr->next->prev = new_node;
    }
    curr->next = new_node;
    new_node->prev = curr;

    return l;
}

int secondHighest(DoubleLinkedList& l) {
    if (l.head == nullptr || l.head->next == nullptr) {
        return -1;
    }

    int Max_1 = INT_MIN, Max_2 = INT_MIN;

    Node* curr = l.head;
    while (curr != nullptr) {
        if (curr->data > Max_1) {
            Max_2 = Max_1;
            Max_1 = curr->data;
        } else if (curr->data > Max_2 && curr->data < Max_1) {
            Max_2 = curr->data;
        }
        curr = curr->next;
    }

    return Max_2 == INT_MIN ? -1 : Max_2;
}

void pairSumGreaterThanX(DoubleLinkedList& l, int x) {
    if (l.head == nullptr) {
        cout << -1 << endl;
        return;
    }

    int count = 0;
    Node* curr = l.head;

    while (curr != nullptr) {
        Node* front = curr->next;
        while (front != nullptr) {
            if (curr->data + front->data > x) {
                count++;
            }
            front = front->next;
        }
        curr = curr->next;
    }

    if (count == 0) {
        cout << -1 << endl;
    } else {
        cout << count << endl;
    }
}

int main() {
    int queryType;
    cin >> queryType;

    if (queryType == 1) {
        int n, m;
        cin >> n >> m;
        DoubleLinkedList list1;
        DoubleLinkedList list2;
        int x;
        while (n--) {
            cin >> x;
            list1.insert(x);
        }
        while (m--) {
            cin >> x;
            list2.insert(x);
        }
        concatenate(list1, list2).printLinkedList();
    } else if (queryType == 2) {
        int n, m;
        cin >> n >> m;
        DoubleLinkedList list1;
        DoubleLinkedList list2;
        int x;
        while (n--) {
            cin >> x;
            list1.insert(x);
        }
        while (m--) {
            cin >> x;
            list2.insert(x);
        }
        sortedConcatenate(list1, list2).printLinkedList();
    } else if (queryType == 3) {
        int n;
        cin >> n;
        int x;
        DoubleLinkedList list1;
        while (n--) {
            cin >> x;
            list1.insert(x);
        }
        int k;
        cin >> k;
        insertSorted(list1, k).printLinkedList();
    } else if (queryType == 4) {
        int n;
        cin >> n;
        DoubleLinkedList list1;
        int x;
        while (n--) {
            cin >> x;
            list1.insert(x);
        }
        cout << secondHighest(list1) << endl;
    } else if (queryType == 5) {
        int n, k;
        cin >> n >> k;
        DoubleLinkedList list1;
        int x;
        while (n--) {
            cin >> x;
            list1.insert(x);
        }
        pairSumGreaterThanX(list1, k);
    }

    return 0;
}
