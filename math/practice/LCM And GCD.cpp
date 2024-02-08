class Solution {
public:
    long long getGcd(long long A, long long B) {
        if(!B) {
            return A;
        }
        return getGcd(B, A%B);
    }
    
    long long getLcm(long long A, long long B) {
        return (A*B)/getGcd(A, B);
    }

    vector<long long> lcmAndGcd(long long A , long long B) {
        long long lcm = getLcm(A, B);
        long long gcd = getGcd(A, B);
        return {lcm, gcd};
    }
};