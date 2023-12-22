class Solution {
public:
    int lengthOfLongestSubstring(string& s) {
        int n = s.size();
        int ans = 0;

        // optimized sliding window using hashing
        unordered_map<char, int> map;
        for(int i=0, j=0; j<n; j++) {
            // update
            if(map.count(s[j])) {
                i = max(map[s[j]], i);
            }

            // work
            int unique_window_size = j-i+1;
            ans = max(ans, unique_window_size);

            // insert
            map[s[j]] = j+1;
        }

        return ans;
    }
};