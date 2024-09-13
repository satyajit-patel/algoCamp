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

    parent[max(x, y)] = min(x, y); 
  }
};

// class Solution {
// public:
//   // 684. Redundant Connection
//   vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//     int n = edges.size();
//     vector<int> ans;

//     DSU* dsu = new DSU(n+1);
//     for(auto& row: edges) {
//       int u = row[0];
//       int v = row[1];
//       if(dsu->findParent(u) != dsu->findParent(v)) {
//         dsu->merge(u, v);
//       } else {
//         ans.push_back(u);
//         ans.push_back(v);
//       }
//     }

//     return ans;
//   }
// };

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extraEdges = 0;

        DSU* dsu = new DSU(n);
        for(auto& row: connections) {
            int u = row[0];
            int v = row[1];
            if(dsu->findParent(u) != dsu->findParent(v)) {
                dsu->merge(u, v);
            } else {
                extraEdges++;
            }
        }

        int numNetworks = 0;
        for(int node=0; node<n; node++) {
            if(dsu->findParent(node) == node) {
                numNetworks++;
            }
        }

        int edgeNeedtoConnect = numNetworks - 1;
        if(edgeNeedtoConnect > extraEdges) {
            return -1;
        }
        return edgeNeedtoConnect;
    }
};