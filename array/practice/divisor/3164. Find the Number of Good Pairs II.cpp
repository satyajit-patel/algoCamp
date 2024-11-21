class Solution {
public:
    /*
        divisor  - an ele which divides another ele
        dividend - an ele which gets divided by another ele 
        1 <= n <= 1e5
        g(n) = O(nlogn)
        f(n) = O(nlogn)

        Input: nums1 = [1,2,4,12], nums2 = [2,4], k = 3
        Output: 2
        Explanation:
        The 2 good pairs are (3, 0) and (3, 1). // 0 based indexing

        dry run
	nums2 =[(2*k), (4*k)]
        now in nums1
        12 is divisible by 6 (3, 0)
        12 is divisible by 12 (3 1)

        i.e. nums2 becomes nums2[6, 12]
        now we have to find the another numbers which gets divided by nums2[i]
        like for 6 -> 6, 12 18, 24, 30... (so for all this num.. 6 is divisor)
    */

    int mp[1000000+1];
    int dividend[1000000+1];
    void preCompute(vector<int>& nums, int k) {
        for(auto& it: nums) {
            int nit = it * k;
            if(nit <= 1000000) {
                mp[nit]++;
            }
        }
        /*
            mp[6] = 1;
            mp[12] = 1
        */

        // sieve method
        for(int i=1; i<=1000000; i++) {
            int freq = mp[i];
            if(freq >= 1) {
                for(int j=i; j<=1000000; j+=i) {
                    dividend[j] += freq;
                }
            }
        }
        /*
            dividend[6]  = 1
            dividend[12] = 2
            dividend[18] = 1
            dividend[24] = 2
            dividend[30] = 1
            .
            .
        */
    }

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0;
        preCompute(nums2, k);
        for(auto& it: nums1) {
            ans += dividend[it];
        }
        return ans;
    }
};