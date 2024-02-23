/*
        Input:
        N = 7, x = 5 
        arr[] = {1,2,8,10,11,12,19}
        Output: 1
        Explanation: Largest Number less than 5 is
        2 (i.e K = 2), whose index is 1(0-based 
        indexing)
    */
    
    int findFloor(vector<long long> v, long long n, long long x) {
        int ans = -1;
        int lo = 0, hi = n-1;
        while(lo <= hi) {
            int mid = (lo+hi)/2;
            if(v[mid] <= x) {
                ans = mid;
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        return ans;
    }