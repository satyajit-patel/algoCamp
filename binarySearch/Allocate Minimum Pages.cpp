// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
/*
    Input: n = 4, arr[] = [12, 34, 67, 90], m = 2
    Output: 113
    Explanation: Allocation can be done in following ways:
    {12} and {34, 67, 90} Maximum Pages = 191
    {12, 34} and {67, 90} Maximum Pages = 157
    {12, 34, 67} and {90} Maximum Pages =113.
    Therefore, the minimum of these cases is 113, 
    which is selected as the output.
*/
struct Sol {
    bool good(int mid, vector<int>& books, int students) {
        int student  = 1;
        int curPages = 0;
        for(auto& it: books) {
            curPages += it;
            if(curPages > mid) {
                student++;
                curPages = it;
            }
        }
        return student <= students;
    }
    
    int allocateBooks(vector<int>& books, int students) {
        if(students > books.size()) {
            return -1;
        }
        int low  = 0;
        int high = 0;
        int ans  = -1;
        for(auto &it : books) {
            high += it;
            low  = std::max(low, it);
        }
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(good(mid, books, students)) {
                ans  = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    long long findPages(int n, int arr[], int m) {
        Sol* sol = new Sol();
        vector<int> nums(arr, arr+n);
        return sol->allocateBooks(nums, m);
    }
};