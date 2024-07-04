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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int xCoOrdinate = it.second.first;
            int level = it.second.second;
            mp[xCoOrdinate][level].insert(node->val);

            if(node->left) {
                q.push({node->left, {xCoOrdinate-1, level+1}});
            }
            if(node->right) {
                q.push({node->right, {xCoOrdinate+1, level+1}});
            }
        }

        vector<vector<int>> ans;
        for(auto& row: mp) {
            vector<int> temp;
            for(auto& it: row.second) {
                temp.insert(temp.end(), it.second.begin(), it.second.end());
            }
            ans.push_back(temp);
        }
        return ans;

        // vector<vector<int>> ans;
        // for(auto& row: mp) {
        //     vector<int> temp;
        //     for(auto& it: row.second) {
        //         auto ms = it.second;
        //         for(auto& ele: ms) {
        //             temp.push_back(ele);
        //         }
        //     }
        //     ans.push_back(temp);
        // }
        // return ans;
    }
};