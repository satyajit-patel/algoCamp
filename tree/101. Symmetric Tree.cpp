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
    bool state(TreeNode* root1, TreeNode* root2) {
        // base case
        if(!root1 && !root2) {
            return true;
        }
        if(root1 && !root2) {
            return false;
        }
        if(!root1 && root2) {
            return false;
        }
        if(root1->val != root2->val) {
            return false;
        }

        // transition
        if(!state(root1->left, root2->right)) {
            return false;
        }
        if(!state(root1->right, root2->left)) {
            return false;
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        bool ans = state(root, root);
        return ans;
    }
};