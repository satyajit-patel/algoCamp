class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int sum = 0;
        unordered_map<int, int> map;
        map[0]++;
        for(auto& it: nums) {
            // update
            sum += it;

            // work
            if(map.count(sum-k)) {
                ans += map[sum-k];
            }
            
            // insert
            map[sum]++;
        }
        return ans;
    }
};