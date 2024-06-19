class Solution {
public:
    bool judgeSquareSum(int c) {
        int i = 0;
        int j = sqrt(c);
        while(i <= j) {
            long long calc = (long long)(i*i)+(j*j);
            if(calc == c) {
                return true;
            } else if(calc > c) {
                j--;
            } else if(calc < c) {
                i++;
            }
        }
        return false;
    }
};