/*
        Input:
        n = 3 k = 2
        Output: 3
        
        initial :  1 2 3 
        after step1 : 1 3
        after step2 : 3
    */
    
    void state(int i, vector<int>& arr, int k) {
        // base case
        if(arr.size() == 1) {
            return;
        }
        
        // transition
        int newIndex = (i+(k-1)) % arr.size();
        arr.erase(arr.begin()+newIndex);
        state(newIndex, arr, k);
    }
    
    int josephus(int n, int k) {
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            arr[i] = i+1;
        }
        state(0, arr, k);
        return arr[0];
    }

	// ********************************

	class Solution {
public:
    int findTheWinner(int n, int k) {
        // circular game / josephus problem
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            arr[i] = i + 1;
        }

        // // O(n^2)
        // int i = 0;
        // while(arr.size() > 1) { // O(n)
        //     int newIndex = (i+(k-1)) % arr.size();
        //     arr.erase(arr.begin()+newIndex); // O(n) as it has to shift back rest elements
        //     i = newIndex;
        // }
        // return arr[0];

        // O(n * k)
        queue<int> q;
        for(auto& it: arr) {
            q.push(it);
        }
        while(q.size() > 1) { // O(n)
            // we have to delete kTh element, so we need to stand at it's previous
            for(int i=0; i<k-1; i++) { // O(k)
                int ele = q.front();
                q.pop();
                q.push(ele);
            }
            q.pop();
        }
        return q.front();
    }
};