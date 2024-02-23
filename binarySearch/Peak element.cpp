/*
        n = 3
        arr[] = {1, 2, 3}
        Peak Element's Index: 2
        Output: 1
    */
    
    int peakElement(int arr[], int n) {
        // there could be multiple peak elements
        if(n == 1) {
            return 0;
        }
        if(arr[0] >= arr[1]) {
            return 0;
        }
        if(arr[n-1] >= arr[n-2]) {
            return n-1;
        }
        
        // // O(n)
        // for(int i=1; i<n-1; i++) {
        //     if(arr[i]>arr[i-1] && arr[i]>arr[i+1]) {
        //         return i;
        //     }
        // }
        
        // O(logn)
        int low = 1;
        int high = n-2;
        while(low <= high) {
            int mid = (low+high)/2;
            if(arr[mid]>=arr[mid-1] && arr[mid]>arr[mid+1]) {
                return mid;
            }
            // in increasing graph
            if(arr[mid] >= arr[mid-1]) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        
        return -1;
    }