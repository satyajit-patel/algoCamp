class Solution {
public:
    string reorganizeString(string& s) {
        map<char, int> mp;
        for(auto& it : s) {
            mp[it]++;
        }
        
        priority_queue<pair<int, char>, vector<pair<int, char>>> maxHeap;
        for(auto& it : mp) {
            maxHeap.push({it.second, it.first});
        }

        std::string ans = "";
        while(maxHeap.size() >= 2) {
            int freq1 = maxHeap.top().first;
            char ch1 = maxHeap.top().second;
            maxHeap.pop();

            int freq2 = maxHeap.top().first;
            char ch2 = maxHeap.top().second;
            maxHeap.pop(); 

            ans += ch1;
            ans += ch2;
            freq1--;
            freq2--;

            if(freq1 > 0) {
                maxHeap.push({freq1, ch1});
            }
            if(freq2 > 0) {
                maxHeap.push({freq2, ch2});
            }
        }
        if(!maxHeap.empty()) {
            char ch = maxHeap.top().second;
            int freq = maxHeap.top().first;
            maxHeap.pop();

            if(freq == 1) {
                ans += ch;
            } else {
                return "";
            }
        }

        return ans;
    }
};