 /*
        Constraints:
        1 <= s.length <= 100
        s consists only of lowercase English letters.
        
        expected
        f(n) = O(n^4)
        
        Input: s = "leetcode"
        Output: true
        Explanation: 
        Substring "ee" is of length 2 which is also present in reverse(s) == "edocteel".
    */
    
    bool isSubstringPresent(string& s) {
        string rev = s;
        reverse(s.begin(), s.end());
        
        // sliding window
        int i = 0;
        int j = 0;
        string temp = "";
        while(j < 2) {
            temp += s[j];
            j++;
        }
        if(s.find(temp.substr(i, 2)) != -1 && rev.find(temp.substr(i, 2)) != -1) {
            return true;
        }
        //  n * n = O(n^2)
        while(j < s.size()) {
            temp += s[j];
            i++;
            // O(n)
            if(s.find(temp.substr(i, 2)) != -1 && rev.find(temp.substr(i, 2)) != -1) {
                return true;
            }
            j++;
        }
        
        return false;
    }