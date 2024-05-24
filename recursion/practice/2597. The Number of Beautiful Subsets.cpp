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

    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> temp;
        vector<vector<int>> subset;
        state(0, nums, temp, subset);
        int ans = 0;
        for(auto& row: subset) {
            if(row.empty()) {
                continue;
            }
            bool good = true;
            for(int i=0; i<row.size(); i++) {
                for(int j=i+1; j<row.size(); j++) {
                    if(abs(row[i]-row[j]) == k) {
                        good = false;
                        break;
                    }
                }
                if(!good) {
                    break;
                }
            }
            if(good) {
                ans++;
            }
        }
        return ans;
    }