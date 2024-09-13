class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        // aim is to kill the enemy who has
        // more damge and less health
        int n = damage.size();
        long long ans = 0;
        int totalDamage = 0;
        for(auto& it: damage) {
            totalDamage += (it * 1LL);
        }

        vector<pair<double, int>> nums(n);
        for(int i=0; i<n; i++) {
            int hit = ceil(1.0 * health[i] / power);
            double damPerHit = 1.0 * damage[i] / hit;
            nums[i] = {damPerHit, i};
        }
        sort(nums.begin(), nums.end(), greater<pair<double, int>>());

        for(int i=0; i<nums.size(); i++) {
            int index = nums[i].second;
            cout<<index<<" -> ";
            int d = damage[index];
            int h = health[index];
            int hit = ceil(1.0 * h / power);
            ans += (hit * totalDamage);
            totalDamage -= d;
        }
        return ans;
    }
};