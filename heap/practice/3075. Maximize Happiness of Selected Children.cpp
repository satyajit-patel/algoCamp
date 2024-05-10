/*
        Constraints:
        1 <= n == happiness.length <= 2 * 10^5
        1 <= happiness[i] <= 10^8
        1 <= k <= n

        Input: happiness = [1,2,3], k = 2
        Output: 4
    */

    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        sort(happiness.begin(), happiness.end());
        reverse(happiness.begin(), happiness.end());
        int opr = 0;
        for(int i=0; i<happiness.size() && i<k; i++) {
            opr++;
            long long calc = max(happiness[i]-i, 0);
            // if(calc == 0) {
            //     break;
            // }
            ans += calc;
        }
        cout<<opr<<endl;
        return ans;
    }