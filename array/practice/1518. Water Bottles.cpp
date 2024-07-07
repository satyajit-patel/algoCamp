class Solution {
public:
    int numWaterBottles(int n, int k) {
        int ans = n;
        while(n >= k) {
            int extra =  (n / k);
            ans += extra;
            n %= k;
            n += extra;
        }
        return ans;
    }
};