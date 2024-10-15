#include <iostream>
#include <algorithm>

using namespace std;

// Class for AVL Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new AVL tree node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to get the height of a node
int getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return max(getHeight(node->left), getHeight(node->right)) + 1;
}

// Function to create a new AVL tree node
Node* createNode(int val) {
    return new Node(val);
}

// Function to right rotate subtree rooted with y
Node* rightRotate(Node* y) {
    Node* new_Root = y->left;
    Node* subTree = new_Root->right;

    // Perform rotation
    new_Root->right = y;
    y->left = subTree;

    return new_Root; // New root after rotation
}

// Function to left rotate subtree rooted with x
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    return y; // New root after rotation
}

// Get Balance factor of node N
int getBalance(Node* current_Node) {
    if (current_Node == nullptr) {
        return 0;
    }
    return getHeight(current_Node->left) - getHeight(current_Node->right);
}

// Function to insert a node in AVL tree and balance the tree
Node* insert(Node* node, int data) {
    // Step 1: Perform the normal BST insertion
    if (node == nullptr) {
        return createNode(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        return node; // Duplicate data is not allowed in AVL
    }

    // Step 2: Get the balance factor
    int balance_factor = getBalance(node);

    // Step 3: Perform rotations if unbalanced

    // Left Left Case
    if (balance_factor > 1 && data < node->left->data) {
        return rightRotate(node);
    }

    // Right Right Case
    if (balance_factor < -1 && data > node->right->data) {
        return leftRotate(node);
    }

    // Left Right Case
    if (balance_factor > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance_factor < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node; // No rotation needed, return the unchanged node
}

// Function to check if a tree is a valid AVL tree
bool isValidAVL(Node* root) {
    if (root == nullptr) {
        return true;
    }

    int balance = getBalance(root);

    // Check the balance factor is between -1 and 1, and both subtrees are valid AVL trees
    return (balance >= -1 && balance <= 1) && isValidAVL(root->left) && isValidAVL(root->right);
}

// Function to perform preorder traversal of the AVL tree
void preorderTraversal(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

/*Logic-->>  The code inserts nodes into an AVL tree, ensuring that for every insertion, the balance factor (height difference between left and right subtrees) remains between -1 and 1.
If the tree becomes unbalanced after insertion, the code performs left or right rotations (or combinations) to restore balance in the AVL tree.
After insertion, the tree is checked to confirm if it remains a valid AVL tree by verifying that the balance factor of every node lies within the acceptable range.*/

int main() {
    int n;

    cin >> n;
    Node* root = nullptr;

    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        root = insert(root, data);
    }

    preorderTraversal(root);
    cout << endl;

    if (isValidAVL(root)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
