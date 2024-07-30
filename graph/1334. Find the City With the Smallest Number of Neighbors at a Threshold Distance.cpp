class Solution {
public:
    void dijksta(int root, vector<pair<int, int>>adj[], auto& dist) {
        dist[root] = 0;
        queue<pair<int, int>> q;
        q.push({root, dist[root]});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int node = it.first;
            int cost = it.second;

            for(auto& child: adj[node]) {
                int adjNode = child.first;
                int adjCost = child.second;
                if(cost + adjCost < dist[adjNode]) {
                    dist[adjNode] = cost + adjCost;
                    q.push({adjNode, dist[adjNode]});
                }
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int, int>> adj[n];
        for(auto& row: edges) {
            int u = row[0];
            int v = row[1];
            int w = row[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<vector<int>> allSourceShortPath;
        for(int node=0; node<n; node++) {
            vector<int> dist(n, INT_MAX); // single source short path
            dijksta(node, adj, dist);
            allSourceShortPath.push_back(dist); 
        }

        // now
        int ans = -1;
        int minCityVisit = INT_MAX;
        for(int i=0; i<n; i++) {
            int count = 0;
            for(int j=0; j<n; j++) {
                // cout<<allSourceShortPath[i][j]<<" ";
                if(allSourceShortPath[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            // cout<<endl;
            if(count <= minCityVisit) {
                minCityVisit = count;
                ans = i;
            }
        }

        return ans;
    }
};