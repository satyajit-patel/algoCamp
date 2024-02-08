class Solution {
public:
    string equilibrium(int *arr, int n) {
        if(n == 1) {
            return "YES";
        }
        
        int L[n], R[n];
        
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += arr[i];
            L[i] = sum;
        }
        
        sum = 0;
        for(int i=n-1; i>=0; i--) {
            sum += arr[i];
            R[i] = sum;
        }
        
        for(int i=1; i<n-1; i++) {
            if(L[i-1] == R[i+1]) {
                return "YES";
            }
        }
        
        return "NO";
    }
};
