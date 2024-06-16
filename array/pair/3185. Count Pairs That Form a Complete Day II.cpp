class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans = 0;
        map<int, long long> mp;

        for(int i=0; i<hours.size(); i++) {
            int x = (24 - (hours[i]%24)) % 24;
            ans += mp[x];
            mp[hours[i]%24]++;
        }

        return ans;
    }
};