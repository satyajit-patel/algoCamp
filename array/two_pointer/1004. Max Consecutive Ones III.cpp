/*
        Constraints:
        1 <= nums.length <= 105
        nums[i] is either 0 or 1.
        0 <= k <= nums.length

        Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
        Output: 6
    */

    int longestOnes(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        int n = nums.size();

        int zero = 0;
        int init = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == 0) {
                zero++;
            }

            while(zero > k) {
                if(nums[init] == 0) {
                    zero--;
                }
                init++;
            }

            maxi = max(maxi, i-init+1);
        }

        return maxi;
    }