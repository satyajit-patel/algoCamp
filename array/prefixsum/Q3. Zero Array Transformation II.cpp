class Solution {
public:
// https://leetcode.com/contest/weekly-contest-424/problems/zero-array-transformation-ii/
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries, int mid) {
        int n = nums.size();
        vector<int> ps(n + 1, 0);
        for(int i=0; i<mid; i++) {
            ps[queries[i][0]] += queries[i][2];
            ps[queries[i][1] + 1] -= queries[i][2];
        }
        for(int i=0; i<n; i++) {
            ps[i + 1] += ps[i];
            // cout << ps[i] << " ";
            if(ps[i] < nums[i]) {
                return false;
            }
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int i = 0, j = queries.size(), ans = -1;
        while(i <= j) {
            int mid = (i + j) / 2;
            if(isZeroArray(nums, queries, mid)) {
                ans = mid;
                // look for more small
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return ans;
    }
};