class Solution {
public:
    bool canPair(vector<int> nums, int k) {
        if(nums.size() % 2 == 1) {
            return false;
        }
        vector<int> arr(k+1, 0);
        for(auto& it: nums) {
            int boy = it % k;
            arr[boy]++; // if boy is available
            int girl = k - boy;
            arr[girl]--; // then reserved the girl for him
        }
        for(int boy=1; boy<k; boy++) {
            if(arr[boy] != 0) {
                return false;
            }
        }
        return true;
    }
};