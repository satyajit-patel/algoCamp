// m is maximum of number zeroes allowed to flip
    // n is size of array
    
    /*
        Input:
        N = 3
        arr[] = {1, 0, 1}
        M = 1
        Output:
        3
    */
    
    int findZeroes(int arr[], int n, int m) {
        int maxi = 0, num_zero = 0;
        for(int i=0,init=0; i<n; i++) {
            if(arr[i] == 0) {
                num_zero++;
            }
            
            while(num_zero > m) {
                if(arr[init++] == 0) {
                    num_zero--;
                }
            }
            
            maxi = max(maxi, i-init+1);
        }
        return maxi;
    }  