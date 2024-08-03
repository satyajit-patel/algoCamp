/*
        Constraints:
        1 <= nums.length <= 3 * 104
        nums[i] is either 0 or 1.
        0 <= goal <= nums.length

        Input: nums = [1,0,1,0,1], goal = 2
        Output: 4
        Explanation: 
        The 4 subarrays are bolded and underlined below:
        [1,0,1,0,1]
        [1,0,1,0,1]
        [1,0,1,0,1]
        [1,0,1,0,1]
    */

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int ans = 0;

        // // O(n^2) TLE
        // for(int i=0; i<n; i++) {
        //     int sum = 0;
        //     for(int j=i; j<n; j++) {
        //         sum += nums[j];
        //         if(sum == goal) {
        //             ans++;
        //         }
        //     }
        // }

        // O(n)
        map<int, int> map;
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];

            if(sum == goal) {
                ans++;
            }
            if(map.find(sum - goal) != map.end()) {
                ans += map[sum - goal];
            }

            map[sum]++;
        }

        return ans;
    }