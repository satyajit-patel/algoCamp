/* A binary tree node
struct Node {
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    bool hasPathSum(Node *root, int S) {
        // base case
        if(!root) {
            return false;
        }
        if(S < 0) {
            return false;
        }
        if(!root->left && !root->right) {
            return (root->data - S) == 0;
        }
        
        // transition
        bool left = hasPathSum(root->left, S-root->data);
        bool right = hasPathSum(root->right, S-root->data);
        bool ans = left || right;
        return ans;
    }
};
