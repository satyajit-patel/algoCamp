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
    set<int> st;
    int target;

    bool f(TreeNode* node) {
        if(!node) {
            return false;
        }
        if(st.count(target - node->val)) {
            return true;
        }

        st.insert(node->val);
        return f(node->left) || f(node->right);
    } 

    bool findTarget(TreeNode* root, int k) {
        st.clear();
        target = k;
        bool ans = f(root);
        return ans;
    }
};