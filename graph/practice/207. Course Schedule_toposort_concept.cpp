class Solution {
public:
    vector<int> getToposort(map<int, set<int>>& adj, int n) {
        std::vector<int> toposort, inDegree(n, 0);
        for(int node=0; node<n; node++) {
            for(auto& child:adj[node]) inDegree[child]++;
        }
        std::queue<int> q;
        for(int node=0; node<n; node++) {
            if(inDegree[node] == 0) q.push(node);
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            toposort.push_back(node);
            for(auto& child:adj[node]) {
                inDegree[child]--;
                if(inDegree[child] == 0) q.push(child);
            }
        }
        return toposort; 
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::map<int, std::set<int>> adj;
        for(auto& row:prerequisites) {
            int u = row[0];
            int v = row[1];
            // you must take course "v" first if you want to take course "u".
            adj[v].insert(u);
        }
        std::vector<int> toposort = getToposort(adj, numCourses);
        return toposort.size() == numCourses;
    }
};