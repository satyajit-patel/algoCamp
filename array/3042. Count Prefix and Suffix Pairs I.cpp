/*
        Input: words = ["a","aba","ababa","aa"]
        Output: 4
        Explanation: In this example, the counted index pairs are:
        i = 0 and j = 1 because isPrefixAndSuffix("a", "aba") is true.
        i = 0 and j = 2 because isPrefixAndSuffix("a", "ababa") is true.
        i = 0 and j = 3 because isPrefixAndSuffix("a", "aa") is true.
        i = 1 and j = 2 because isPrefixAndSuffix("aba", "ababa") is true.
        Therefore, the answer is 4.
        
        Constraints:

        1 <= words.length <= 50
        1 <= words[i].length <= 10
        words[i] consists only of lowercase English letters.
        
        f(n) = O(n^8)
    */
    
    int countPrefixSuffixPairs(vector<string>& words) {
        int c = 0;
        int n = words.size();
        // f(n) = O(n^3)
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                string prev = words[i];
                string next = words[j];
                if(prev.size() > next.size()) {
                    continue;
                }
                
                bool prefix = true, suffix = true;
                for(int k=0; k<prev.size(); k++) { 
                    if(prev[k] != next[k]) {
                        prefix = false;
                    }
                    if(prev[prev.size()-k-1] != next[next.size()-k-1]) {
                        suffix = false;
                    }
                }
                if(prefix && suffix) {
                    c++;
                }
            }
        }
        return c;
    }