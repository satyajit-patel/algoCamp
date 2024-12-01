class Solution {
public:
    int inf = 1e7 + 1;
    vector<int> a;
    int c;
    int dp[100+10][100+10][100+10];
    int n;

    int state(int i, int j, int k) {
        // base case
        if(j < 0 || k < 0) {
            return inf;
        }
        if(i == n) {
            return 0;
        }
        if(dp[i][j][k] != -1) {
            return dp[i][j][k];
        }

        // transition
        int A = a[i];
        int B = 2;
        
        int doNothing = A + state(i+1, j, k);
        int oprOne = (A+B-1)/B + state(i+1, j-1, k);
        int oprTwo = (A >= c) ? A-c + state(i+1, j, k-1) : inf;
        int oprOneTwo = ((A+B-1)/B >= c) ? ((A+B-1)/B)-c + state(i+1, j-1, k-1) : inf;
        int oprTwoOne = (A >= c) ? ((A-c)+B-1)/B + state(i+1, j-1, k-1) : inf;

        // ans
        int ans = min({doNothing, oprOne, oprTwo, oprOneTwo, oprTwoOne});
        dp[i][j][k] = ans;
        return ans;
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        a.clear();
        a = nums;
        c = k;
        n = nums.size();

        memset(dp, -1, sizeof(dp)); // memset(pointer, value, size);
        int ans = state(0, op1, op2);
        return ans;
    }
};