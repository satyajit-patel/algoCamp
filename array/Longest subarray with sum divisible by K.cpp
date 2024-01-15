class Solution {
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k) {
	    int maxSize = 0;
	    int prefixSum = 0;
	    map<int, int> map;
	    
	    for(int i=0; i<n; i++) {
	        prefixSum += arr[i];
	        int reminder = prefixSum % k;
	        if(reminder < 0) {
	            reminder += k;
	        }
	        
	        if(reminder == 0) {
	            maxSize = max(maxSize, i+1);
	        }
	        if(map.count(reminder)) {
	            maxSize = max(maxSize, i - map[reminder]);
	        } else {
	            map[reminder] = i;
	        }
	    }
	    return maxSize;
	}
};