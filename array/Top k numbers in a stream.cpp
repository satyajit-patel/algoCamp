class Solution {
public:
    struct comp {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        }
    };

    vector<vector<int>> kTop(vector<int>& arr, int n, int k) {
        vector<vector<int>> result;
        map<int, int> freqMap;
        set<pair<int, int>, comp> freqSet;
    
        for (int i = 0; i < n; ++i) {
            int num = arr[i];
            auto it = freqSet.find({num, freqMap[num]});
            if (it != freqSet.end()) {
                freqSet.erase(it);
            }
            freqMap[num]++;
            freqSet.insert({num, freqMap[num]});
            vector<int> temp;
            for(auto it=freqSet.begin(); it!=freqSet.end() && temp.size()<k; it++) {
                temp.push_back(it->first);
            }
            result.push_back(temp);
        }
        return result;
    }
};