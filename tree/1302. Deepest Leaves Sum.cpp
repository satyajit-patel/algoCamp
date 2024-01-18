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
    vector<vector<int>> bfs(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> temp;
            for(int i=0; i<n; i++) {
                root = q.front();
                q.pop();
                temp.push_back(root->val);
                if(root->left) {
                    q.push(root->left);
                }
                if(root->right) {
                    q.push(root->right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }

    int deepestLeavesSum(TreeNode* root) {
        vector<vector<int>> ans = bfs(root);
        int sum = 0;
        for(int i=0; i<ans[ans.size()-1].size(); i++) {
            sum += ans[ans.size()-1][i];
        }
        return sum;
    }
};