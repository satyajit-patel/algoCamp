/*
        n = 4
        a[] = {1, -2, 2, -3}
        k = 2
        Output : 
        1
    */
    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) {
        long long maxi = INT_MIN, sum = 0, tempSum = 0;
        for(long long i=0,init=0; i<n; i++) {
            sum += a[i];
            if(i-init+1 == k) {
                maxi = max(maxi, sum);
            }
            else if(i-init+1 > k) {
                maxi = max(maxi, sum);
                tempSum += a[init++];
                if(tempSum < 0) {
                    sum -= tempSum;
                    maxi = max(maxi, sum);
                    tempSum = 0;
                }
            }
        }
        return maxi;
    }