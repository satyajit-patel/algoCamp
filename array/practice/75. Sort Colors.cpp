class Solution {
public:
    void dnf(vector<int>& nums) {
        // dnf is known as
        // dutch national flag algorithm
        // it was proposed by dijkstra
        // the flag of netherlands consists 3 color 
        // so its about that may be
        int i = 0, k = 0, j = nums.size()-1;
        while(k <= j) {
            if(nums[k] == 0) {
                swap(nums[k], nums[i]);
                i++;
                k++;
            }
            else if(nums[k] == 2) {
                swap(nums[k], nums[j]);
                j--;
            }
            else {
                k++;
            }
        }
    }

    void sortColors(vector<int>& nums) {
        dnf(nums);
    }
};