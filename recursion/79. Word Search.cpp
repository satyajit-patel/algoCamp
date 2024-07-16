class Solution {
public:
    /*
        Input: board = [["A","B","C","E"],
                        ["S","F","C","S"],
                        ["A","D","E","E"]], word = "SEE"
        Output: true

        Input: board = [["a"]], word = "a"
        Output: true
    */

    int dx[4] = {0, -1, 0, +1};
    int dy[4] = {-1, 0, +1, 0};

    bool valid(int i, int j, auto& grid) {
        return i>=0 && i<grid.size() && j >=0 && j<grid[0].size();
    }

    bool state(int index, int i, int j, auto& grid, auto& s) {
        // base case
        if(index >= s.size()) {
            return true;
        }
        if(!valid(i, j, grid)) {
            return false;
        }
        if(grid[i][j] != s[index]) {
            return false;
        }

        // transition
        char dummy = grid[i][j];
        grid[i][j] = '#';
        for(int ind=0; ind<4; ind++) {
            int ni = i + dx[ind];
            int nj = j + dy[ind];
            if(state(index+1, ni, nj, grid, s)) {
                return true;
            }
        }
        grid[i][j] = dummy;
        return false;
    }

    bool exist(vector<vector<char>>& board, string& word) {
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(state(0, i, j, board, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};