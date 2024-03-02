/*
        Input: N = 5
        arr = {40, 20, 30, 10, 30}
        Output: 26000
        Explanation: There are 4 matrices of dimension 
        40x20, 20x30, 30x10, 10x30.
        A       B       C       D
    
        Constraints: 
        2 ≤ N ≤ 100
        1 ≤ arr[i] ≤ 500
        
        note :
            i <= k < j
            
            i >= j then 0
            else min(f(i, k) + f(k+1, j) + (a[i-1]*a[j]*a[k]))
            
            from above example
            k = (1->3)
            f(1, 1) + f(2, 4) i.e (A) (BCD)
            f(1, 2) + f(3, 4) i.e (AB) (CD)
            f(1, 3) + f(4, 4) i.e (ABC) (D)
            
    */
    
    int dp[101][101];
    int f(int i, int j, int* a) {
        // base case
        if(i >= j) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        // transition
        int mini = 1e9;
        for(int k=i; k<j; k++) {
            int cost = f(i, k, a) + f(k+1, j, a) + (a[i-1]*a[j]*a[k]);
            mini = min(mini, cost);
        }
        dp[i][j] = mini;
        return mini;
    }

    int matrixMultiplication(int N, int arr[]) {
        memset(dp, -1, sizeof dp); // memeset(startAddress, valueToBeFilled, size)
        int ans = f(1, N-1, arr);
        return ans;
    }