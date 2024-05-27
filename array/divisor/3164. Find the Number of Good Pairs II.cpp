/*
        Constraints:
        1 <= n, m <= 10^5
        1 <= nums1[i], nums2[j] <= 10^6
        1 <= k <= 10^3

        f(n) = O(n logn)

        Input: nums1 = [1,2,4,12], nums2 = [2,4], k = 3
        Output: 2
        Explanation:
        The 2 good pairs are (3, 0) and (3, 1).
    */

    int maxi = 1000000;
    int freq[1000000+1];
    int divisor_count[1000000+1];

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        for(int i=0; i<nums2.size(); i++) {
            int ele = nums2[i] * k;
            if(ele <= maxi) {
                freq[ele]++;
            }
        }

        // sieve method
        for(int ele=1; ele<=maxi; ele++) {
            int freqCount = freq[ele];
            if(freqCount >= 1) {
                for(int i=ele; i<=maxi; i+=ele) {
                    divisor_count[i] += freqCount;
                }
            }
        }

        long long ans = 0;
        for(auto& it: nums1) {
            ans += divisor_count[it];
        }
        return ans;
    }