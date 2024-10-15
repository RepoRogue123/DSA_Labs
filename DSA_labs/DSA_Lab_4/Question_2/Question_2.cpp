#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    TreeNode* root = nullptr;

    // Function to create a binary tree from the array using level-order traversal
    void make_binary_tree_from_array(int* arr, int size) {
        if (size == 0 || arr[0] == -1) {
            this->root = nullptr;  // Handle empty or invalid root case
            return;
        }

        root = new TreeNode(arr[0]);
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < size) {
            TreeNode* current = q.front();
            q.pop();

            // Create the left child
            if (i < size && arr[i] != -1) {
                current->left = new TreeNode(arr[i]);#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    TreeNode* root = nullptr;

    // Function to create a binary tree from the array using level-order traversal
    void make_binary_tree_from_array(int* arr, int size) {
        if (size == 0 || arr[0] == -1) {
            this->root = nullptr;  // Handle empty or invalid root case
            return;
        }

        root = new TreeNode(arr[0]);
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < size) {
            TreeNode* current = q.front();
            q.pop();

            // Create the left child
            if (i < size && arr[i] != -1) {
                current->left = new TreeNode(arr[i]);
                q.push(current->left);
            }
            i++;

            // Create the right child
            if (i < size && arr[i] != -1) {
                current->right = new TreeNode(arr[i]);
                q.push(current->right);
            }
            i++;
        }
    }

    // Function to calculate the height of the tree and check if it's balanced
    int Max_height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int lh = Max_height(root->left);
        int rh = Max_height(root->right);

        if (lh == -1 || rh == -1 || abs(lh - rh) > 1) {
            return -1;  // Return -1 if the subtree is unbalanced
        }

        return 1 + max(lh, rh);
    }

    // Function to check if the tree is balanced
    bool isBalanced(TreeNode* root) {
        return Max_height(root) != -1;  // Return true if the tree is balanced
    }
};

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << "true" << endl;  // Empty tree is balanced
        return 0;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    BinaryTree tree;
    tree.make_binary_tree_from_array(arr.data(), n);

    cout << (tree.isBalanced(tree.root) ? "true" : "false") << endl;

    return 0;
}

                q.push(current->left);
            }
            i++;

            // Create the right child
            if (i < size && arr[i] != -1) {
                current->right = new TreeNode(arr[i]);
                q.push(current->right);
            }
            i++;
        }
    }

    // Function to calculate the height of the tree and check if it's balanced
    int Max_height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int lh = Max_height(root->left);
        int rh = Max_height(root->right);

        if (lh == -1 || rh == -1 || abs(lh - rh) > 1) {
            return -1;  // Return -1 if the subtree is unbalanced
        }

        return 1 + max(lh, rh);
    }

    // Function to check if the tree is balanced
    bool isBalanced(TreeNode* root) {
        return Max_height(root) != -1;  // Return true if the tree is balanced
    }
};

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << "true" << endl;  // Empty tree is balanced
        return 0;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    BinaryTree tree;
    tree.make_binary_tree_from_array(arr.data(), n);

    cout << (tree.isBalanced(tree.root) ? "true" : "false") << endl;

    return 0;
}
