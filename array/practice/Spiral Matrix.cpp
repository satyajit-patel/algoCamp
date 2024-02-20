/*
	    Input: 
        N = 3, M = 3, K = 4
        A[] = {{1, 2, 3}, 
               {4, 5, 6}, 
               {7, 8, 9}}
        Output: 
        6
        Explanation: Spiral traversal of matrix: 
        {1, 2, 3, 6, 9, 8, 7, 4, 5}. Fourth element
        is 6.
	*/
	
	int findK(vector<vector<int>> &a, int n, int m, int k) {
        vector<int> ans;
        int front_row = 0, front_col = 0, back_row = n-1, back_col = m-1;
        int tot_ele = n*m, num_ele = 0;
        while(num_ele < tot_ele) {
            for(int i=front_col; i<=back_col; i++) {
                ans.push_back(a[front_row][i]);
                num_ele++;
            }
            front_row++;
            
            for(int i=front_row; i<=back_row; i++) {
                ans.push_back(a[i][back_col]);
                num_ele++;
            }
            back_col--;
            
            for(int i=back_col; i>=front_col; i--) {
                ans.push_back(a[back_row][i]);
                num_ele++;
            }
            back_row--;
            
            for(int i=back_row; i>=front_row; i--) {
                ans.push_back(a[i][front_col]);
                num_ele++;
            }
            front_col++;
        }
        return ans[k-1];
    }
