class Solution {
public:
    static bool comp(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second;
    }

    int maxMeetings(int start[], int end[], int n) {
        vector<pair<int, int>> arr(n);
        for(int i=0; i<n; i++) {
            arr[i] = {start[i], end[i]};
        }
        sort(arr.begin(), arr.end(), comp);
        int ans = 1;
        int last = arr[0].second;
        for(int i=1; i<n; i++) {
            if(arr[i].first > last) {
                last = arr[i].second;
                ans++;
            }
        }
        return ans;
    }
};