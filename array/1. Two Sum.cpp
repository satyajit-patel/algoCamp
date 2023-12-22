class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 1 <= n <= 1e4 so O(n^2) could work
        int n = nums.size();
        multimap<int, int> map;
        for(int i=0; i<n; i++) {
            map.insert({nums[i], i});
        }
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) {
            // nums[i] + x = target
            int x = target - nums[i];
            if(binary_search(nums.begin()+i+1, nums.end(), x)) {
                vector<int> ans;
                auto it = map.find(nums[i]);
                ans.push_back(it->second);
                map.erase(it);
                it = map.find(x);
                ans.push_back(it->second);
                return ans;
            }
        }
        return {-1, -1};
    }
};