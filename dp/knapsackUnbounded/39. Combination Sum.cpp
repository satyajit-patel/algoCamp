class Solution {
public:
    vector<int> A;
    vector<vector<int>> ans;

    void state(int i, vector<int> temp, int target) {
        // base case
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        if(target < 0) {
            return;
        }
        if(i >= A.size()) {
            return;
        }

        // transition
        temp.push_back(A[i]);
        state(i, temp, target-A[i]);
        temp.pop_back();
        state(i+1, temp, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        A.clear(), A = candidates;
        ans.clear();
        state(0, {}, target);
        return ans;
    }
};