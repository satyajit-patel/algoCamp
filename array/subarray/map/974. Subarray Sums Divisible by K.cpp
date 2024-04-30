/*
        Constraints:
        1 <= nums.length <= 3 * 10^4
        -10^4 <= nums[i] <= 10^4
        2 <= k <= 10^4

        f(n) = O(n logn), close to O(n^2) yet not n^2

        Input: nums = [4,5,0,-2,-3,1], k = 5
        Output: 7
        Explanation: 
        There are 7 subarrays with a sum divisible by k = 5:
        [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
    */

    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();

        // // O(n^2) TLE 70/73
        // for(int i=0; i<n; i++) {
        //     int sum = 0;
        //     for(int j=i; j<n; j++) {
        //         sum += nums[j];
        //         if(sum % k == 0) {
        //             ans++;
        //         }
        //     }
        // }

        int sum = 0;
        map<int, int> mp;
        mp[sum]++;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            int rem = sum % k;

            // edge case
            if(rem < 0) {
                rem += k;
            }
            
            if(mp.count(rem)) {
                ans += mp[rem];
            }

            mp[rem]++;
        }

        return ans;
    }