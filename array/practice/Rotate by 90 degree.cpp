/*
        Input:
        N = 3 
        matrix[][] = {{1, 2, 3},
                      {4, 5, 6}
                      {7, 8, 9}}
        Output: 
        Rotated Matrix:
        3 6 9
        2 5 8
        1 4 7
    */
    void rotateby90(vector<vector<int> >& matrix, int n) { 
        vector<vector<int>> ans(n, vector<int>(n));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                ans[n-j-1][i] = matrix[i][j];
            }
        }
        matrix.swap(ans);
    } 