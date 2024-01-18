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
    int minDiff;
    TreeNode* prevNode;

    void dfs(TreeNode* root) {
        // base case
        if(!root) {
            return;
        }

        // transition
        dfs(root->left);
        if(prevNode != NULL) {
            minDiff = min(minDiff, root->val - prevNode->val);
        }
        prevNode = root;
        dfs(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        minDiff = INT_MAX;
        prevNode = NULL;
        // in BST inorder traversal is always in sorted order
        dfs(root);
        return minDiff;
    }
};