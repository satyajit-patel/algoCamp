class DSU {
private:
    vector<int> parent;
public:
    DSU(int n) {
        parent.resize(n, -1);
    }

    int findParent(int node) {
        if(parent[node] == -1) {
            return node;
        }
        // keep updating parent
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

class Solution {
public:
    /*
            A
        1---------2
        |      .
    B   |   . C
        | .
        3

        so connection "C" is redundant here
    */

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int n = edges.size();
        DSU* dsu = new DSU(n+1);

        for(auto& row: edges) {
            int u = row[0];
            int v = row[1];
            if(dsu->findParent(u) != dsu->findParent(v)) {
                dsu->merge(u, v);
            } else {
                ans.push_back(u);
                ans.push_back(v);
            }
        }

        return ans;
    }
};