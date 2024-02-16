/*
    Input: nums = [1,2,3], k = 3
    Output: 2
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        map<int, int> map;
        int prefixSum = 0;
        map[prefixSum]++;
        for(auto& it: nums) {
            prefixSum += it;
            if(map.find(prefixSum-k) != map.end()) {
                ans += map[prefixSum-k];
            }
            map[prefixSum]++;
        }
        return ans;
    }
};