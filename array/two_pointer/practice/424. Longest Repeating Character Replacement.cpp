class Solution {
public:
    // "ABCDE" => 2
    int characterReplacement(string& s, int k) {
        int maxi = 0;
        int n = s.size();
        int left = 0;
        int maxFreq = 0;
        map<char, int> mp;

        for(int right=0; right<n; right++) {
            mp[s[right]]++;
            maxFreq = std::max(maxFreq, mp[s[right]]);

            while((right-left+1) - maxFreq > k) {
                mp[s[left]]--;
                left++;
                // update the maxFrq again
                maxFreq = 0;
                for(auto& it: mp) {
                    maxFreq = std::max(maxFreq, it.second);
                }
            }

            maxi = std::max(maxi, (right-left+1));
        }

        return maxi;
    }
};