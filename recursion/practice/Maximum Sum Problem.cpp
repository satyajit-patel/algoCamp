// https://www.geeksforgeeks.org/problems/maximum-sum-problem2211/1 
        int state(int n) {
            // base case
            if(n == 0) {
                return 0;
            }
            if(n == 1) {
                return 1;
            }
            
            // transition
            int case1 = state(n/2);
            int case2 = state(n/3);
            int case3 = state(n/4);
            int ans = max(n, case1+case2+case3);
            return ans;
        }
    
        int maxSum(int n) {
            int ans = state(n);
            return ans;
        }