class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // x ^ x = 0 i.e if even x -> 0
        // x ^ 0 = x i.e if odd x -> element inself
        int ans = 0;
        for(auto& it: nums) {
            ans ^= it;
        }
        return ans;
    }
};