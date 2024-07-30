class DSU {
private:
    vector<int> parent, height;
public:
    DSU(int n) {
        parent.resize(n, -1);
        height.resize(n, -1);
    }
    int findParent(int x) {
        if(parent[x] == -1) return x;
        return parent[x] = findParent(parent[x]);
    }
    void merge(int u, int v) {
        int x = findParent(u);
        int y = findParent(v);
        if(x == y) return;

        parent[std::max(x, y)] = std::min(x, y); 
    }
};

class Solution {
public:
    // 684. Redundant Connection
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> ans;

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
