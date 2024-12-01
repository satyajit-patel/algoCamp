// https://leetcode.com/contest/weekly-contest-426/problems/identify-the-largest-outlier-in-an-array/description/
class Solution {
public:
    bool find(vector<pair<int, int>>& temp, int target, int index) {
        int n = temp.size();
        int i = 0;
        int j = n - 1;

        while(i <= j) {
            int mid = (i + j) / 2;

            int num = temp[mid].first;
            int ind = temp[mid].second;

            if((num == target) && (ind != index)) {
                return true;
            } else if(num < target) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        
        return false;
    }

    int getLargestOutlier(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();
        
        int totSum = 0;
        vector<pair<int, int>> temp(n);
        for(int i=0; i<n; i++) { // O(n)
            totSum += nums[i];
            temp[i] = {nums[i], i};
        }
        std::sort(temp.begin(), temp.end()); // O(n * logn)

        for(int i=0; i<n; i++) { // O(n) 
            int outlier = nums[i];
            int sum = totSum - outlier;
            if(!(sum & 1)) { // enter if even
                int target = sum / 2;
                // cout << outlier << " " << sum << " " << target << endl;
                if(find(temp, target, i)) { // O(logn)
                    maxi = max(maxi, outlier);
                }
            }
        }
        return maxi;
    }
};