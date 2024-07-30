class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<string> ans(n);

        vector<pair<int, string>> temp(n);
        for(int i=0; i<n; i++) {
            temp[i] = {heights[i], names[i]};
        }

        std::sort(temp.begin(), temp.end(), greater<pair<int, string>>());
        // std::sort(temp.begin(), temp.end());
        // std::reverse(temp.begin(), temp.end());

        for(int i=0; i<n; i++) {
            ans[i] = temp[i].second;
        }
        return ans;
    }
};