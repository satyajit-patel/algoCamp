class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0; // pointer to s
        int j = 0; // pointer to t
        while(i < s.size() && j < t.size()) {
            if(s[i] == t[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }

        int remainingSizeNeeded = (t.size()-1) - j + 1;
        return remainingSizeNeeded;
    }
};