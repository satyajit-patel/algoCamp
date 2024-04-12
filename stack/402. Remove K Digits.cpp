/*
        Constraints:
        1 <= k <= num.length <= 10^5
        num consists of only digits.
        num does not have any leading zeros except for the zero itself.

        f(n) = O(n logn)

        Input: num = "1432219", k = 3
        Output: "1219"
        Explanation: 
        Remove the three digits 4, 3, and 2 to form 
        the new number 1219 which is the smallest.
    */

    string removeKdigits(string num, int k) {
        string ans = ""; // this will act as a monotonic increasing stack

        /*
            dry run
            1432219, k = 3

            1 push
            14 push
            13 pop k = 2
            12 pop k = 1
            122 push
            121 pop k = 0
            1219 push
        */ 

        int n = num.size();
        for(int i=0; i<n; i++) {
            while(!ans.empty() && num[i] < ans.back() && k) {
                ans.pop_back();
                k--;
            }

            // carefull about leading zeros
            if(!ans.empty() || num[i] != '0') {
                ans += num[i];
            }
            // cout<<ans<<"->"<<endl;
        }

        // suppose everything is in increasing form like 1234
        while(k-- && !ans.empty()) {
            ans.pop_back();
        }

        if(ans.empty()) {
            return "0";
        }

        
        return ans;
    }