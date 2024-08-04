// https://leetcode.com/contest/biweekly-contest-136/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-i/
class Solution {
public:
    int f(vector<vector<int>>& grid) {
        int x = 0;
        for(auto& row: grid) {
            int i = 0;
            int j = row.size() - 1;
            while(i <= j) {
                if(row[i] != row[j]) {
                    x++;
                }
                i++;
                j--;
            }
        }
        return x;
    }

    vector<vector<int>> getTranspose(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        /*
            carefull
            grid is n * m matrix
            transpose will be m * n matrix
        */
        vector<vector<int>> transpose(m, vector<int>(n, 0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                transpose[j][i] = grid[i][j];
            }
        }
        return transpose;
    }

    int minFlips(vector<vector<int>>& grid) {
        int x = f(grid);
        vector<vector<int>> transpose = getTranspose(grid);
        int y = f(transpose);

        return std::min(x, y);
    }
};