class comp {
public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if(a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b. first;
    }
};
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> newNums(n);
        for(int i=0; i<n; i++) {
            string s = std::to_string(nums[i]);
            string newS = "";
            for(auto& it: s) {
                newS += ((mapping[it - '0']) + '0');
            }
            int num = std::stoi(newS);
            // cout<<num<<" ";
            newNums[i] = {num, i};
        }
        // std::sort(newNums.begin(), newNums.end(), comp()); // no need
        std::sort(newNums.begin(), newNums.end());
        vector<int> ans;
        for(auto& it: newNums) {
            int index = it.second;
            ans.push_back(nums[index]);
        }
        return ans;
    }
};