#define vvc vector<vector<char>>
class Solution {
  public:
    // URDL DRU DRD DLD DLU
    int dx[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
    int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
    
    bool isvalid(vvc& grid, int i, int j) {
        return i>=0 && i<grid.size() && j>=0 && j<grid[0].size();
    }
    
    void bfs(vvc& grid, int i, int j, vector<vector<int>>& vis) {
        queue<pair<int, int>> q;
        q.push({i, j});
        while(!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            for(int ind=0; ind<8; ind++) {
                int ni = i + dx[ind];
                int nj = j + dy[ind];
                if(isvalid(grid, ni, nj) && grid[ni][nj]=='1') {
                    vis[ni][nj] = 1;
                    grid[ni][nj] = '0';
                    q.push({ni, nj});
                }
            }
        }
    }
  
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        char land = '1';
        char water = '0';
        int num_island = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == land && !vis[i][j]) {
                    vis[i][j] = 1;
                    num_island++;
                    bfs(grid, i, j, vis);
                }
            }
        }
        return num_island;
    }
};
