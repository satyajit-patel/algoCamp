class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        vector<vector<int>> dir = {{-1, 0}, {0, +1}, {+1, 0}, {0, -1}};
        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int ind=0; ind<4; ind++) {
                int ni = i + dir[ind][0];
                int nj = j + dir[ind][1];
                if(ni>=0 && ni<n && nj>=0 && nj<m) {
                    int newCost = dist[i][j] + 1;
                    if(newCost < dist[ni][nj]) {
                        q.push({ni, nj});
                        dist[ni][nj] = newCost;
                    }
                }
            }
        }
        return dist;
    }
};