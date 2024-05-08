/*
        A word is considered valid if:
        It contains a minimum of 3 characters.
        It consists of the digits 0-9, and the uppercase and lowercase English letters. (Not necessary to have all of them.)
        It includes at least one vowel.
        It includes at least one consonant.
    */
    
    bool isvowel(char ch) {
        ch = tolower(ch);
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'; 
    }
    
    bool isValid(string word) {
        int n = word.size();
        if(n < 3) {
            return false;
        }
        bool v = false;
        bool c = false;
        for(int i=0; i<n; i++) {
            if(word[i]=='@' || word[i]=='#' || word[i]=='$') {
                return false;
            }
            if(isalpha(word[i])) {
                if(isvowel(word[i])) {
                    v = true;
                } else {
                    c = true;
                }   
            }
        }
        return v && c;
    }