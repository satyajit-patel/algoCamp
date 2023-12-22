class Solution {
public:
    vector<vector<char>> grid;
    string s;

    bool isvalid(int i, int j) {
        return i>=0 && i<grid.size() && j>=0 && j<grid[0].size();
    }

    bool state(int i, int j, int index) {
        // base case
        if(index >= s.size()) {
            return true;
        }
        if(!isvalid(i, j)) {
            return false;
        }
        if(grid[i][j] == '#') {
            return false;
        }
        if(grid[i][j] != s[index]) {
            return false;
        }

        // transition
        char ch = grid[i][j];
        grid[i][j] = '#';
        bool up = state(i-1, j, index+1);
        bool down = state(i+1, j, index+1);
        bool left = state(i, j-1, index+1);
        bool right = state(i, j+1, index+1);
        grid[i][j] = ch;
        bool ans = up || down || left || right;
        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        grid.clear(), grid = board;
        s.clear(), s = word;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(state(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};