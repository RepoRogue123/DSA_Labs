#include<bits/stdc++.h>
using namespace std;

class BinaryTree{
    public:
    class Node {
        public:
        int data;
        Node* left;
        Node* right;
        
        Node(): data(0), left(nullptr), right(nullptr) {}
        
        Node(int val): data(val), left(nullptr), right(nullptr) {}
    };
    
    Node* root = nullptr;
    
    void make_BT_from_array(int *arr, int size)
    {
        this->root = BT_from_level_order_array(arr, 0, size);
    }
    
    Node* BT_from_level_order_array(int *arr, int index, int size){

        if (index < size && arr[index] != -1) {
            Node* newnode = new Node(arr[index]);
            newnode->left = BT_from_level_order_array(arr, 2 * index + 1, size);
            newnode->right = BT_from_level_order_array(arr, 2 * index + 2, size);
            return newnode;
        }
        return nullptr;
    }
    
    void alternatingLevelOrderTraversal(Node*root) {
        if(root == NULL) {
            return;
        }

        queue<Node*>q;
        q.push(root);

        int level = 1;  // Start at level 1

        while(!q.empty()){
            int size_1 = q.size();
            vector<int> arr;

            for(int i = 0; i < size_1; i++){
                Node* node = q.front();
                q.pop();

                arr.push_back(node->data);  // Store node data in arr

                // Always insert left to right in queue
                if(node->left != nullptr) {
                    q.push(node->left);
                }
                if(node->right != nullptr) {
                    q.push(node->right);
                }
            }

            // If level is even, reverse the current level's output
            if(level % 2 == 0) {
                reverse(arr.begin(), arr.end());
            }

            // Print the current level's result
            for(int i = 0; i < arr.size(); i++){
                cout << arr[i] <<" ";
            }
            cout<<"| ";

            level++;  // Move to next level
        }
    }
    
};

int main() {
    BinaryTree tree;
    int n, data;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> data;
        arr[i] = data;
    }
    
    tree.make_BT_from_array(arr, n);
    tree.alternatingLevelOrderTraversal(tree.root);  // Pass root to traversal function
    delete[] arr;  // Free allocated memory
    return 0;
}
