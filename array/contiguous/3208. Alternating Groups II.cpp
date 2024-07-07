class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans = 0;
        int n = colors.size();
        vector<int> a = colors;
        a.insert(a.end(), a.begin(), a.end());

        // feels like sliding window but not sliding window
        int size = 1;
        for(int i=1; i<n+(k-1); i++) {
            if(a[i] != a[i-1]) {
                size++;
            } else {
                size = 1;
            }
            
            if(size >= k) {
                ans++;
            }
        }

        return ans;
    }
};