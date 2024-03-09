/*
        Input:
        s = "1010"
        r = 1
        n = 2
        Output:
        0
        Explanation : 
        After 1st iteration s becomes "10011001".
        Now, we can clearly see that the character 
        at 2nd index is 0, and so the output.
        
        Constraints:
        1 ≤ |s| ≤ 10^3
        1 ≤ r ≤ 20
        0 ≤ n < |s|
  */
  
    char nthCharacter(string& s, int r, int n) {
        for(int i=0; i<r; i++) {
            string temp = "";
            for(int j=0; j<s.size(); j++) {
                if(s[j] == '0') {
                    temp += "01";
                } else {
                    temp += "10";
                }
            }
            // s.clear(), s = temp; // TLE
            s = temp.substr(0, n+1); // as we onl need index till n
        }
        return s[n];
    }