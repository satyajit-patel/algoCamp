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
    int ans;

    // void f(TreeNode* root, int maxSoFar) {
    //     // base case
    //     if(root == NULL) {
    //         return;
    //     }

    //     // transition
    //     if(root->val >= maxSoFar) {
    //         ans++;
    //     }
    //     f(root->left, max(maxSoFar, root->val));
    //     f(root->right, max(maxSoFar, root->val));
    // }

    void dfs(TreeNode* root, int maxSoFar) {
        if(root->val >= maxSoFar) {
            ans++;
        }
        if(root->left) {
            dfs(root->left, max(root->val, maxSoFar));
        }
        if(root->right) {
            dfs(root->right, max(root->val, maxSoFar));
        }
    }

    int goodNodes(TreeNode* root) {
        ans = 0;
        // f(root, root->val);
        dfs(root, INT_MIN);
        return ans;
    }
};