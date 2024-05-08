/*
        Return the following:
        If version1 < version2, return -1.
        If version1 > version2, return 1.
        Otherwise, return 0.

        Input: version1 = "1.0", version2 = "1.0.0"
        Output: 0

        Input: version1 = "0.1", version2 = "1.1"
        Output: -1
    */

    int compareVersion(string version1, string version2) {
        vector<string> v1, v2;

        stringstream ss1(version1);
        while(ss1.good()) {
            string word;
            getline(ss1, word, '.');
            v1.push_back(word);
        }

        stringstream ss2(version2);
        while(ss2.good()) {
            string word;
            getline(ss2, word, '.');
            v2.push_back(word);
        }

        // for(auto& it: v1) {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        // for(auto& it: v2) {
        //     cout<<it<<" ";
        // }

        int n = max(v1.size(), v2.size());
        for(int i=0; i<n; i++) {
            int x = (i < v1.size()) ? stoi(v1[i]) : 0;
            int y = (i < v2.size()) ? stoi(v2[i]) : 0;
            if(x < y) {
                return -1;
            } else if(x > y) {
                return 1;
            }
        }

        return 0;
    }