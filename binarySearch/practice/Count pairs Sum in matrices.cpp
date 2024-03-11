/*
	    Input: 
        n = 3, x = 21
        mat1 = {{1, 5, 6},
                {8, 10, 11},
                {15, 16, 18}}
        mat2 = {{2, 4, 7},
                {9, 10, 12},
                {13, 16, 20}}
        OUTPUT: 4
        Explanation: 
        The pairs whose sum is found to be 21 are 
        (1, 20), (5, 16), (8, 13), (11, 10).
        
        Constraints:
        1 ≤ mat1[i][j] , mat2[i][j] ≤ 10^5
        1 ≤ n ≤ 100
        1 ≤ x ≤ 10^5
        
        f(n) = O(n^4)
	*/
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x) {
	    vector<int> a;
	    for(auto& row: mat2) {
	        for(auto& it: row) {
	            a.push_back(it);
	        }
	    }
	    
	    int ans = 0;
	    // O(n^2 logn)
	    for(auto& row: mat1) {
	        for(auto& it: row) {
	            /*
	                p1 + p2 = x
	                p1 = x - p2
	            */
	            int p1 = it;
	            int p2 = x - it;
	            if(binary_search(a.begin(), a.end(), p2)) {
	                ans++;
	            }
	        }
	    }
	    return ans;
	}