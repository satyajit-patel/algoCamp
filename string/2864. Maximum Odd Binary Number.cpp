class Solution {
public:
    string maximumOddBinaryNumber(string& s) {
        int n = s.size();
        std::sort(s.begin(), s.end());
        std::reverse(s.begin(), s.end());
        int i = s.find_last_of('1');
        std::swap(s[i], s[n-1]);
        return s;
    }
};