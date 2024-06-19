class Solution {
public:
    /*
        Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
        Output: 12
        Explanation: 
        We need 2 bouquets each should have 3 flowers.
        Here is the garden after the 7 and 12 days:
        After day 7: [x, x, x, x, _, x, x]
        We can make one bouquet of the first three flowers that bloomed. 
        We cannot make another bouquet from the last three flowers that bloomed because 
        they are not adjacent.
        After day 12: [x, x, x, x, x, x, x]
        It is obvious that we can make two bouquets in different ways.
    */

    bool f(int mid, vector<int>& bloomDay, int m, int k) {
        int size = 0;
        int num_bouque = 0;
        for(int i=0; i<bloomDay.size(); i++) {
            if(bloomDay[i] <= mid) {
                size++;
            } else {
                size = 0;
            }
            if(size == k) {
                size = 0;
                num_bouque++;
            }
            if(num_bouque == m) {
                return true;
            }
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 0;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while(low <= high) {
            int mid = (low+high)/2;
            // cout<<low<<" "<<high<<"-mid->"<<mid<<endl;
            if(f(mid, bloomDay, m, k)) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
};