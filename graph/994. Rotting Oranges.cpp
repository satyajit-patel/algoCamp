class Solution {
public:
    // left up right down 
    int dx[4] = {0, -1, 0, +1};
    int dy[4] = {-1, 0, +1, 0};

    bool isValid(int i, int j, int n, int m) {
        return i>=0 && i<n && j>=0 && j<m;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int emptyCell = 0;
        int freshOrange = 1;
        int rottenOrange = 2;
        int minTime = 0;
        int totalOranges = 0;
        int rottenOranges = 0;
        std::queue<std::pair<std::pair<int, int>, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] != emptyCell) totalOranges += 1;
                if(grid[i][j] == rottenOrange) q.push({{i, j}, minTime});
            }
        }
        while(!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            q.pop();
            rottenOranges += 1;
            minTime = std::max(minTime, time);
            for(int ind=0; ind<4; ind++) {
                int ni = i + dx[ind];
                int nj = j + dy[ind];
                if(isValid(ni, nj, n, m) && grid[ni][nj]==freshOrange) {
                    grid[ni][nj] = rottenOrange;
                    q.push({{ni, nj}, time+1});
                }
            }
        }
        if(rottenOranges == totalOranges) return minTime;
        return -1;
    }
};