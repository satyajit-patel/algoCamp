/*
        Input: s = "abBAcC"
        Output: ""
        Explanation: 
        We have many possible scenarios, 
        and all lead to the same answer. For example:
        "abBAcC" --> "aAcC" --> "cC" --> ""
        "abBAcC" --> "abBA" --> "aA" --> ""

        Constraints:
        1 <= s.length <= 100
        s contains only lower and upper case English letters.
    */

    bool issame(char small_letter, char capital_letter) {
        if(capital_letter >= 'A' && capital_letter <= 'Z') {
            capital_letter = tolower(capital_letter);
            return small_letter == capital_letter;
        }
        return false;
    }

    string makeGood(string s) {
        // cout<<s<<endl;
        while(1) {
            bool flag = false;
            for(int i=0; i<s.size(); i++) {
                if(i+1 < s.size() && (issame(s[i], s[i+1]) || issame(s[i+1], s[i]))) {
                    flag = true;
                    s.erase(i, 2);
                    // break;
                }
            }
            if(!flag) {
                break;
            }
            // cout<<s<<endl;
        }

        return s;
    }