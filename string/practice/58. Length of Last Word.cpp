/*
        Input: s = "   fly me   to   the moon  "
        Output: 4
        Explanation: 
        The last word is "moon" with length 4.
    */

    int lengthOfLastWord(string& s) {
        int ans = 0;

        int i = s.size() - 1;
        while(i>=0 && s[i] == ' ') {
            i--;
        }
        while(i>=0 && s[i] != ' ') {
            i--;
            ans++;
        }

        return ans;
    }