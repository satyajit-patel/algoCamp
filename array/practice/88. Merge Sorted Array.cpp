class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        vector<int> A;
        while(i < m && j < n) {
            if(nums1[i] <= nums2[j]) {
                A.push_back(nums1[i]);
                i++;
            }
            else {
                A.push_back(nums2[j]);
                j++;
            }
        }
        while(i < m) {
            A.push_back(nums1[i]);
            i++;
        }
        while(j < n) {
            A.push_back(nums2[j]);
            j++;
        }
        nums1.clear();
        nums1 = A;
    }
};