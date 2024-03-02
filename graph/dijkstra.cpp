// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
class Solution {
public:
    vector<int> f(int V, vector<vector<int>> adj[], int S) {
        std::vector<int> dist(V, INT_MAX);
        dist[S] = 0;
        std::queue<std::pair<int, int>> q;
        q.push({S, dist[S]});
        while(!q.empty()) {
            int node = q.front().first;
            int cost = q.front().second;
            q.pop();
            for(auto& child:adj[node]) {
                int adjNode = child[0];
                int adjCost = child[1];
                if(cost+adjCost < dist[adjNode]) {
                    dist[adjNode] = cost + adjCost;
                    q.push({adjNode, dist[adjNode]});
                }
            }
        }
        return dist;
    }

    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        std::vector<int> dist = f(V, adj, S);
        return dist;
    }
};
