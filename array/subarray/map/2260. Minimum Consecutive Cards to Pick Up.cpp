/*
        Constraints:
        1 <= cards.length <= 10^5
        0 <= cards[i] <= 10^6

        f(n) = O(n)

        Input: cards = [3,4,2,3,4,7]
        Output: 4
        Explanation: 
        We can pick up the cards 
        [3,4,2,3] which contain a matching pair of cards with value 3. 
        Note that picking up the cards [4,2,3,4] is also optimal.
    */

    int minimumCardPickup(vector<int>& cards) {
        int mini = INT_MAX;
        int n = cards.size();

        map<int, int> mp;
        // O(n logn)
        for(int i=0; i<n; i++) { // O(n)
            int x = cards[i];
            if(mp.count(x)) { // O(logn)
                mini = min(mini, i-mp[x]+1);
            }

            mp[x] = i;
        }

        if(mini == INT_MAX) {
            return -1;
        }
        return mini;
    }s