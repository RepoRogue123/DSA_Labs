#include <iostream>
using namespace std;

class Node {
public:
    int id;
    Node* next;
    Node(int id) : id(id), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    CircularLinkedList(int n) {
        head = nullptr;
        tail = nullptr;
        size = n;
        for (int i = 1; i <= n; i++) {
            insert(i);
        }
        // Making the linked list circular
        tail->next = head;
    }

    void insert(int id) {
        Node* newNode = new Node(id);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void setStart(int n) {
        n = (n - 1) % size;
        for (int i = 0; i < n; i++) {
            head = head->next;
        }
    }

    int findWinner(int p) {
        Node* current = head;
        while (size > 1) {
            for (int i = 1; i < p; i++) {
                current = current->next;
            }
            // Remove the next node
            Node* temp = current->next;
            current->next = temp->next;
            if (temp == head) {
                head = head->next;
            }
            if (temp == tail) {
                tail = current;
            }
            delete temp;
            size--;
        }
        int winner = head->id;
        delete head;
        head = tail = nullptr;
        return winner;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int x, n, p;
        cin >> x >> n >> p;
        CircularLinkedList game(x);
        game.setStart(n);
        cout << game.findWinner(p) << endl;
    }
    return 0;
}