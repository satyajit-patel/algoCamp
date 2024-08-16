class Solution {
public:
    pair<int, int> dfs(int root, vector<int> adj[], vector<int>& vis) {
        vis[root] = 1;
        int ans = 0;
        int subtreeSize = 1;
        set<int> st;

        for(auto& child: adj[root]) {
            if(!vis[child]) {
                auto it = dfs(child, adj, vis);
                int prevAns = it.first;
                int curSubtreeSize = it.second;
                subtreeSize += curSubtreeSize;
                ans += prevAns;
                // if left's subtree size and right's subtree size are equal 
                // then st.size must be <= 1 as it does't store duplicate
                // and thats where we will know that we found an ans 
                st.insert(curSubtreeSize); 
            }
        }

        if(st.size() <= 1) {
            ans++;;
        }
        // cout<<root<<"->"<<ans<<endl; // NICE VISUALIZATION OF RECURSION
        return {ans, subtreeSize};
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        int v = edges.size() + 1;
        vector<int> adj[v];
        vector<int> vis(v, 0);
        for(auto& it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int ans = dfs(0, adj, vis).first;
        return ans;
    }
};