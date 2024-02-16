long long sequence(int n) {
        int mod = 1e9 + 7;
        long long ans = 0;
        int start = 1;
        int newN = 1;
        while(newN <= n) {
            long long mul = 1;
            int temp = newN;
            while(temp--) {
                // mul *= (start++);
                mul = ((mul % mod) * ((start++)%mod)) % mod;
            }
            ans = ((ans%mod) + (mul%mod)) % mod;
            newN++;
        }
        return ans % mod;
    }