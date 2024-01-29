class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) {
            return true;
        }

        unordered_map<int, set<int>> adj;
        for(auto& row: edges) {
            int u = row[0];
            int v = row[1];
            adj[u].insert(v);
            adj[v].insert(u);
        }

        vector<int> vis(n, 0);
        vector<int> dist(n, 0);
        vector<int> parent(n, -1);

        queue<int> q;
        q.push(source);
        vis[source] = 1;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto& child : adj[node]) {
                if(!vis[child]) {
                    q.push(child);
                    vis[child] = 1;
                    dist[child] = dist[node] + 1;
                    parent[child] = node;
                }
            }
        }

        // dist of dest is not NULL i.e it is reachable
        return (dist[destination] != 0) ? true : false;
    }
};