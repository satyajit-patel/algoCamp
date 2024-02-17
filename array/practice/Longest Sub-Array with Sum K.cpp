/*
        Input :
        A[] = {10, 5, 2, 7, 1, 9}
        K = 15
        Output : 4
        Explanation:
        The sub-array is {5, 2, 7, 1}.
        
        Constraints:
        1<=N<=105
        -105<=A[i], K<=105
        
        f(n) = O(nlogn)
    */
    
    int lenOfLongSubarr(int A[],  int N, int K) { 
        int maxi = 0;
        
        // for(int i=0; i<N; i++) {
        //     int sum = 0;
        //     for(int j=i; j<N; j++) {
        //         sum += A[j];
        //         if(sum == K) {
        //             maxi = max(maxi, j-i+1);
        //         }
        //     }
        // }
        
        map<int, int> map; // {sum, index}
        int sum = 0;
        map[sum] = -1;
        for(int i=0; i<N; i++) {
            sum += A[i];
            if(map.find(sum - K) != map.end()) {
                maxi = max(maxi, i-map[sum - K]);
            }
            if(map.find(sum) == map.end()) {
                map[sum] = i;   
            }
        }
        
        return maxi;
    } 