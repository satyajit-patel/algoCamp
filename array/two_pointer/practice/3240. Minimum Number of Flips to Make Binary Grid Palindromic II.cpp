class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        // default
        for(int i=0; i<n/2; i++) {
            for(int j=0; j<m/2; j++) {
                int ones = 0;
                // connected points
                int topLeft = grid[i][j];
                int topRight = grid[i][m-1-j];
                int bottomLeft = grid[n-1-i][j];
                int bottomRight = grid[n-1-i][m-1-j];
                ones += topLeft == 1;
                ones += topRight == 1;
                ones += bottomLeft == 1;
                ones += bottomRight == 1;

                if(ones == 4 || ones == 0) {
                    continue;
                } else if(ones > 2) {
                    ans += (4-ones); // convert zeros to ones
                } else {
                    ans += ones; // convert ones to zeros
                }
            }
        }

        int pair = 0;
        int option = 0;

        // if odd rows
        if(n%2) {
            int row = n/2;
            for(int i=0; i<m/2; i++) {
                if(grid[row][i] == 1 && grid[row][m-1-i] == 1) {
                    pair++;
                } else if(grid[row][i] != grid[row][m-1-i]) {
                    ans++;
                    option++;
                }
            }
        }
        // if odd colums
        if(m%2) {
            int col = m/2;
            for(int i=0; i<n/2; i++) {
                if(grid[i][col] == 1 && grid[n-1-i][col] == 1) {
                    pair++;
                } else if(grid[i][col] != grid[n-1-i][col]) {
                    ans++;
                    option++;
                }
            }
        }
        if(n%2 && m%2 && grid[n/2][m/2] == 1) {
            ans++;
        }

        if(pair%2) {
            if(!option) {
                ans += 2;
            }
        }

        return ans; 
    }
};