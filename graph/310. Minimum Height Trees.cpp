/*
        observation:
            to make less height tree we have to make the root
            which is at inner level of graph.

            we can't make make leaf node as root for sure
            so we need to go in from outer side level to level
    */

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) {
            return {0};
        }
        vector<int> ans;

        vector<int> adj[n];
        for(auto& row: edges) {
            int u = row[0];
            int v = row[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> inDegree(n, 0);
        for(int node=0; node<n; node++) {
            for(auto& child: adj[node]) {
                inDegree[child]++;
            }
        }
        // cout<<inDegree[0]<<endl;

        queue<int> q;
        for(int node=0; node<n; node++) {
            // pushing only the leaf nodes
            if(inDegree[node] == 1) {
                q.push(node);
            }
        }

        while(n > 2) {
            int curSize = q.size();
            n -= curSize;
            for(int i=0; i<curSize; i++) {
                int node = q.front();
                q.pop();

                for(auto& child: adj[node]) {
                    inDegree[child]--;
                    if(inDegree[child] == 1) {
                        q.push(child);
                    }
                }
            }
        }

        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }