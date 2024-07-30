class Solution {
public:
    /*
        Input: k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
        Output: [[3,0,0],[0,0,1],[0,2,0]]

        1------>2<--------3 // row so topoSort will be 1,3,2 or 3,1,2
        3------>2-------->1 // col so topoSort will be 3,2,1

    */

    vector<int> getTopo(vector<vector<int>>& edges, int n) {
        vector<int> topo;

        map<int, set<int>> adj;
        for(auto& row: edges) {
            int u = row[0];
            int v = row[1];
            adj[u].insert(v);
        }

        vector<int> inDegree(n+1, 0);
        for(int node=1; node<=n; node++) {
            for(auto& child: adj[node]) {
                inDegree[child]++;
            }
        }

        queue<int> q;
        for(int node=1; node<=n; node++) {
            if(inDegree[node] == 0) {
                q.push(node);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(auto& child: adj[node]) {
                inDegree[child]--;
                if(inDegree[child] == 0) {
                    q.push(child);
                }
            }
        }

        return topo;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowC, vector<vector<int>>& colC) {
        vector<int> topoRow = getTopo(rowC, k);
        if(topoRow.size() != k) {
            return {}; // cycle exist
        }
        vector<int> topoCol = getTopo(colC, k);
        if(topoCol.size() != k) {
            return {}; // cycle exist
        }

        vector<vector<int>> ans(k, vector<int>(k, 0));

        for(int i=0; i<k; i++) {
            for(int j=0; j<k; j++) {
                if(topoRow[i] == topoCol[j]) {
                    ans[i][j] = topoRow[i];
                }
            }
        }

        return ans;
    }
};