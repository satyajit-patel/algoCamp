#define vvi vector<vector<int>>
class Solution {
public:
    int n, m;
    // urdl
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    bool isvalid(int i, int j) {
        return i>=0 && i<n && j>=0 && j<m;
    }
    
    int bfs(int i, int j, vvi& grid, vvi& vis) {
        vis[i][j] = 1;
        queue<pair<pair<int, int>, int>> q;
        q.push({{i, j}, 0});
        while(!q.empty()) {
            i = q.front().first.first;
            j = q.front().first.second;
            int t = q.front().second;
            q.pop();
            if(i==0 && j==0) {
                return t;
            }
            for(int ind=0; ind<4; ind++) {
                int ni = i + dx[ind];
                int nj = j + dy[ind];
                if(isvalid(ni, nj) && grid[ni][nj]==1 && !vis[ni][nj]) {
                    vis[ni][nj] = 1;
                    q.push({{ni, nj}, t+1});
                }
            }
        }
        return -1;
    }

    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        n = N, m = M;
        if(A[0][0] == 0) {
            return -1;
        }
        if(A[X][Y] == 0) {
            return -1;
        }
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = bfs(X, Y, A, vis);
        return ans;
    }
};