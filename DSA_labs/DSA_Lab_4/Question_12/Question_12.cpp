#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        if (val < node->data) {
            node->left = insert(node->left, val);
        } else if (val > node->data) {
            node->right = insert(node->right, val);
        }
        return node;
    }

    void inOrderHelper(Node* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        inOrderHelper(node->left, result);
        result.push_back(node->data);
        inOrderHelper(node->right, result);
    }

public:
    BST() : root(nullptr) {}

    void insert(int val) {
        root = insert(root, val);
    }

    vector<int> inOrderTraversal() {
        vector<int> result;
        inOrderHelper(root, result);
        return result;
    }
};

/*A Binary Search Tree (BST) is constructed by inserting nodes in the tree based on their value, where left child nodes hold values smaller than the parent and right child nodes hold values larger.
The tree is traversed in-order (left subtree, root, right subtree) to return a sorted sequence of node values.
The program takes user input for the number of nodes and their values, inserts them into the BST, and then prints the in-order traversal of the tree.*/

int main() {
    int n;
    cin >> n;
    
    BST bst;
    
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        bst.insert(val);
    }
    
    vector<int> inOrder = bst.inOrderTraversal();
    for (int val : inOrder) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}