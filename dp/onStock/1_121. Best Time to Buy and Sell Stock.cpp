 /*
        Input: prices = [7,1,5,3,6,4]
        Output: 5

        Constraints:
        1 <= prices.length <= 10^5
        0 <= prices[i] <= 10^4

        expected f(n) = O(nlogn)
        our f(n) = O(n)
    */
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = INT_MAX;
        int leftMin[n];
        for(int i=0; i<n; i++) {
            // remembering the past
            mini = min(mini, prices[i]);
            leftMin[i] = mini;
        }

        int ans = INT_MIN;
        for(int i=0; i<n; i++) {
            int buy = leftMin[i];
            int sell = prices[i];
            int profit = sell - buy;
            
            ans = max(ans, profit);
        }
        return ans;
    }