struct compClass {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if(a.first == b.first) {
            // big value at front
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> mp;
        for(auto& it: nums) {
            mp[it]++;
        }

        vector<pair<int, int>> arr; // freq, ele
        for(auto& it: mp) {
            arr.push_back({it.second, it.first});
        }

        std::sort(arr.begin(), arr.end(), compClass());

        vector<int> ans;
        for(auto& it: arr) {
            int freq = it.first;
            int value = it.second;
            while(freq--) {
                ans.push_back(value);
            }
        }

        return ans;
    }
};