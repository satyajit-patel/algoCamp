class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        map<char, int> mp;
        int init = 0;
        int n = s.size();

        /*
            "dvdf" => 3
            "abba" => 2
        */

        for(int i=0; i<n; i++) {
            if(mp.count(s[i])) {
                init = std::max(init, mp[s[i]]);
                // init = mp[s[i]]; // this will fail in "abba" => 2
            }

            ans = std::max(ans, i-init+1);

            mp[s[i]] = i+1;
        }

        return ans;
    }
};