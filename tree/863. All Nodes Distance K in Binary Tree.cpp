/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* node, TreeNode* prevNode, map<int, set<int>>& adj) {
        // base case
        if(!node) {
            return;
        }
        if(prevNode) {
            int u = node->val;
            int v = prevNode->val;
            // undirected
            adj[u].insert(v);
            adj[v].insert(u);
        }

        // transition
        dfs(node->left, node, adj);
        dfs(node->right, node, adj);
    }

    void bfs(int node, map<int, set<int>>& adj, int k, vector<int>& ans) {
        map<int, bool> vis;
        vis[node] = 1;
        queue<pair<int, int>> q;
        q.push({node, 0});

        while(!q.empty()) {
            auto it =q.front();
            q.pop();
            node = it.first;
            int step = it.second;

            if(step == k) {
                ans.push_back(node);
            }

            for(auto& child: adj[node]) {
                if(!vis[child]) {
                    vis[child] = 1;
                    q.push({child, step+1});
                }
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // tree -> graph 
        map<int, set<int>> adj;
        dfs(root, NULL, adj);

        vector<int> ans;
        bfs(target->val, adj, k, ans);
        return ans;
    }
};