class Solution {
public:
    bool good(int mid, vector<int>& A, int n, int k) {
        int numOfCows = 1;
        int lastStall = A[0];
        for(int i=1; i<n; i++) {
            if(A[i] - lastStall >= mid) {
                numOfCows++;
                lastStall = A[i];
            }
        }
        return numOfCows >= k;
    }

    int solve(int n, int k, vector<int> &stalls) {
        int ans = -1;
        int lo = 0;
        int hi = INT_MAX;
        sort(stalls.begin(), stalls.end());
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(good(mid, stalls, n, k)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};
