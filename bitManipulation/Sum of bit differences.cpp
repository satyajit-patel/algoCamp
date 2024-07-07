/*
	    Input: 
        n = 2
        arr[] = {1, 2}
        Output: 4
        Explanation: All possible pairs of an array are (1, 1), (1, 2), (2, 1), (2, 2).
        Sum of bit differences = 0 + 2 + 2 + 0 = 4
        
        Constraints:
        1 <= n <= 105
        1 <= arr[i] <= 105
	*/
	
	long long sumBitDifferences(int arr[], int n) {
	    
	    /*
	        note :-
	        
	        ele & 1 == 0            => even
	        ele & (ele-1) == 0      => power of 2
	        // (ele >> k) & 1 == 1  => kth bit is set
	        ele & (1 << k) == 1     => kth bit is set
	        
	        ele ^ (1 << k)          => toggles the kth bit
	        ele | (1 << k)          => sets the kth bit
	        ele & ~(1 << k)         => unsets the kth bit
	    */
	    
	    long long ans = 0;
	    // 32 * n = O(n)
	    for(int k=0; k<32; k++) {
	        long long num_ones = 0;
	        for(int i=0; i<n; i++) {
	           // bool isKthBitSet = (arr[i]>>k) & 1;
	           bool isKthBitSet = arr[i] & (1 << k);
	            if(isKthBitSet) {
	                num_ones++;
	            }
	        }
	        long long num_zeros = n - num_ones;
	        ans += 2 * num_ones * num_zeros;
	    }
	    return ans;
	}