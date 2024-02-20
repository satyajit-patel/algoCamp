/*
        Input:
        n = 3 k = 2
        Output: 3
        
        initial :  1 2 3 
        after step1 : 1 3
        after step2 : 3
    */
    
    void state(int i, vector<int>& arr, int k) {
        // base case
        if(arr.size() == 1) {
            return;
        }
        
        // transition
        int newIndex = (i+(k-1)) % arr.size();
        arr.erase(arr.begin()+newIndex);
        state(newIndex, arr, k);
    }
    
    int josephus(int n, int k) {
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            arr[i] = i+1;
        }
        state(0, arr, k);
        return arr[0];
    }