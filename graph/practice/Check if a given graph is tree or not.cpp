class Solution {
public:
    void dfs(int node, vector<int>& vis, unordered_map<int, set<int>>& adj) {
        vis[node] = 1;
        for(auto& child: adj[node]) {
            if(!vis[child]) {
                dfs(child, vis, adj);
            }
        }
    }

    int isTree(int n, int m, vector<vector<int>>& g) {
        int tree = 1;
        int notTree = 0;
        int numOfNodes = n;
        int numOfEdges = m;
        
        if(numOfEdges != numOfNodes-1) {
            return notTree;
        }
        
        unordered_map<int, set<int>> adj;
        for(auto& row: g) {
            int u = row[0];
            int v = row[1];
            adj[u].insert(v);
            adj[v].insert(u);
        }
        vector<int> vis(n, 0);
        dfs(0, vis, adj);
        for(int node=0; node<numOfNodes; node++) {
            if(!vis[node]) {
                return notTree;
            }
        }
        return tree;
    }
};