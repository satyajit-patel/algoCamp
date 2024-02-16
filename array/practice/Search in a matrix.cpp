int matSearch (vector <vector <int>> &mat, int N, int M, int X) {
	    // 1 <= N, M <= 10^3 i.e f(n) = O(n^2logn)
	    for(int i=0; i<N; i++) {
	        vector<int> A = mat[i];
	        if(binary_search(A.begin(), A.end(), X)) {
	            return 1;
	        }
	    }
	    return 0;
	}