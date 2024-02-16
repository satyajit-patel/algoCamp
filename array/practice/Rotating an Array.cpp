/*
        n = 7
        arr[] = {-1, -2, -3, 4, 5, 6, 7}
        d = 2
    */

    void leftRotate(int arr[], int n, int d) {
        vector<int> ans(n);
        for(int i=0; i<n; i++) {
            int index = i - d;
            if(index < 0) {
                index = n - abs(index);
            }
            ans[index] = arr[i];
        }
        for(int i=0; i<n; i++) {
            arr[i] = ans[i];
        }
    }