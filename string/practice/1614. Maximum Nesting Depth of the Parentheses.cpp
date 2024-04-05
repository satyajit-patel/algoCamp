/*
        Input: s = "(1+(2*3)+((8)/4))+1"
        Output: 3
        Explanation: 
        Digit 8 is inside of 3 nested parentheses in the string.
    */

    int maxDepth(string s) {
        int maxi = INT_MIN;

        int openParenthesis = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') {
                openParenthesis++;
            } else if(s[i] == ')') {
                openParenthesis--;
            }
            maxi = max(maxi, openParenthesis);
        }

        return maxi;
    }