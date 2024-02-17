class Solution{
public:
    int maxLen(vector<int>&A, int n) {   
        map<int, int> map;
        int sum = 0;
        map[sum] = -1;
        int ans = 0;
        for(int i=0; i<n; i++) {
            // work
            sum += A[i];
            
            // update
            if(map.count(sum)) {
                ans = max(ans, i-map[sum]);
            } else {
                map[sum] = i;
            }
        }
        return ans;
    }
};