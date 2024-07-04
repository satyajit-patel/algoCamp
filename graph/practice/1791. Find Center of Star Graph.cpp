class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int, set<int>> adj;
        for(auto& row: edges) {
            int u = row[0];
            int v = row[1];
            adj[u].insert(v);
            adj[v].insert(u);
        }

        int n = adj.size();
        vector<int> inOrder(n+1, 0);
        for(int node=1; node<=n; node++) {
            for(auto& child: adj[node]) {
                inOrder[child]++;
            }
        }

        for(int node=1; node<=n; node++) {
            if(inOrder[node] == (n-1)) {
                return node;
            }
        }
        return -1;
    }
};