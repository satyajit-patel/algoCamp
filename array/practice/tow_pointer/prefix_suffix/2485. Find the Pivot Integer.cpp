/*
        Constraints:
        1 <= n <= 1000
        f(n) = O(n^2 logn)

        Input: n = 8
        Output: 6
        Explanation: 
        6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.
    */

    int pivotInteger(int n) {
        vector<int> prefixSum(n), suffixSum(n);
        int pSum = 0, sSum = 0;
        // O(n)
        for(int i=0; i<n; i++) {
            pSum += i+1;
            sSum += n-i;
            prefixSum[i] = pSum;
            suffixSum[n-i-1] = sSum;
        }

        // O(n)
        for(int i=0; i<n; i++) {
            if(prefixSum[i] == suffixSum[i]) {
                return i+1;
            }
        }
        // n + n = O(n)
        return -1;
    }