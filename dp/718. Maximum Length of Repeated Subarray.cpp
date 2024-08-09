class Solution {
public:
    /*
        Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
        Output: 3
        Explanation: The repeated subarray with maximum length is [3,2,1].
    */

    vector<int> a, b;
    int n, m;
    int maxi;
    vector<vector<int>> dp;

    int state(int i, int j) {
        // base case
        if(i >= n || j >=m) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // transition
        int take = 0;
        if(a[i] == b[j]) {
            take = 1 + state(i+1, j+1);
            maxi = std::max(maxi, take);
        }
        state(i+1, j);
        state(i, j+1);
        return dp[i][j] = take;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        a = nums1;
        b = nums2;
        n = a.size();
        m = b.size();
        dp.resize(n+1, vector<int>(m+1, -1));
        // longest common substring
        maxi = 0;
        int ans = state(0, 0);
        return maxi;
    }
};