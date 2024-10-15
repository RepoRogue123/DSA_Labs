#include <iostream>

class BinaryTree{
    public:
    class Node {
        public:
        int data;
        Node* left;
        Node* right;
        // Implement any required node variables/methods/constructors here
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

    
    void alternating_path_sum(int *targets, int k){
        //Implement your main logic here
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
    
    tree.make_BT_from_array(arr,n);
    tree.alternating_path_sum(targets, k);
    return 0;
}