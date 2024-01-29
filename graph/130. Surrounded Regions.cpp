class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board, int n, int m) {
        // base case
        if(!(i>=0 && i<n && j>=0 && j<m)) {
            return;
        }
        if(board[i][j] != '-') {
            return;
        }

        // transition;
        board[i][j] = 'O';
        vector<vector<int>> dir = {{-1,0}, {0,+1}, {+1,0}, {0,-1}};
        for(int ind=0; ind<4; ind++) {
            int ni = i + dir[ind][0];
            int nj = j + dir[ind][1];
            dfs(ni, nj, board, n, m);
        }
    }

    void bfs(int i, int j, vector<vector<char>>& board, int n, int m) {
        queue<pair<int, int>> q;
        q.push({i, j});
        board[i][j] = 'O';
        while(!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            vector<vector<int>> dir = {{-1,0}, {0,+1}, {+1,0}, {0,-1}};
            for(int ind=0; ind<4; ind++) {
                int ni = i + dir[ind][0];
                int nj = j + dir[ind][1];
                if(ni>=0 && ni<n && nj>=0 && nj<m) {
                    if(board[ni][nj] == '-') {
                        q.push({ni, nj});
                        board[ni][nj] = 'O';
                    }
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = '-';
                }
            }
        }

        // top
        for(int i=0; i<m; i++) {
            if(board[0][i] == '-') {
                // bfs(0, i, board, n, m);
                dfs(0, i, board, n, m);
            }
        }
        // bottom
        for(int i=0; i<m; i++) {
            if(board[n-1][i] == '-') {
                // bfs(n-1, i, board, n, m);
                dfs(n-1, i, board, n, m);
            }
        }
        // left
        for(int i=0; i<n; i++) {
            if(board[i][0] == '-') {
                // bfs(i, 0, board, n, m);
                dfs(i, 0, board, n, m);
            }
        }
        // right
        for(int i=0; i<n; i++) {
            if(board[i][m-1] == '-') {
                // bfs(i, m-1, board, n, m);
                dfs(i, m-1, board, n, m);
            }
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == '-') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};