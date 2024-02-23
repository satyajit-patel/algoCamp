// https://practice.geeksforgeeks.org/contest/job-a-thon-30-hiring-challenge/problems

bool isPrime(int n) {
            if(n <= 1) {
                return false;
            }
            for(int i=2; i*i<=n; i++) {
                if(n%i == 0) {
                    return false;
                }
            }
            return true;
        }
    
        int dfs(int root, int& ans, vector<int> adj[], vector<int>& vis) {
            vis[root] = 1;
            int sum = root;
            for(auto& child: adj[root]) {
                if(!vis[child]) {
                    sum = (sum + dfs(child, ans, adj, vis)) % 100003;
                }
            }
            if(isPrime(sum)) {
                ans++;
            }
            return sum;
        }
    
        int primeSumSubtrees(int n,vector<vector<int>>&edges) {
            int ans = 0;
            vector<int> adj[n+1];
            vector<int> vis(n+1, 0);
            for(auto& row: edges) {
                int u = row[0];
                int v = row[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            dfs(1, ans, adj, vis);
            return ans;
        }