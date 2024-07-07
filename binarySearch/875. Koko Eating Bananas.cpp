class Solution {
public:
    bool good(int mid, auto& piles, int h) {
        long long count = 0;
        for(int i=0; i<piles.size(); i++) {
            count += piles[i] / mid;
            if(piles[i] % mid) { // if still some bananas left to eat
                count++;
            }
        }
        return count <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = -1;

        int i = 1;
        int j = 1e9;
        while(i <= j) {
            int mid = (i + j) / 2;
            if(good(mid, piles, h)) {
                ans = mid;
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }

        return ans;
    }
};