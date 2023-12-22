class Solution {
  public:
    int gameOfXor(int N , int A[]) {
        /*
            XOR Properties
            A ^ A = 0
            A ^ A ^ A = A
            
            Bitwise XOR of A
                => even times = 0
                => odd times = A
        */
        int ans = 0;
        for(int i=0; i<N; i++) {
            // find out #times A[i] will occure in subarray
            // and apply XOR properties
            int freq = (i-0+1) * ((N-1)-i+1);
            if(freq%2) {
                ans ^= A[i];
            }
        }
        return ans;
    }
};