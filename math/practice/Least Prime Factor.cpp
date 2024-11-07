// https://www.geeksforgeeks.org/problems/least-prime-factor5216/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        // 1 <= n <= 1e5
        vector<int> smallestPrime(n+1, -1);
        smallestPrime[0] = 0;
        smallestPrime[1] = 1;
        for(int i=2; i<=n; i++) {
            for(int j=i; j<=n; j+=i) {
                if(smallestPrime[j] == -1) {
                    smallestPrime[j] = i;
                }
            }
        }
        return smallestPrime;
    }
};