/*
        Input: s = "egg", t = "add"
        Output: true

        Input: s = "foo", t = "bar"
        Output: false

        Constraints:
        1 <= s.length <= 5 * 10^4
        t.length == s.length
        s and t consist of any valid ascii character.
    */

    bool isIsomorphic(string s, string t) {
        int n = s.size();

        map<char, char> mapST, mapTS;
        for(int i=0; i<n; i++) {
            char ch1 = s[i];
            char ch2 = t[i];

            if(mapST.count(ch1) && mapST[ch1] != ch2) {
                return false;
            }
            if(mapTS.count(ch2) && mapTS[ch2] != ch1) {
                return false;
            }

            mapST[ch1] = ch2;
            mapTS[ch2] = ch1;
        }

        return true;
    }