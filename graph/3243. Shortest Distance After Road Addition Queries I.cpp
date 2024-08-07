class Solution {
public:
    int getShortPathCostBFS(vector<int> adj[], int source, int target) {
        queue<pair<int, int>> q; // node cost
        q.push({source, 0});

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int node = it.first;
            int cost = it.second;

            if(node == target) {
                return cost;
            }

            for(auto& child: adj[node]) {
                q.push({child, cost+1});
            }
        }

        return -1;
    }

    int getShortPathCostDijkstra(vector<int> adj[], int source, int target) {
        int n = target + 1;
        vector<int> dist(n, INT_MAX);
        dist[source] = 0;
        queue<pair<int, int>> q; // node cost
        q.push({source, dist[source]});

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int node = it.first;
            int cost = it.second;

            for(auto& child: adj[node]) {
                int adjNode = child;
                int adjCost = cost + 1;
                if(adjCost < dist[adjNode]) {
                    dist[adjNode] = adjCost;
                    q.push({adjNode, dist[adjNode]});
                }
            }
        }

        // for(auto& it: dist) {
        //     cout<<it<<" ";
        // }
        // cout<<endl;

        return dist[target];
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> adj[n];
        for(int node=0; node<n-1; node++) {
            int u = node;
            int v = node+1;
            // directed graph
            adj[u].push_back(v);
        }

        for(auto& row: queries) {
            int u = row[0];
            int v = row[1];
            adj[u].push_back(v);
            // int cost = getShortPathCostBFS(adj, 0, n-1); // TLE
            int cost = getShortPathCostDijkstra(adj, 0, n-1);
            ans.push_back(cost);
        }

        return ans;
    }
};