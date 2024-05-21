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
    int moves;

    int state(TreeNode* root) {
        // base case
        if(!root) {
            return 0;
        }

        // transition
        int left = state(root->left);
        int right = state(root->right);
        // + means we have extra, - means we need
        moves += abs(left) + abs(right);
        // keep one coin and return extra
        return (left + right + root->val) - 1;
    }

    int distributeCoins(TreeNode* root) {
        moves = 0;
        state(root);
        return moves;
    }
};