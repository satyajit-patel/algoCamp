bool isprime(int n) {
        if(n < 2) {
            return false;
        }
        for(int ele=2; ele*ele<=n; ele++) {
            if((n % ele) == 0) {
                return false;
            }
        }
        return true;
    }
  
    vector<int> getPrimes(int n) {
        for(int ele=2; ele<=n; ele++) {
            // ele + x = n
            int x = n - ele;
            if(isprime(ele) && isprime(x)) {
                return {ele, x};
            }
        }
        return {-1, -1};
    }