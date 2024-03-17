 /*
        Constraints:
        1 <= s.length <= 10^5
        s and c consist only of lowercase English letters.
        
        f(n) = O(n logn)
        
        Input: s = "abada", c = "a"
        Output: 6
        Explanation: 
        Substrings starting and ending with "a" are: 
        "a", "aba", "abada", "a", "ada", "a".
    */
    
    long long countSubstrings(string& s, char c) {
        long long count = 0;
        
//         // O(n^2) TLE
//         for(int i=0; i<s.size(); i++) {
//             // optimization
//             if(s[i] != c) {
//                 continue;
//             }
            
//             string temp = "";
//             for(int j=i; j<s.size(); j++) {
//                 temp += s[j];
//                 if(temp[0] == c && temp[temp.size()-1] == c) {
//                     count++;
//                 }
//             }
//         }
        
        // O(n)
        long long num_substring_tillThisPoint = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == c) {
                num_substring_tillThisPoint++;
                count += num_substring_tillThisPoint;
            }
        }
        
        return count;
    }