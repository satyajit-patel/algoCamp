/*
        Constraints:
        1 <= nums.length <= 12
        1 <= nums[i] <= 20

        f(n) = O(n^8)

        Input: nums = [1,3]
        Output: 6
        Explanation: The 4 subsets of [1,3] are:
        - The empty subset has an XOR total of 0.
        - [1] has an XOR total of 1.
        - [3] has an XOR total of 3.
        - [1,3] has an XOR total of 1 XOR 3 = 2.
        0 + 1 + 3 + 2 = 6
    */

    void state(int i, auto& nums, auto& temp, auto& subset) {
        // base case
        if(i >= nums.size()) {
            subset.push_back(temp);
            return;
        }

        // transition
        temp.push_back(nums[i]);
        state(i+1, nums, temp, subset);
        temp.pop_back();
        state(i+1, nums, temp, subset);
    }

    // void f(int i, vector<int>& nums, int currentXOR, int& totalXOR) {
    //     // base case
    //     if (i >= nums.size()) {
    //         totalXOR += currentXOR;
    //         return;
    //     }

    //     // transition: include nums[i] in the subset
    //     f(i + 1, nums, currentXOR ^ nums[i], totalXOR);
    //     // transition: exclude nums[i] from the subset
    //     f(i + 1, nums, currentXOR, totalXOR);
    // }

    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subset;
        vector<int> temp;
        state(0, nums, temp, subset);

        int ans = 0;
        for(auto& row: subset) {
            int sum = 0;
            for(auto& it: row) {
                cout<<it;
                sum ^= it;            
            }
            cout<<"->"<<sum<<endl;
            ans += sum;
        } 
        return ans;

        // int totalXOR = 0;
        // f(0, nums, 0, totalXOR);
        // return totalXOR;
    }