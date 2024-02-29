 /*
        Input: matrix =
        [
        [0,1,1,1],
        [1,1,1,1],
        [0,1,1,1]
        ]
        Output: 15
        Explanation: 
        There are 10 squares of side 1.
        There are 4 squares of side 2.
        There is  1 square of side 3.
        Total number of squares = 10 + 4 + 1 = 15.
    */

    int countSquares(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(mat[i][j] == 1) {
                    mat[i][j] += min({mat[i-1][j], mat[i][j-1], mat[i-1][j-1]});
                }
            }
        }

        int ans = 0;
        for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat[i].size(); j++) {
                ans += mat[i][j];
            }
        }
        return ans;
    }