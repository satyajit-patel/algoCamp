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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, TreeNode*> mp;
        set<int> st;
        for(auto& row: descriptions) {
            int parent = row[0];
            int child  = row[1];
            int isLeft = row[2];

            if(!mp.count(parent)) {
                TreeNode* newNode = new TreeNode(parent);
                mp[parent] = newNode;
            }
            if(!mp.count(child)) {
                mp[child] = new TreeNode(child);
            }
            if(isLeft) {
                mp[parent]->left = mp[child];
            } else {
                mp[parent]->right = mp[child];
            }

            st.insert(child);
        }

        for(auto& row: descriptions) {
            int parent = row[0];
            if(!st.count(parent)) {
                return mp[parent];
            }
        }
        return NULL;
    }
};