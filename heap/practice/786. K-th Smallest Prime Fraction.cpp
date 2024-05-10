/*
        Input: arr = [1,2,3,5], k = 3
        Output: [2,5]

        Constraints:
        2 <= arr.length <= 10^3
        1 <= arr[i] <= 3 * 104

        f(n) = O(n2 * logn)
    */

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();

        // // bruteForce
        // vector<pair<float, pair<int, int>>> a;
        // for(int i=0; i<n; i++) {
        //     for(int j=i+1; j<n; j++) {
        //         a.push_back({(arr[i]*1.0)/arr[j], {arr[i], arr[j]}});
        //     }
        // }
        // sort(a.begin(), a.end());
        // // // debug
        // // for(auto& it: a) {
        // //     cout<<it.first<<"->"<<it.second.first<<","<<it.second.second<<endl;
        // // }
        // // n^2 + nlogn = O(n^2)
        // return {a[k-1].second.first, a[k-1].second.second};

        // kTh smallest
        priority_queue<vector<double>> maxHeap;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                maxHeap.push({(double)arr[i]/arr[j], (double)arr[i], (double)arr[j]});

                if(maxHeap.size() > k) {
                    maxHeap.pop();
                }
            }
        }
        // n^2 + log(k) = O(n^2)
        return {(int)maxHeap.top()[1], (int)maxHeap.top()[2]};
    }