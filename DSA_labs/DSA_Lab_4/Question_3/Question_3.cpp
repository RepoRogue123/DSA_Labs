#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

// Function to create a new tree node
TreeNode* newNode(int value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// Function to build a binary tree from an array
TreeNode* buildTreeFromArray(int arr[], int index, int size) {
    if (index < size && arr[index] != -1) {
        TreeNode* newnode = newNode(arr[index]);
        newnode->left = buildTreeFromArray(arr, 2 * index + 1, size); 
        newnode->right = buildTreeFromArray(arr, 2 * index + 2, size);
        return newnode;
    }
    return nullptr;
}

/*Logic-->> The basic logic to find whether two trees are identical or not is that both must give be equal in terms of every kind of traversal(may it be preorder,postporder or inorder). */

bool areIdentical(TreeNode* p, TreeNode* q) {
    if (p == nullptr || q == nullptr) {
        return (p == q);
    }
    return (p->data == q->data) && areIdentical(p->left, q->left) && areIdentical(p->right, q->right);
}

// Function to build a binary tree from a string in the array format
TreeNode* buildTreeFromArrayString(const string& str) {
    // Convert the input string to a vector of integers
    vector<int> arr;
    stringstream ss(str);
    string temp;

    while (ss >> temp) {
        if (temp == "-1") {
            arr.push_back(-1);  // whenever the temp is queal to '-1', we interpret it as a null node and hence push -1 into the array
        } else {
            arr.push_back(stoi(temp)); // Here I have used stoi function, this function converts the temp into an integer
        }
    }

    // Create the binary tree from the array
    if (arr.empty()) return nullptr;
    return buildTreeFromArray(arr.data(), 0, arr.size());
}

int main() {
    // Get the array input for the first tree from the user
    string input1;
    getline(cin, input1);

    // Create binary tree from the first input
    TreeNode* root1 = buildTreeFromArrayString(input1);

    // Get the array input for the second tree from the user
    string input2;
    getline(cin, input2);

    // Create binary tree from the second input
    TreeNode* root2 = buildTreeFromArrayString(input2);

    // Check if the trees are identical
    if (areIdentical(root1, root2)) {
        cout << "1"; // 1 for identical
    } else {
        cout << "0"; // 0 for not identical
    }

    // No need to manually free memory since the program will terminate afterward

    return 0;
}
