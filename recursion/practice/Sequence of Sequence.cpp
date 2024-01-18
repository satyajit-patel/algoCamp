class Solution {
public:
    int N, M;

    int state(int i, int val) {
        // base case
        if(i >= N) {
            return 1;
        }
        if(val > M) {
            return 0;
        }
        
        // transition
        int take = state(i+1, val*2);
        int notTake = state(i, val+1);
        int ans = take + notTake;
        return ans;
    }

    int numberSequence(int m, int n) {
        M = m, N = n;
        int ans = state(0, 1);
        return ans;
    }
};