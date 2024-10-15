#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize a node
    TreeNode(int val=0) : value(val), left(nullptr), right(nullptr) {}

    // Destructor to clean up dynamically allocated nodes
    ~TreeNode() {
        delete left;
        delete right;
    }

    // Helper function to create a node
    TreeNode* createNode(int value) {
        if (value == -1) return nullptr; // -1 is used to denote null nodes
        return new TreeNode(value);
    }

    // Insert nodes into the tree in level-order fashion
    TreeNode* insertLevelOrder(vector<int>& arr, TreeNode* root, int i, int n) {
        if (i < n && arr[i] != -1) {
            TreeNode* newnode = createNode(arr[i]);
            root = newnode;
            root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
            root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
        }
        return root;
    }

    // Invert the binary tree iteratively
    TreeNode* invertTreeIterative(TreeNode* root) {
        if (root == nullptr) return nullptr;

        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode* current = s.top();
            s.pop();
            
            // Swap left and right children
            swap(current->left, current->right);

            if (current->right != nullptr) {
                s.push(current->right);
            }
            if (current->left != nullptr) {
                s.push(current->left);
            }
        }
        return root;
    }

    // Print the tree in pre-order traversal (print -1 for null nodes)
    void printPreorder(TreeNode* node) {
        if (node == nullptr) {
            cout << "-1 "; // Print -1 for null nodes
            return;
        }
        cout << node->value << " "; // Print the value of the node
        printPreorder(node->left);  // Recursively print the left subtree
        printPreorder(node->right); // Recursively print the right subtree
    }
};

int main() {
    // Read the number of elements in the tree
    int n;
    cin >> n;

    // Read the tree elements
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Create the binary tree
    TreeNode* root = nullptr;
    TreeNode tree;
    root = tree.insertLevelOrder(arr, root, 0, n);

    // Print the original tree in pre-order with -1 for null nodes
    tree.printPreorder(root);
    cout << endl;

    // Invert the tree iteratively and print the result
    root = tree.invertTreeIterative(root);
    tree.printPreorder(root);
    cout << endl;

    // Clean up memory
    delete root;

    return 0;
}
