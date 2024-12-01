class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.size();
        int x = n / k;
        
        if(n%x != 0) {
            return false;
        }

        map<string, int> mp;
        for(int i=0; i<n; i+=x) {
            mp[s.substr(i, x)]++;
            mp[t.substr(i, x)]--;
        }
        for(auto& it: mp) {
            if(it.second != 0) {
                return false;
            }
        }
        return true;
    }
};