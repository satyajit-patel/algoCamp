/*
        Input: nums = [1,2,3], k = 3
        Output: 2
    */

    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int sum = 0;
        int n = nums.size();
        map<int, int> mp;
        mp[sum]++;

        for(int i=0; i<n; i++) {
            sum += nums[i];

            int x = sum-k;
            if(mp.count(x)) {
                ans += mp[x];
            }

            mp[sum]++;
        }

        return ans;
    }