// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
class Solution {
public:
    bool bfs(int root, vector<int> adj[], vector<int>& vis) {
        vis[root] = 1;
        queue<pair<int, int>> q;
        q.push({root, -1});
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int node = it.first;
            int parent = it.second;
            
            for(auto& child: adj[node]) {
                if(!vis[child]) {
                    vis[child] = 1;
                    q.push({child, node});
                } else if(child != parent) {
                    return true;
                }
            }
        }
        
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        for(int node=0; node<V; node++) {
            if(!vis[node]) {
                if(bfs(node, adj, vis)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};