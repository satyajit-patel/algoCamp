 /*
        Constraints:
        1 <= deck.length <= 1000
        1 <= deck[i] <= 106
        All the values of deck are unique.

        f(n) = O(n^2 logn)

        Input: deck = [17,13,11,2,3,5,7]
        Output: [2,13,3,11,5,17,7]

        dry run

        ans     0 0 0 0 0 0 0
        deck    2 3 5 7 11 13 17
        q       0 1 2 3 4 5 6

        ans     2 0 0 0 0 0 0
        deck    2 3 5 7 11 13 17
        q       2 3 4 5 6 1
        index = 0, i = 0

        ans     2 0 3 0 0 0 0
        deck    2 3 5 7 11 13 17
        q       4 5 6 1 3
        index = 2, i = 1

        ans     2 0 3 0 5 0 0
        deck    2 3 5 7 11 13 17
        q       6 1 3 5
        index = 4, i = 2

        ans     2 0 3 0 5 0 7
        deck    2 3 5 7 11 13 17
        q       3 5 1
        index = 6, i = 3

        ans     2 0 3 11 5 0 7
        deck    2 3 5 7 11 13 17
        q       1 5
        index = 3, i = 4

        ans     2 13 3 11 5 0 7
        deck    2 3 5 7 11 13 17
        q       5 
        index = 1, i = 5

        ans     2 13 3 11 5 17 7
        deck    2 3 5 7 11 13 17
        q       empty
        index = 5, i = 6
    */

    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> ans(n);

        queue<int> q;
        sort(deck.begin(), deck.end());
        for(int i=0; i<n; i++) {
            q.push(i);
        }
        for(int i=0; i<n; i++) {
            int index = q.front();
            q.pop();

            ans[index] = deck[i];
            if(!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }

        return ans;
    }