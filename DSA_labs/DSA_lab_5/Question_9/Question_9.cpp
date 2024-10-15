#include <iostream>
#include <vector>
using namespace std;

// Node class for the linked list
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// LinkedList class for the main linked list operations
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to append a new node at the end of the list
    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to calculate the greater array
    vector<int> calculateGreater(int size) {
        vector<int> greater(size, 0);
        Node* current = head;
        
        for (int i = 0; i < size; i++) {
            Node* temp = current->next;
            while (temp) {
                if (temp->data > current->data) {
                    greater[i] = temp->data;
                    break;
                }
                temp = temp->next;
            }
            current = current->next;
        }
        
        return greater;
    }

    // Function to print the linked list
    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int size;
    cin >> size;
    LinkedList list;

    // Input the elements of the linked list
    for (int i = 0; i < size; i++) {
        int data;
        cin >> data;
        list.append(data);
    }

    // Calculate the greater array
    vector<int> greater = list.calculateGreater(size);

    // Output the greater array
    for (int i = 0; i < size; i++) {
        cout << greater[i] << " ";
    }
    cout << endl;

    return 0;
}