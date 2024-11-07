class Solution {
public:
    /*
        Example 1:
        Input: s = "ababccc"
        Output: 5
        Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. 
        Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid 
        as you have 'a' and 'b' multiple times.
        Example 2:

        Input: s = "aba"
        Output: 2
        Explanation: One way to split maximally is ['a', 'ba'].
    */

    void f(int i, string& s, int curCount, int& maxCount, set<string> st) {
        // base case
        if(i >= s.size()) {
            maxCount = max(maxCount, curCount);
            return;
        }
        if(maxCount >= (curCount + s.size()-i)) { // pruning
            return;
        }

        // transition
        for(int ind=i; ind<s.size(); ind++) {
            string sub = s.substr(i, ind-i+1);
            if(st.find(sub) == st.end()) {
                st.insert(sub);
                f(ind+1, s, curCount + 1, maxCount, st);
                st.erase(sub);
            }
        }
    }

    int maxUniqueSplit(string s) {
        int maxCount = 0;
        set<string> st;
        f(0, s, 0, maxCount, st);
        return maxCount;
    }
};