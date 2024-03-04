/*
        Input:
        N=5, K=4
        arr[] = {5, 2, 1, 3, 2} 
        Output: 
        5 
        2 5 
        1 2 5 
        1 2 3 5 
        2 1 3 5 
        Explanation:
        Firstly there was 5 whose frequency
        is max till now. So resulting sequence is {5}.
        Then came 2, which is smaller than 5 but
        their frequencies are same so resulting sequence is {2, 5}.
        Then came 1, which is the smallest among all the
        numbers arrived, so resulting sequence is {1, 2, 5}.
        Then came 3 , so resulting sequence is {1, 2, 3, 5}
        Then again 2, which has the highest
        frequency among all numbers, 
        so resulting sequence {2, 1, 3, 5}.
    */

    struct comp {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        }
    };

    vector<vector<int>> kTop(vector<int>& arr, int n, int k) {
        vector<vector<int>> result;
        map<int, int> freqMap;
        set<pair<int, int>, comp> freqSet;
    
        for (int i = 0; i < n; ++i) {
            int num = arr[i];
            auto it = freqSet.find({num, freqMap[num]});
            if (it != freqSet.end()) {
                freqSet.erase(it);
            }
            freqMap[num]++;
            freqSet.insert({num, freqMap[num]});
            vector<int> temp;
            for(auto it=freqSet.begin(); it!=freqSet.end() && temp.size()<k; it++) {
                temp.push_back(it->first);
            }
            result.push_back(temp);
        }
        return result;
    }