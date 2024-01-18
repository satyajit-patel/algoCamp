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
    bool f(TreeNode* t1, TreeNode* t2) {
        // base case
        if(t1 == NULL && t2 == NULL) {
            return true;
        }
        if(t1 == NULL && t2 != NULL) {
            return false;
        }
        if(t1 != NULL && t2 == NULL) {
            return false;
        }

        // transition
        return (t1->val == t2->val) && f(t1->left, t2->right) && f(t1->right, t2->left);
    }

    bool isSymmetric(TreeNode* root) {
        return f(root, root);
    }
};