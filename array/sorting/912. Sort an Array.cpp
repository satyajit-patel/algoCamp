class Solution {
public:
    /*
        // g(n) = O(n logn)
    */

    void merge(vector<int>& nums, int startIndex, int mid, int endIndex) {
        int n1 = mid-startIndex+1;
        int n2 = endIndex-mid;
        vector<int> arr1(n1);
        vector<int> arr2(n2);

        for(int i=0; i<n1; i++) {
            arr1[i] = nums[startIndex + i];
        }
        for(int i=0; i<n2; i++) {
            arr2[i] = nums[(mid+1) + i];
        }

        vector<int> ans;
        int i = 0;
        int j = 0;

        while(i < n1 && j < n2) {
            if(arr1[i] <= arr2[j]) {
                ans.push_back(arr1[i++]);
            } else {
                ans.push_back(arr2[j++]);
            }
        }
        while(i < n1) {
            ans.push_back(arr1[i++]);
        }
        while(j < n2) {
            ans.push_back(arr2[j++]);
        }

        int ind = 0;
        for(int i=startIndex; i<=endIndex; i++) {
            nums[i] = ans[ind++];
        }
    }

    void state(int i, int j, vector<int>& nums) {
        // base case
        if(i >= j) {
            return;
        }

        // transition
        int mid = (i + j) / 2;
        state(i, mid, nums);
        state(mid+1, j, nums);

        merge(nums, i, mid, j);
    }

    vector<int> sortArray(vector<int>& nums) {
        // f(n) = O(n logn)
        int n = nums.size();
        state(0, n-1, nums); // merge sort
        return nums; 
    }
};