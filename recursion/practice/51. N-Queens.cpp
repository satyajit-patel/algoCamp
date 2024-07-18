class Solution {
public:
    bool issafe(int row, int col, auto& grid) {
        // leftUpCorner
        int i = row;
        int j = col;
        while(i >= 0 && j >= 0) {
            if(grid[i][j] == 'Q') {
                return false;
            }
            i--;
            j--;
        }

        // absoluteLeft
        i = row;
        j = col;
        while(j >= 0) {
            if(grid[i][j] == 'Q') {
                return false;
            };
            j--;
        }

        // leftDownCorner
        i = row;
        j = col;
        while(i < grid.size() && j>=0) {
            if(grid[i][j] == 'Q') {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    void state(int j, auto& grid, auto& ans) {
        // base case
        if(j >= grid[0].size()) {
            ans.push_back(grid);
            return;
        }

        // transition
        for(int i=0; i<grid.size(); i++) {
            if(issafe(i, j, grid)) {
                grid[i][j] = 'Q';
                state(j+1, grid, ans);
                grid[i][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> grid(n, string(n, '.'));
        state(0, grid, ans);
        return ans;
    }
};