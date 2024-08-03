class Solution {
public:
    /*
        Input: s = "010"
        Output: "001"

        Input: s = "0101"
        Output: "1001"
    */

    string maximumOddBinaryNumber(string s) {
        // observation a num is odd if it's last bit is odd
        std::sort(s.begin(), s.end());
        std::reverse(s.begin(), s.end());

        int index = s.find_last_of('1'); 
        std::swap(s[index], s[s.size()-1]);

        return s;
    }
};