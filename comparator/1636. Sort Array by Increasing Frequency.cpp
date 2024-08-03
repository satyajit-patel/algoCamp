class Solution {
public:
    /*
        Input: 
            colors = [0,1,0,1,0], // circular
            k = 3
        Output: 
            3
        explanation
            as k = 3 so it will circulate upto
            0 1 0 1 0 - 0 0 1

    */

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