#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;
    // Constructor to initialize a node
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
    // Destructor to clean up dynamically allocated nodes
    ~TreeNode() {
        delete left;
        delete right;
    }
};

// Function to create a new node
TreeNode* createNode(int value) {
    if (value == -1) return nullptr; // -1 is used to denote null nodes
    return new TreeNode(value);
}

// Function to insert nodes in level order
TreeNode* insertLevelOrder(vector<int>& arr, TreeNode* root, int i, int n) {
    if (i < n) {
        TreeNode* temp = createNode(arr[i]);
        root = temp;
        
        if (root) {
            // Insert left child
            root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
            // Insert right child
            root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
        }
    }
    return root;
}

// Function to invert the binary tree
/*The first line stores the left child of the current node in a temporary variable.
The second line recursively inverts the right subtree and assigns it to the left child of the current node.
The third line recursively inverts the original left subtree (stored in temp) and assigns it to the right child of the current node.*/

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    
    // Swap the left and right children
    TreeNode* temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);
    
    return root;
}

// Function to print the tree in pre-order
void printPreorder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    
    cout << node->value << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {
    // DO NOT MODIFY THIS
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    TreeNode* root = nullptr;
    root = insertLevelOrder(arr, root, 0, n);
    // Print the original tree in pre-order
    printPreorder(root);
    cout << endl;
    // Invert the tree and print again
    root = invertTree(root);
    printPreorder(root);
    cout << endl;
    // Clean up memory
    delete root;
    return 0;
}