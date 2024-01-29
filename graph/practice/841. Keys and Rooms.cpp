class Solution {
public:
    unordered_map<int, set<int>> adj;
    vector<int> vis;

    void dfs(int node) {
        vis[node] = 1;
        for(auto& child: adj[node]) {
            if(!vis[child]) {
                dfs(child);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        adj.clear();
        vis.resize(n, 0);
        for(int node=0; node<n; node++) {
            int u = node;
            for(int j=0; j<rooms[node].size(); j++) {
                int v = rooms[node][j];
                adj[u].insert(v);
                // adj[v].insert(u);
            }
        }
        dfs(0);
        for(int node=0; node<n; node++) {
            if(!vis[node]) {
                return false;
            }
        }
        return true;
    }
};