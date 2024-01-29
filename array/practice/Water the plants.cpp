class Solution {
public:
    int min_sprinklers(int g[], int n) {
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++) {
            if(g[i] > -1) {
                v.push_back({i-g[i], i+g[i]});
            }
        }
        int i = 0, count = 0, target = 0;
        sort(v.begin(), v.end());
        while(target < n) {
            if(i == v.size() || v[i].first > target) {
                return -1;
            }
            int mx = v[i].second;
            while(i+1<v.size() && v[i+1].first<=target) {
                i++;
                mx = max(mx, v[i].second);
            }
            count++;
            target = mx+1;
            i++;
        }
        return count;
    }
};
