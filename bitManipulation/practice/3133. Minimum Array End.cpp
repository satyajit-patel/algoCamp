class Solution {
public:
    long long minEnd(int n, int x) {
        /*
            4 => 1 0 0
            5 => 1 0 1
            6 => 1 1 0

            7  => 0 1 1 1
            15 => 1 1 1 1
        */

        long long a = x * 1LL;
        if(n == 1) {
            return a;
        }

        long long i = 0;

        int count = 0;
        long long b = (n-1) * 1LL;
        for(long long bit=0; bit<64; bit++) {
            if(!(a & (1LL << bit))) {
                if(b & (1LL << i++)) {
                    a = a | (1LL << bit);
                    count++;
                }
            }
            if(count >= (n-1)) {
                break;
            }
        }
        return a;
    }
};