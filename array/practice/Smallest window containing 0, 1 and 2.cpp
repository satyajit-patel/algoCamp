class Solution {
  public:
    int smallestSubstring(string& S) {
        bool flag = false;
        int minSize = INT_MAX;
        int zero = 0, one = 0, two = 0;
        int init = 0;
        for(int i=0; i<S.size(); i++) {
            if(S[i] == '1') {
                one++;
            } else if(S[i] == '2') {
                two++;
            } else if(S[i] == '0') {
                zero++;
            }
            while(zero && one && two && init < i) {
                int curSize = i - init +1 ;
                if(curSize < minSize) {
                    flag = true;
                    minSize = curSize;
                }
                if(S[init] == '1') {
                    one--;
                } else if(S[init] == '2') {
                    two--;
                } else if(S[init] == '0') {
                    zero--;
                }
                init++;
            }
        }
        if(!flag) {
            return -1;
        }
        return minSize;
    }
};