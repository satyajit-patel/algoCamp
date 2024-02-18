 /*
        Input:
        A[] = {1, 2, 4, 5, 7}
        B[] = {5, 6, 3, 4, 8} 
        X = 9 
        Output: 
        1 8
        4 5 
        5 4
        Explanation:
        (1, 8), (4, 5), (5, 4) are the
        pairs which sum to 9.
    
        Constraints:
        1 ≤ N, M ≤ 10^6
        -106 ≤ X, A[i], B[i] ≤ 106
        
        f(n) = O(nlogn)
    */
    
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X) {
        // Your code goes here
        vector<pair<int,int>> ans;
        sort(A, A+N);
        sort(B, B+M);
        
        // for(int i=0; i<N; i++) {
        //     // ele1 + ele2 = x
        //     // ele2 = x - ele1
        //     int ele1 = A[i];
        //     int ele2 = X - ele1;
            
        //     if(binary_search(B, B+M, ele2)) {
        //         ans.push_back({ele1, ele2});
        //     }
        // }
        
        int i = 0, j = M-1;
        while(i<N && j>=0) {
            int sum = A[i] + B[j];
            if(sum == X) {
                ans.push_back({A[i], B[j]});
                i++;
                j--;
            } else if(sum < X) {
                i++;
            } else {
                j--;
            }
        }
        
        return ans;
    }