// m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        // code here
        int ans = 0;
        int numOfZero = 0;
        for(int i=0,j=0; j<n; j++) {
            if(arr[j] == 0) {
                numOfZero++;
            }
            while(numOfZero > m && i <= j) {
                if(arr[i] == 0) {
                    numOfZero--;
                }
                i++;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }  