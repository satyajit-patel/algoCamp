class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /*
            n/k = r1
            now
            (n + x)/k = r1 (if we get same reminder)
            then "x" must have been a dividend of "k"

            above was for divisible concept

            but here

            Input: nums = [1,1,1], k = 2
            Output: 2

            Input: nums = [1,2,3], k = 3
            Output: 2
    
            the intuition is: 
                let sum = x + k (and k is known to us)
                then x = sum - k

                it means if we have "sum" and we know "k" as well
                and somehow we get to know that we had "x" also then
                we will be sure that k = sum - x
                ex:
                                    8(sum)
                    ________________________________________ 
                            x(5)                k(3)
                    ______________________-------------------

                    now we know 8
                    and if we get to know that we had 5 previously then
                    k = 8 - 5
                    k = 3
                    i.e we will be confirm taht k is what we think it is.. that is 3
        */
        int ans = 0;

        int sum = 0;
        map<int, int> mp;
        mp[sum]++;

        for(auto& it: nums) {
            sum += it;

            // sum = x - k
            int x = sum - k;
            if(mp.count(x)) {
                ans += mp[x];
            }
            mp[sum]++;
        }

        return ans; 
    }
};