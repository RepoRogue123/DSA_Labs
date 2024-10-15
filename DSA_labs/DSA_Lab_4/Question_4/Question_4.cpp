#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const std::vector<int>& nodes) {
    if (nodes.empty()) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(nodes[0]);
    std::queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

bool isPathSum(TreeNode* root, int targetSum) {
    if (root == NULL) {
        return false;
    }
    
    // If it's a leaf node and its value equals the remaining sum
    if (root->left == NULL && root->right == NULL && root->value == targetSum) {
        return true;
    }
    
    /*Logic-->> If there exists a path then at the leafnode the value of the node as well as the modified target must be the same. We modify the targetSum at every recurssion as we traverse through each node.As soon as it finds a path, it immediately returns true */
    return isPathSum(root->left, targetSum - root->value) ||
           isPathSum(root->right, targetSum - root->value);
}

int main() {
    int n, targetSum;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cin >> targetSum;

    TreeNode* root = buildTree(arr);

    bool result = isPathSum(root, targetSum);
    cout << (result ? "true" : "false") << "\n";

    // Note: This delete only frees the root node, not the entire tree
    delete root;

    return 0;
}