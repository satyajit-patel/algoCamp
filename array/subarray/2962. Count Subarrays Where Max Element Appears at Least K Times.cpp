/*
        Input: nums = [1,3,2,3,3], k = 2
        Output: 6
        Explanation: 
        The subarrays that contain the element 3 at least 2 times are: 
        [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].

        Constraints:
        1 <= nums.length <= 10^5
        1 <= nums[i] <= 10^6
        1 <= k <= 10^5

        f(n) = O(n logn)
    */

    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        
        // O(n)
        int maxi = *max_element(nums.begin(), nums.end());
        int count = 0;
        int init = 0;
        // O(n)
        for(int i=0; i<n; i++) {
            if(nums[i] == maxi) {
                count++;
            }

            while(count >= k) {
                ans += n - i;
                if(nums[init] == maxi) {
                    count--;
                }
                init++;
            }
        }

        // n + n = O(n)
        return ans;
    }