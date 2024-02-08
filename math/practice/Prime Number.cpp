class Solution{
public:
    bool f(int N) {
        if(N == 1) {
            return false;
        }
        for(int i=2; i*i<=N; i++) {
            if(N%i == 0) {
                return false;
            }
        }
        return true;
    }

    int isPrime(int N){
        return f(N);
    }
};