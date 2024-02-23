 /*
        N = 4
        Arr = {1, 3, 5, 6}
        k = 5
        Output: 2
        
        N = 4
        Arr = {1, 3, 5, 6}
        k = 2
        Output: 1
    */
    
    int searchInsertK(vector<int>Arr, int N, int k) {
        int index = lower_bound(Arr.begin(), Arr.end(), k) - Arr.begin();
        return index;
    }