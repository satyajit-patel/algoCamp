/*
    https://www.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1

    Input: n = 5, d = 2, arr[] = {1,2,3,4,5}
    Output: 3 4 5 1 2    
*/

class Solution {
public:
    void rotateArr(int arr[], int d, int n) {
        queue<int> q;
        for(int i=0; i<n; i++) {
            q.push(arr[i]);
        }
        while(d--) {
            int x = q.front();
            q.pop();
            q.push(x);
        }
        int i = 0;
        while(!q.empty()) {
            arr[i++] = q.front();
            q.pop();
        }
        
        // vector<int> a(arr, arr+n);
        // while(d--) {
        //     int x = a[0];
        //     a.erase(a.begin()+0);
        //     a.push_back(x);
        // }
        // for(int i=0; i<n; i++) {
        //     arr[i] = a[i];
        // }
    }
};
