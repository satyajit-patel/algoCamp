vector<int> getToposort(int n, vector<int> adj[]) {
        vector<int> toposort;
        vector<int> inDegree(n, 0);

        for(int node=0; node<n; node++) {
            for(auto& child: adj[node]) {
                inDegree[child]++;
            }
        }
        queue<int> q;
        for(int node=0; node<n; node++) {
            if(inDegree[node] == 0) {
                q.push(node);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            toposort.push_back(node);
            for(auto& child: adj[node]) {
                inDegree[child]--;
                if(inDegree[child] == 0) {
                    q.push(child);
                }
            }
        }
        return toposort;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto& row: prerequisites) {
            int u = row[0];
            int v = row[1];
            adj[v].push_back(u);
        }

        vector<int> toposort = getToposort(numCourses, adj);
        if(toposort.size() != numCourses) {
            return {};
        }
        return toposort;
    }