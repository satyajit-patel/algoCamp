 /*
        Input: nums = [1,2,3,1,2,3,1,2], k = 2
        Output: 6
        Explanation: 
        The longest possible good subarray is [1,2,3,1,2,3] 
        since the values 1, 2, and 3 occur at most twice in this subarray. 
        Note that the subarrays [2,3,1,2,3,1] and [3,1,2,3,1,2] are also good.

        Constraints:
        1 <= nums.length <= 10^5
        1 <= nums[i] <= 10^9
        1 <= k <= nums.length

        f(n) = O(n logn)
    */

    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        map<int, int> mp;

        int init = 0;
        // O(n)
        for(int i=0; i<n; i++) {
            mp[nums[i]]++;

            while(mp[nums[i]] > k) {
                mp[nums[init]]--;
                init++;
            }

            ans = max(ans, i-init+1);
        }
        
        return ans;
    }