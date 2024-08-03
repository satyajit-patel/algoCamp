vector<int> bfs(int V, vector<int> adj[]) {
        vector<int> topo;
        
        vector<int> inDegree(V, 0);
        for(int node=0; node<V; node++) {
            for(auto& child: adj[node]) {
                inDegree[child]++;
            }
        }
        queue<int> q;
        for(int node=0; node<V; node++) {
            if(inDegree[node] == 0) {
                q.push(node);
            }
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            topo.push_back(node);
            
            for(auto& child: adj[node]) {
                inDegree[child]--;
                if(inDegree[child] == 0) {
                    q.push(child);
                }
            }
        }
        
        return topo;
    }

    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> topo = bfs(V, adj);
        return topo.size() != V;
    }