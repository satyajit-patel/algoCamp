 /*
        Constraints:
        1 <= n == happiness.length <= 2 * 10^5
        1 <= happiness[i] <= 10^8
        1 <= k <= n
        
        Input: happiness = [1,2,3], k = 2
        Output: 4
        Explanation: We can pick 2 children in the following way:
        - Pick the child with the happiness value == 3. 
        The happiness value of the remaining children becomes [0,1].
        - Pick the child with the happiness value == 1. 
        The happiness value of the remaining child becomes [0]. 
        Note that the happiness value cannot become less than 0.
        The sum of the happiness values of the selected children is 3 + 1 = 4.
    */
    
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        
        sort(happiness.begin(), happiness.end());
        reverse(happiness.begin(), happiness.end());
        
        for(int i=0; i<k; i++) {
            ans += max(0, happiness[i] - i);
        }
        return ans;
    }