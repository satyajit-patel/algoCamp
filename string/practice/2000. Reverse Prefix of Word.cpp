/*
        Input: word = "abcdefd", ch = "d"
        Output: "dcbaefd"
    */

    string reversePrefix(string word, char ch) {
        int n = word.size();
        int index = -1;
        string ans = "";
        for(int i=0; i<n; i++) {
            ans += word[i];
            if(word[i] == ch) {
                index = i+1;
                break;
            } 
        }

        if(index == -1) {
            return word;
        }
        reverse(ans.begin(), ans.end());
        while(index < n) {
            ans += word[index];
            index++;
        }
        return ans;
    }