 /*
        n = 6
        A[] = {16,17,4,3,5,2}
        Output: 17 5 2
    */
    
    vector<int> leaders(int a[], int n){
        vector<int> suffixMax(n);
        int maxi = INT_MIN;
        for(int i=n-1; i>=0; i--) {
            maxi = max(maxi, a[i]);
            suffixMax[i] = maxi;
        }
        
        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(a[i] >= suffixMax[i]) {
                ans.push_back(a[i]);
            }
        }
        return ans;
    }