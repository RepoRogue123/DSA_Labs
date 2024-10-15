#include <iostream>
using namespace std;

class LRUCache {
public:
    class Node {
    public:
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(int x = 0, int y = 0): key(x), value(y), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int maxsize;
    int size;

    LRUCache(int x): head(nullptr), tail(nullptr), maxsize(x), size(0) {}

    void enqueue(int x, int y) {
        Node* newNode = new Node(x, y);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    bool isEmpty() {
        return (head == nullptr);
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            exit(EXIT_FAILURE);
        }

        Node* popped = tail;
        int val = popped->key;

        if (head == tail) { // Only one node in the list
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete popped;
        size--;
        return val;
    }

    Node* find(int n) {
        if (head == nullptr) return nullptr;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->key == n) return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    void remove(Node* n) {
        if (!n) return;

        if (n == head) {
            head = head->next;
            if (head) head->prev = nullptr;
        } else if (n == tail) {
            tail = tail->prev;
            if (tail) tail->next = nullptr;
        } else {
            n->prev->next = n->next;
            n->next->prev = n->prev;
        }

        delete n;
        size--;
    }

    int get(int x) {
        Node* ans = find(x);
        if (ans) {
            int ans_key = ans->key;
            int ans_val = ans->value;
            remove(ans);
            enqueue(ans_key, ans_val);
            return ans_val;
        } else {
            return -1;
        }
    }

    void put(int x, int y) {
        Node* ans = find(x);
        if (ans == nullptr) {
            if (size == maxsize) {
                dequeue();
            }
            enqueue(x, y);
        } else {
            remove(ans);
            enqueue(x, y);
        }
    }
};

int main() {
    int n, numOps, op, num1, num2;
    cin >> n >> numOps;
    LRUCache cache(n);

    while (numOps--) {
        cin >> op;
        if (op == 1) {
            cin >> num1;
            cout << cache.get(num1) << endl;
        } else {
            cin >> num1 >> num2;
            cache.put(num1, num2);
        }
    }
    return 0;
}
