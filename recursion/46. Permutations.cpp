class Solution {
public:
    /*
        Input: nums = [1,2,3]
        Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
    */

    void state(auto& nums, auto& temp, auto& mp, auto& ans) {
        // base case
        if(temp.size() >= nums.size()) {
            ans.push_back(temp);
            return;
        }

        // transition
        for(int i=0; i<nums.size(); i++) {
            if(!mp[i]) {
                mp[i] = true;
                temp.push_back(nums[i]);
                state(nums, temp, mp, ans);
                temp.pop_back();
                mp[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        // std::sort(nums.begin(), nums.end());
        // do {
        //     ans.push_back(nums);
        // } while(std::next_permutation(nums.begin(), nums.end()));
        

        vector<int> temp;
        map<int, bool> mp;
        state(nums, temp, mp, ans);

        return ans;
    }
};