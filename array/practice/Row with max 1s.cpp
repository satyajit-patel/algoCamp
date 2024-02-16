int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int row = -1;
	    int maxi = INT_MIN;
	    for(int i=0; i<n; i++) {
	        int count = 0;
	        for(int j=0; j<m; j++) {
	            if(arr[i][j] == 1) {
	                count++;
	            }
	        }
	        if(count != 0 && count > maxi) {
	            maxi = count;
	            row = i;
	        }
	    }
	    return row;
	}