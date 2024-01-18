/*
struct Node {
    int data;
    Node* left;
    Node* right;
};*/

class Solution {
public:
    Node* removekeys(Node* root, int l, int r) {
        // base case
        if(!root) {
            return NULL;
        }
        if(root->data < l) {
            return removekeys(root->right, l, r);
        }
        if(root->data > r) {
            return removekeys(root->left, l, r);
        }
        
        // transition
        root->left = removekeys(root->left, l, r);
        root->right = removekeys(root->right, l, r);
        return root;
    }
};