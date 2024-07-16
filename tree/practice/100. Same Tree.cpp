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
        if((!t1) && (!t2)) {
            return true;
        }
        if((t1) && (!t2)) {
            return false;
        }
        if((!t1) && (t2)) {
            return false;
        }

        // assumption
        bool left = f(t1->left, t2->left);
        bool right = f(t1->right, t2->right);

        // self work
        bool curr = (t1->val == t2->val);
        bool ans = curr && left && right;
        return ans;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans = f(p, q);
        return ans;
    }
};