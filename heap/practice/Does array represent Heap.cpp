/*
        Input:
        n = 6
        arr[] = {90, 15, 10, 7, 12, 2}
        Output: 
        1
    */
    
    bool isMaxHeap(int arr[], int n) {
        for(int i=0; i<n; i++) {
            int parent = arr[i];
            int leftChildIndex = (2 * i) + 1;
            int rightChildIndex = (2 * i) + 2;
            
            if(leftChildIndex < n && arr[leftChildIndex] > parent) {
                return false;
            }
            if(rightChildIndex < n && arr[rightChildIndex] > parent) {
                return false;
            }
        }
        return true;
    }