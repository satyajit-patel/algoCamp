/*
        Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
        Output: true
        Explanation: There are two paths from vertex 0 to vertex 2:
        - 0 → 1 → 2
        - 0 → 2
    */

    bool dfs(int root, vector<int> adj[], auto& vis, int d) {
        vis[root] = 1;
        if(root == d) {
            return true;
        }
        for(auto& child: adj[root]) {
            if(!vis[child]) {
                if(dfs(child, adj, vis, d)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        vector<int> vis(n, 0);

        for(auto& row: edges) {
            int u = row[0];
            int v = row[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool ans = false;
        for(int node=0; node<n; node++) {
            if(!vis[node]) {
                if(dfs(source, adj, vis, destination)) {
                    ans = true;
                    break;
                }
            }
        }
        return ans;
    }