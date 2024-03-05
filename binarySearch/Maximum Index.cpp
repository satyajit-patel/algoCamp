 /*
        n = 9
        a[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
        Output:
        6
        Explanation:
        In the given array a[1] < a[7] 
        satisfying the required condition(a[i] < a[j]) 
        thus giving the maximum difference of j - i which is 6(7-1).
        
        Constraints:
        1 ≤ n ≤ 10^6
        0 ≤ a[i] ≤ 10^9
    */
    
    int maxIndexDiff(int a[], int n) { 
        // condition A[i] <= A[j] && i <= j
        int maxi = -1e9;
        
        // tow pointer
        // // TLE almost pass n + n = O(n), but for 1-2 case O(n^2)
        // for(int i=0; i<n; i++) {
        //     int j = n-1;
        //     while(j >= i && a[j] < a[i]) {
        //         j--;
        //     }
        //     maxi = max(maxi, j-i);
        // }
        
        // binary search
        int rightMaxi[n];
        int tempMaxi = -1e9;
        for(int i=n-1; i>=0; i--) {
            tempMaxi = max(tempMaxi, a[i]);
            rightMaxi[i] = tempMaxi;
        }
        /*
            a[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
            
            rightMaxi graph
            80
                80
                    80
                        80
                            80
                                80
                                    33
                                        33
                                            1
                
                
                
            
        */
        
        // O(nlogn)
        for(int i=0; i<n; i++) {
            int ans = -1;
            int low = i;
            int high = n-1;
            while(low <= high) {
                int mid = (low+high)/2;
                if(a[i] <= rightMaxi[mid]) {
                    ans = mid;
                    low = mid+1;
                } else {
                    high = mid-1;
                }
            }
            maxi = max(maxi, ans-i);
        }
        
        return maxi;
    }