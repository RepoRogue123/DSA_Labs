#include <iostream>

class BinaryTree {
public:
    class Node {
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };
    
    Node* root = nullptr;
    
    void make_BT_from_array(int *arr, int size) {
        this->root = BT_from_level_order_array(arr, 0, size);
    }
    /*he BT_from_level_order_array function builds a binary tree from an array that represents the tree level by level. It checks if the current position in the array is valid and if the value is not -1 (which means there's a node). If so, it creates a new node with that value. Then, it recursively creates the left and right child nodes using the positions 2 * index + 1 for the left child and 2 * index + 2 for the right child. If the position is invalid or the value is -1, it returns nullptr, meaning there's no node at that position.*/
    Node* BT_from_level_order_array(int *arr, int index, int size) {
        if (index < size && arr[index] != -1) {
            Node* newnode = new Node(arr[index]);
            newnode->left = BT_from_level_order_array(arr, 2 * index + 1, size);
            newnode->right = BT_from_level_order_array(arr, 2 * index + 2, size);
            return newnode;
        }
        return nullptr;
    }
    /*The dfs function explores each path from the root of the binary tree to its leaves, calculating an alternating sum of node values along the way. Starting from a given node, it updates the sum by adding or subtracting the node's value based on its level (even levels add, odd levels subtract). It then checks if this alternating sum matches any of the target values and counts matches. Finally, the function recursively checks both the left and right child nodes to continue the traversal and sum calculation.*/
    
    void dfs(Node* node, int current_sum, int level, int *targets, int *target_counts, int k) {
        if (!node) return;
        
        // Calculate alternating sum
        if (level % 2 == 0) {
            current_sum += node->data;
        } else {
            current_sum -= node->data;
        }
        
        // Check if this sum matches any of the targets
        for (int i = 0; i < k; ++i) {
            if (current_sum == targets[i]) {
                target_counts[i]++;
            }
        }
        
        // Traverse left and right subtrees
        dfs(node->left, current_sum, level + 1, targets, target_counts, k);
        dfs(node->right, current_sum, level + 1, targets, target_counts, k);
    }
    /*The alternating_path_sum function calculates how many paths in the binary tree match each target sum. It starts by initializing an array to keep track of counts for each target. It then uses the dfs function to explore all paths from the root and calculate their alternating sums. After collecting the counts, the function prints the results for each target in the order they were given and then cleans up the memory used for counting.*/
    
    void alternating_path_sum(int *targets, int k) {
        int *target_counts = new int[k]();
        
        dfs(root, 0, 0, targets, target_counts, k);
        
        // Output the results in the order of the targets
        for (int i = 0; i < k; ++i) {
            std::cout << target_counts[i] << " ";
        }
        std::cout << std::endl;
        
        delete[] target_counts;
    }
};

int main() {
    BinaryTree tree;
    int n, data, k;
    std::cin >> n >> k;
    int *arr = new int[n];
    int *targets = new int[k];
    
    for(int i = 0; i < n; i++) {
        std::cin >> data;
        arr[i] = data;
    }
    
    for(int i = 0; i < k; i++) {
        std::cin >> data;
        targets[i] = data;
    }
    
    tree.make_BT_from_array(arr, n);
    tree.alternating_path_sum(targets, k);
    
    delete[] arr;
    delete[] targets;
    
    return 0;
}
