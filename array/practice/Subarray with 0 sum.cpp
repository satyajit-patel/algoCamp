class Solution {
public:
    bool subArrayExists(int arr[], int n) {
        unordered_map<int, int> map;
        int sum = 0;
        map[sum]++;
        for(int i=0; i<n; i++) {
            // update
            sum += arr[i];
            
            // work
            if(map.count(sum)) {
                return true;
            }
            
            // insert
            map[sum]++;
        }
        return false;
    }
};