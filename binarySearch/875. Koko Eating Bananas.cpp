/*
        Input: piles = [3,6,7,11], h = 8
        Output: 4

        Constraints:
        1 <= piles.length <= 10^4
        piles.length <= h <= 10^9
        1 <= piles[i] <= 10^9
    */

    bool good(int mid, vector<int>& piles, int h) {
        long long int curHour = 0;
        for(int i=0; i<piles.size(); i++) {
            curHour += ceil((piles[i]*1.0)/mid);
        }
        return curHour <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = -1;
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low <= high) {
            int mid = (low+high)/2;
            if(good(mid, piles, h)) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }