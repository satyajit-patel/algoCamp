/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* optimized(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if(!root) {
            return root;
        }

        // asumption
        if(p->val < root->val && (q->val < root->val)) {
            return optimized(root->left, p, q);
        }
        if(p->val > root->val && (q->val > root->val)) {
            return optimized(root->right, p, q);
        }
        return root;
    }

    // classic
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if(!root || (root == p) || (root == q)) {
            return root;
        }

        // asumption
        TreeNode* left = dfs(root->left, p, q);
        TreeNode* right = dfs(root->right, p, q);

        // self work
        if(left && right) {
            return root;
        } else if(!left && right) {
            return right;
        }
        return left;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // TreeNode* lca = dfs(root, p, q);
        // return lca;

        // or
        return optimized(root, p, q);
    }
};