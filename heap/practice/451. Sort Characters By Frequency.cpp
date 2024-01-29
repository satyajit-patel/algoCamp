class Solution {
public:
    string frequencySort(string& s) {
        map<char, int> map;
        for(auto& it: s) {
            map[it]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto& it: map) {
            pq.push({it.second, it.first});
        }
        string ans = "";
        while(!pq.empty()) {
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            while(freq--) {
                ans += ch;
            }
        }
        return ans;
    }
};