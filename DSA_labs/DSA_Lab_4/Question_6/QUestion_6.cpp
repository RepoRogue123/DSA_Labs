#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key;
    struct Node *left, *right;
    int height;
};

// Utility function to get maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to get height of the tree
int height(Node *N) {
    if (N == nullptr) {
        return 0;
    }
    return N->height;
}

// Helper function to create a new node with the given key
Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = nullptr;
    node->height = 1; // New node is initially added at leaf
    return node;
}

// Function to right rotate subtree rooted with y
Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Function to left rotate subtree rooted with x
Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(Node *N) {
    if (N == nullptr) {
        return 0;
    }
    return height(N->left) - height(N->right);
}

// Recursive function to insert a key into the subtree rooted with node
// and returns the new root of the subtree.
Node* insert(Node* node, int key) {
    // Perform the normal BST insertion
    if (node == nullptr) {
        return newNode(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        return node; // Duplicate keys not allowed
    }

    // Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor of this ancestor node to check if it became unbalanced
    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases:

    // Left Left Case
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Find the node with the smallest key value (inorder successor)
Node* minValueNode(Node* node) {
    Node* current = node;

    // Loop down to find the leftmost leaf
    while (current->left != nullptr) {
        current = current->left;
    }

    return current;
}

// Recursive function to delete a node with given key from subtree with given root
Node* deleteNode(Node* root, int key) {
    // Perform the normal BST deletion
    if (root == nullptr) {
        return root;
    }

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }

    // If key is same as root's key, then this is the node to be deleted
    else {
        // Node with only one child or no child
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node *temp = root->left ? root->left : root->right;

            // No child case
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else { // One child case
                *root = *temp; // Copy the contents of the non-empty child
            }

            delete temp;
        } else {
            // Node with two children: Get the inorder successor (smallest
            // in the right subtree)
            Node* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node then return
    if (root == nullptr) {
        return root;
    }

    // Update height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Get the balance factor of this node
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases:

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// A utility function to do preorder traversal of the tree
void preOrder(Node *root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
/*The AVL tree maintains balance by updating the height of each node after insertion or deletion and calculates the balance factor to ensure the tree remains balanced.
If the balance factor becomes unbalanced (greater than 1 or less than -1), appropriate rotations (left, right, or combinations) are performed to restore balance.
The insert and delete operations recursively adjust the tree while ensuring that all nodes maintain their height and balance properties.*/

int main() {
    Node *root = nullptr;
    int n, key;

    // Input the number of nodes
    cin >> n;

    // Input the nodes and insert into AVL tree
    for (int i = 0; i < n; i++) {
        cin >> key;
        root = insert(root, key);
    }

    // Input the key to delete
    cin >> key;

    // Delete the node from the tree
    root = deleteNode(root, key);

    // Preorder traversal of the tree after deletion
    preOrder(root);

    return 0;
}
