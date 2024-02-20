/*
        Input:
        N = 2
        Arr[] = {2, 2}
        Output: 2 1
    */
    vector<int> findTwoElement(vector<int> arr, int n) {
        map<int, int> map;
        for(auto& it: arr) {
            map[it]++;
        }
        int repeatNum = -1, missNum = n;
        for(auto& it: map) {
            if(it.second > 1) {
                repeatNum = it.first;
                break;
            }
        }
        int init = 1;
        for(auto& it: map) {
            if(it.first != init) {
                missNum = init;
                break;
            }
            init++;
        }
        return {repeatNum, missNum};
    }