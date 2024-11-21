class Solution {
public:
// https://leetcode.com/contest/weekly-contest-424/problems/zero-array-transformation-i/description/
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> ps(n + 1, 0);
        for(auto& it: queries) {
            ps[it[0]] += 1;
            ps[it[1] + 1] -= 1;
        }
        for(int i=0; i<n; i++) {
            if(i > 0) {
                ps[i] += ps[i-1];
            }
            // cout << ps[i] << " ";
            if(ps[i] < nums[i]) {
                return false;
            }
        }
        return true;
    }
};