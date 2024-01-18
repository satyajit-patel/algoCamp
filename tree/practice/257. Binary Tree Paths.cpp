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
    void f(TreeNode* root, vector<string>& ans, string temp) {
        // base case
        if(root->left == NULL && root->right == NULL) {
            temp += to_string(root->val);
            ans.push_back(temp);
            return;
        }

        // transition
        if(root->left) {
            f(root->left, ans, temp + to_string(root->val) + "->");
        }
        if(root->right) {
            f(root->right, ans, temp + to_string(root->val) + "->");
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp = "";
        f(root, ans, temp);
        return ans;
    }
};