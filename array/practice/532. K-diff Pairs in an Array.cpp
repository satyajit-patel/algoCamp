class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        // 1 <= n <= 1e4
        // expected TC O(N^2)

        int n = nums.size();
        int ans = 0;

        // // nlogn + (n * (2n)) = O(n^2)
        // sort(nums.begin(), nums.end());
        // for(int i=0; i<n; i++) {
        //     for(int j=i+1; j<n; j++) {
        //         int diff = abs(nums[i]-nums[j]);
        //         if(diff == k) {
        //             ans++;
        //         }
        //         // skiping the duplicates
        //         while(j+1<n && nums[j+1]==nums[j]) {
        //             j++;
        //         }
        //     }
        //     // skiping the duplicates
        //     while(i+1<n && nums[i+1]==nums[i]) {
        //         i++;
        //     }
        // }

        // nlogn + 2n = O(nlogn)
        sort(nums.begin(), nums.end());
        int left = 0, right = 1;
        while(left<n && right < n) {
            int diff = nums[right]-nums[left];
            if(left==right || diff < k) {
                right++;
            }
            else if(diff > k) {
                left++;
            }
            else {
                ans++;
                left++;
                while(left<n && nums[left]==nums[left-1]) {
                    left++;
                }
            }
        }

        return ans;
    }
};