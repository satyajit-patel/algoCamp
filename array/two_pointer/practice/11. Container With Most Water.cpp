class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = INT_MIN;

        // // failed in [1,2,1]
        // vector<pair<int, int>> leftMaxHeight(n);
        // int maxi = INT_MIN;
        // int index = -1;
        // for(int i=0; i<n; i++) {
        //     if(height[i] > maxi) {
        //         maxi = height[i];
        //         index = i;
        //     }
        //     leftMaxHeight[i] = {maxi, index};
        // }
        // for(int i=0; i<n; i++) {
        //     auto it = leftMaxHeight[i];
        //     int width = i - it.second;
        //     int length = std::min(it.first, height[i]);
        //     int curArea = length * width;
        //     maxArea = std::max(maxArea, curArea);
        //     // cout<<length<<" "<<width<<" "<<curArea<<endl;
        // }

        int i = 0;
        int j = n - 1;

        while(i < j) {
            int length = std::min(height[i], height[j]);
            int width = j - i;
            int curArea = length * width;
            maxArea = std::max(maxArea, curArea);

            if(height[i] <= height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return maxArea;
    }
};