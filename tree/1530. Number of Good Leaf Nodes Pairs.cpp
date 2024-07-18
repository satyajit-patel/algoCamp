/**
 * Definition for leaf binary tree node.
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
    void shortPath(TreeNode* root, auto& leaf, auto& adj, int distance, auto& vis, int& ans) {
        vis[root] = true;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int step = it.second;

            if(node != root && leaf.count(node) && step <= distance) {
                ans++;
            }
            if(step > distance) { // optimization
                return;
            }
    
            for(auto& child: adj[node]) {
                if(!vis[child]) {
                    vis[child] = true;
                    q.push({child, step+1});
                }
            }
        }
    }

    void dfs(TreeNode* root, TreeNode* prev, auto& leaf, auto& adj) {
        // base case
        if(!root) {
            return;
        }
        if(!root->left && !root->right) {
            leaf.insert(root);
        }

        // transition
        if(prev) {
            // Tree to Graph conversion
            adj[root].insert(prev);
            adj[prev].insert(root);
        }

        dfs(root->left, root, leaf, adj);
        dfs(root->right, root, leaf, adj);
    }

    int countPairs(TreeNode* root, int distance) {
        int ans = 0;

        set<TreeNode*> leaf;
        map<TreeNode*, set<TreeNode*>> adj;
        dfs(root, NULL, leaf, adj);

        for(auto& it: leaf) {
            map<TreeNode*, bool> vis;
            shortPath(it, leaf, adj, distance, vis, ans);
        }

        return ans/2;
    }
};