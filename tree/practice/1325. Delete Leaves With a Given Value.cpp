/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* f(TreeNode* root, int x) {
        // base case
        if(!root) {
            return NULL;
        }

        // transition
        root->left = f(root->left, x);
        root->right = f(root->right, x);
        if(!root->left && !root->right && root->val == x) {
            return NULL;
        }
        return root;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return f(root, target);
    }
};