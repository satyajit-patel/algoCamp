/*
        Input: nums = [2,1,3,4], k = 1
        Output: 2
    */

    int minOperations(vector<int>& nums, int k) {
        int totalXor = 0;
        for(auto& it: nums) {
            totalXor ^= it;
        }
        int diff = totalXor ^ k;
        return __builtin_popcount(diff);
    }