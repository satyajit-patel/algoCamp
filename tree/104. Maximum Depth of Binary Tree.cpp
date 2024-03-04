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
    int f(TreeNode* root) {
        // base case
        if(!root) return 0;

        // recursive case
        int head = f(root->left);
        int tail = f(root->right);

        // return case
        int ans = std::max(head, tail) + 1;
        return ans;
    }

    int maxDepth(TreeNode* root) {
        return f(root);
    }
};