class Solution {
public:
    vector<vector<pair<string, int>>> dp;

    pair<string, int> state(int i, int j, int* p) {
        //base case
        if(i >= j) {
            char ch = 'A' + (i-1);
            string s = "";
            s += ch;
            return {s, 0};
        }
        if(dp[i][j].second != -1) {
            return dp[i][j];   
        }
        
        // transition
        int mini = INT_MAX;
        string s = "";
        for(int k=i; k<j; k++) {
            pair<string, int> left = state(i, k, p);
            pair<string, int> right = state(k+1, j, p);
            int cost = (p[i-1] * p[j]) * p[k];
            int total = left.second + right.second + cost;
            if(total < mini) {
                string temp = "(" + left.first + right.first + ")";
                mini = total;
                s = temp;
            }
        }
        pair<string, int> ans = {s, mini};
        dp[i][j] = ans;
        return ans;
    }
    
    string matrixChainOrder(int p[], int n){
        dp.resize(n+1, vector<pair<string, int>>(n+1, {"", -1}));
        string ans = state(1, n-1, p).first;
        return ans;
    }
};