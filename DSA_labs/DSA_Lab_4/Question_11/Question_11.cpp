#include <iostream>
using namespace std;

// Class definition for a Node in the BST
class Node {
public:
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize a node
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Class definition for the Binary Search Tree
class BST {
private:
    Node* root;
    // Helper function to insert a node in the BST
    Node* insert(Node* node, int data) {
        if (node == nullptr) {
            return new Node(data);
        }
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else if (data > node->data) {
            node->right = insert(node->right, data);
        }
        return node;
    }

    // Helper function to find the minimum value node in a subtree
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Helper function to find a node with a given value
    Node* findNode(Node* node, int data) {
        if (node == nullptr || node->data == data) {
            return node;
        }
        if (data < node->data) {
            return findNode(node->left, data);
        }
        return findNode(node->right, data);
    }

public:
    // Constructor to initialize the root of the BST
    BST() {
        root = nullptr;
    }

    // Public function to insert a node in the BST
    void insert(int data) {
        root = insert(root, data);
    }

    // Function to find the in-order successor of a given node
    int findInOrderSuccessor(int data) {
        Node* current = findNode(root, data);
        if (current == nullptr) {
            return -1;
        }

        // Case 1: Node has right subtree
        if (current->right != nullptr) {
            return findMin(current->right)->data;
        }

        // Case 2: No right subtree
        Node* successor = nullptr;
        Node* ancestor = root;
        while (ancestor != current) {
            if (current->data < ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
        }

        return (successor == nullptr) ? -1 : successor->data;
    }
};
/*Logic -->> Insert nodes into the BST by comparing values and recursively placing them in the correct position (left if smaller, right if larger).
Find a node's in-order successor by first checking if it has a right subtree (if so, the successor is the minimum value in that subtree).
If no right subtree exists, traverse from the root to find the deepest ancestor for which the given node would be in its left subtree - this ancestor is the successor.*/


// Main function to execute the program
int main() {
    int n, target;
    cin >> n;
    BST tree;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        tree.insert(val);
    }
    cin >> target;
    int successor = tree.findInOrderSuccessor(target);
    if (successor != -1) {
        cout << successor << endl;
    } else {
        cout << "-1" << endl;
    }
    return 0;
}