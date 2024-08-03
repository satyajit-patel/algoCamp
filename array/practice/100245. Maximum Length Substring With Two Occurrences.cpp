/*
        Input: s = "bcbbbcba"
        Output: 4
        Explanation:
        The following substring has a length of 4 
        and contains at most two occurrences of each character: "bcbbbcba".
        
        Constraints:
        2 <= s.length <= 100
        s consists only of lowercase English letters.
        
        f(n) = O(n^4)
    */
    
    int maximumLengthSubstring(string s) {
        int i = 0;
        map<char, int> map;
        int ans = -1;
        // (n + n) * logn = O(n logn)
        for(int j=0; j<s.size(); j++) {
            map[s[j]]++;
            while(map[s[j]] > 2) {
                map[s[i]]--;
                if(map[s[i]] == 0) {
                    map.erase(map.find(s[i]));
                }
                i++;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }