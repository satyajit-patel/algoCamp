/*
        Constraints:
        1 <= nums.length <= 10
        -10 <= nums[i] <= 10
        All the numbers of nums are unique.

        f(n) = O(n^8)
        2^n will still be 1024 i.e 10^3

        Input: nums = [0]
        Output: [[],[0]]    
    */

    void state(int i, auto& nums, auto& temp, auto& ans) {
        // base case
        if(i >= nums.size()) {
            ans.push_back(temp);
            return;
        }

        // transition
        temp.push_back(nums[i]);
        state(i+1, nums, temp, ans);
        temp.pop_back();
        state(i+1, nums, temp, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        state(0, nums, temp, ans);
        return ans;
    }