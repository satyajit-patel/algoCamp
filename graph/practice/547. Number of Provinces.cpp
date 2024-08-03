class DSU {
private:
    vector<int> parent;
public:
    DSU(int n) {
        parent.resize(n, -1);
    }

    int findParent(int node) {
        // base case
        if(parent[node] == -1) {
            return node;
        }

        // transition
        return parent[node] = findParent(parent[node]);
    }

    void merge(int u, int v) {
        int nu = findParent(u);
        int nv = findParent(v);
        if(nu == nv) {
            return;
        }
        parent[std::max(nu, nv)] = std::min(nu, nv);
    }
};

/*
        1-------2
            3
    so  node parent
        1       -1
        2       1
        3       -1
*/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int n = isConnected.size();

        DSU* dsu = new DSU(n+1);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isConnected[i][j]) {
                    int u = i+1;
                    int v = j+1;
                    dsu->merge(u, v);
                }
            }
        }

        for(int node=1; node<=n; node++) {
            if(dsu->findParent(node) == node) {
                ans++;
            }
        }

        return ans;
    }
};