#include <bits/stdc++.h>
using namespace std;
//Getting faster


#define repeat(i,s,e) for(long long i=s;i<e;i++)
#define elif else if
class node {
    public:
    int data;
    node* left;
    node* right;
    
    node(): data(0), left(nullptr), right(nullptr) {}
    
    node(int val): data(val), left(nullptr), right(nullptr) {}
};


class binary_tree{
    public:
    node* root = nullptr;
    
    void make_binary_tree_from_array(int *arr, int size){
        this->root = construct_binary_tree_from_level_order_array(arr, 0, size);
    }
    
    node* construct_binary_tree_from_level_order_array(int *arr, int index, int size){
        if (index < size && arr[index] != -1) {
            node* newnode = new node(arr[index]);
            newnode->left = construct_binary_tree_from_level_order_array(arr, 2 * index + 1, size); 
            newnode->right = construct_binary_tree_from_level_order_array(arr, 2 * index + 2, size);
            return newnode;
        }
        return nullptr;
    }
};

void inorder(node* root){
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

/*Logic --->>> We here call the function recursively, in both the trees simultaneously and we have defined base case in such a way such that whenever we sum and either of the two nodes is null,we return the other node */

node* merge_trees(node* root1, node* root2){
    if (root1 == nullptr) {
        return root2;
    }
    if (root2 == nullptr) {
        return root1;
    }
    
    root1->data += root2->data;
    root1->left = merge_trees(root1->left, root2->left);
    root1->right = merge_trees(root1->right, root2->right);
    
    return root1;
}

int main(){
    binary_tree tree1, tree2;
    int n,m;
    cin>>n;
    int arr[n];
    repeat(i,0,n) cin>>arr[i];
    tree1.make_binary_tree_from_array(arr,n);
    
    cin>>m;
    int brr[m];
    repeat(i,0,m) cin>>brr[i];
    tree2.make_binary_tree_from_array(brr,m);
    binary_tree merged_tree;
    merged_tree.root = merge_trees(tree1.root,tree2.root);
    inorder(merged_tree.root);
    return 0;
}