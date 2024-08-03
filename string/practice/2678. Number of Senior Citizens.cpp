class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;

        for(auto& it: details) {
            int n = it.size();
            int age = std::stoi(it.substr(n-4, 2));

            if(age > 60) {
                ans++;
            }
        }

        return ans;
    }
};