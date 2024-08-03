/*
        Input: nums1 = [1,2,3], nums2 = [2,4]
        Output: 2

        Constraints:
        1 <= nums1.length, nums2.length <= 10^5
        1 <= nums1[i], nums2[j] <= 10^9
        Both nums1 and nums2 are sorted in non-decreasing order.
    */

    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int i = 0;
        int j = 0;
        while(i < n && j < m) {
            if(nums1[i] == nums2[j]) {
                return nums1[i];
            } else if(nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return -1;
    }