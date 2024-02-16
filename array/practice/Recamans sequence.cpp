vector<int> recamanSequence(int n){
        // 1 ≤ n ≤ 10^5 i.e f(n) = O(nlogn)
        set<int> st = {0};
        vector<int> a = {0};
        for(int i=1; i<n; i++) {
            int curEle = a[i-1] - i;
            if(curEle>0 && st.find(curEle)==st.end()) {
                st.insert(curEle);
                a.push_back(curEle);
            } else {
                curEle = a[i-1] + i;
                st.insert(curEle);
                a.push_back(curEle);
            }
        }
        return a;
    }