class Solution {
public:
    /*
        1 <= n <= 1e3
        g(n) = O(n^2 logn)
    */

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        std::sort(nums.begin(), nums.end());

        // // f(n) = O(n^2 logn)
        // set<vector<int>> st;
        // for(int i=0; i<nums.size(); i++) {
        //     for(int j=i+1; j<nums.size(); j++) {
        //         // nums[i] + nums[j] + x == 0
        //         int x = -(nums[i] + nums[j]);
        //         if(std::binary_search(nums.begin()+j+1, nums.end(), x)) {
        //             st.insert({nums[i], nums[j], x});
        //         }
        //     } 
        // }
        // for(auto& it: st) {
        //     ans.push_back(it);
        // }

        // // f(n) = O(n^2)
        // set<vector<int>> st;
        // for(int i=0; i<nums.size(); i++) {
        //     int j = i+1;
        //     int k = nums.size() - 1;
        //     while(j < k) {
        //         int sum = nums[i] + nums[j] + nums[k];
        //         if(sum == 0) {
        //             st.insert({nums[i], nums[j], nums[k]});
        //             j++;
        //             k--;
        //         } else if(sum < 0) {
        //             j++;
        //         } else {
        //             k--;
        //         }
        //     }
        // }
        // for(auto& it: st) {
        //     ans.push_back(it);
        // }

        // f(n) = O(n^2 logn)
        for(int i=0; i<nums.size(); i++) {
           for(int j=i+1; j<nums.size(); j++) {
                // nums[i] + nums[j] + x == 0
                int x = -(nums[i] + nums[j]);
                if(std::binary_search(nums.begin()+j+1, nums.end(), x)) {
                    ans.push_back({nums[i], nums[j], x});
                    while(j+1 < nums.size() && nums[j+1] == nums[j]) {
                        j++;
                    }
                }
           }
           while(i+1 < nums.size() && nums[i+1] == nums[i]) {
                i++;
           }
        }

        return ans;
    }
};