class Solution {
    public:
    int posOfRightMostDiffBit(int m, int n) {
        bitset<64> b1(m);
        bitset<64> b2(n);
        string s1 = b1.to_string();
        string s2 = b2.to_string();
        int i = s1.size()-1;
        int j = s2.size()-1;
        int count = 0;
        bool found = false;
        while(i>=0 && j>=0) {
            count++;
            if(s1[i] != s2[j]) {
                found = true;
                break;
            }
            i--;
            j--;
        }
        if(found) {
            return count;
        }
        return -1;
    }
};