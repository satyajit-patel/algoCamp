/*
    Input:
    N = 8, X = 7
    Arr[] = {5, 6, 8, 9, 6, 5, 5, 6}
    Output: 6 8
    Explanation:
    Floor of 7 is 6 and ceil of 7 
    is 8.
    
    N = 8, X = 10
    Arr[] = {5, 6, 8, 9, 6, 5, 5, 6}
    Output: 9 -1
    Explanation:
    Floor of 10 is 9 but ceil of 10 is not 
    possible.
*/

int getUpperBound(int* arr, int n, int x) {
    int ans = -1;
    int left = 0;
    int right = n-1;
    
    while(left <= right) {
        int mid = (left+right)/2;
        if(arr[mid] >= x) {
            ans = mid;
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
    if(ans == -1) {
        return -1;
    }
    return arr[ans];
}

int getLowerBound(int* arr, int n, int x) {
    int ans = -1;
    int left = 0;
    int right = n-1;
    
    while(left <= right) {
        int mid = (left+right)/2;
        if(arr[mid] <= x) {
            ans = mid;
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    if(ans == -1) {
        return -1;
    }
    return arr[ans];
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    sort(arr, arr+n);
    int lb = getLowerBound(arr, n, x);
    int ub = getUpperBound(arr, n, x);
    return {lb, ub};
}