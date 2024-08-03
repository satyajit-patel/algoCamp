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

    int dx[4] = {0, -1, 0, +1}; // LURD
    int dy[4] = {-1, 0, +1, 0};

    bool isvalid(int i, int j, auto& board) {
        return i >= 0 && i< board.size() && j >= 0 && j < board[0].size();
    }

    vector<vector<int>> vis;
    bool state(int i, int j, int index, auto& board, auto& word) {
        // base case
        if(index >= word.size()) {
            return true;
        }
        if(!isvalid(i, j, board)) {
            return false;
        }
        if(word[index] != board[i][j]) {
            return false;
        }
        if(vis[i][j]) {
            return false;
        }
        // transition
        // char original = board[i][j];
        // board[i][j] = '$';
        // cout<<board[i][j]<<" ";
        vis[i][j] = 1;
        for(int ind=0; ind<4; ind++) {
            int ni = i + dx[ind];
            int nj = j + dy[ind];
            if(state(ni, nj, index + 1, board, word)) {
                return true;
            }
        }
        // board[i][j] = original;
        vis[i][j] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vis.resize(board.size(), vector<int>(board[0].size(), 0));
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(state(i, j, 0, board, word)) {
                    return true;
                }
                // cout<<endl;
            }
        }
        return false;
    }
};