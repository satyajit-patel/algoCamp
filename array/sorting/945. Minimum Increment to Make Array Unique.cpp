class Solution {
public:
    /*
        [3,2,1,2,1,7]
        [1,1,2,2,3,7]

        [1]
        [1,2] (1-1)+1 moves i.e (nums[i-1] - nums[i]) + 1 if(nums[i] >= nums[i-1])
        [1,2,3] (2-2)+1 moves
        [1,2,3,4] (3-2)+1 moves
        [1,2,3,4,5] (4-3)+1 moves
        [1,2,3,4,5,7]
    */

    int minIncrementForUnique(vector<int>& nums) {
        int moves = 0;

        // // TLE
        // set<int> st;
        // for(auto& it: nums) {
        //     while(st.find(it) != st.end()) {
        //         it++;
        //         moves++;
        //     }
        //     st.insert(it);
        // }

        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++) {
            if(nums[i-1] >= nums[i]) {
                moves += (nums[i-1] - nums[i] + 1);
                nums[i] = nums[i-1] + 1;
            }
        }

        return moves;
    }
};