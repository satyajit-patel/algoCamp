class Solution {
public:
    int N;
    vector<vector<int>> ans;
    unordered_map<int, set<int>> adj;

    void dfs(int node, vector<int>& path) {
        // base case
        if(node == N-1) {
            ans.push_back(path);
            return;
        }

        // transition
        for(auto& child: adj[node]) {
            path.push_back(child);
            dfs(child, path);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        N = graph.size();
        adj.clear();
        for(int node=0; node<N; node++) {
            int u = node;
            for(int j=0; j<graph[node].size(); j++) {
                int v = graph[node][j];
                adj[u].insert(v);
            }
        }
        ans.clear();
        vector<int> path;
        path.push_back(0);
        dfs(0, path);
        return ans;
    }
};