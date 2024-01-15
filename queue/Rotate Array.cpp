class Solution {
public:
    void rotateArr(int arr[], int d, int n){
        queue<int> q;
        for(int i=0; i<n; i++) {
            q.push(arr[i]);
        }
        while(d--) {
            int ele = q.front();
            q.pop();
            q.push(ele);
        }
        for(int i=0; i<n; i++) {
            arr[i] = q.front();
            q.pop();
        }
    }
};