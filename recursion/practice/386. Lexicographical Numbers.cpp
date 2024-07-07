class Solution {
public:
    void state(int i, int n, vector<int>& ans) {
        // base case
        if(i > n) {
            return;
        }

        // pre order
        ans.push_back(i);

        // transition
        for(int j = (i==0) ? 1 : 0; j <= 9; j++) {
            state((10*i)+j, n, ans);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        state(0, n, ans);
        ans.erase(ans.begin()+0);
        return ans;
    }
};