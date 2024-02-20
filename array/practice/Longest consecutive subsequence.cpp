/*
        Input:
        N = 7
        a[] = {2,6,1,9,4,5,3}
        Output:
        6
    */
    int findLongestConseqSubseq(int arr[], int N) {
        sort(arr, arr+N);
        int ans = 1, maxi = 1;
        for(int i=1; i<N; i++) {
            if(arr[i] - arr[i-1] == 1) {
                maxi++;
            } else if(arr[i] - arr[i-1] == 0) {
                continue;
            } else {
                maxi = 1;
            }
            ans = max(ans, maxi);
        }
        return ans;
    }