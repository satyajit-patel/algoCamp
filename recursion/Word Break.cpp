/*
        Input:
        n = 6
        B = { "i", "like", "sam", "sung", "samsung", "mobile"}
        A = "ilike"
        Output:
        1
        Explanation:
        The string can be segmented as "i like".
        
        Constraints:
        1 ≤ n ≤ 12
        1 ≤ len(A) ≤ 1100
    */

    bool isPresent(string temp, vector<string> &B) {
        for(auto& it: B) {
            if(it == temp) {
                return true;
            }
        }
        return false;
    }

    int state(int i, string& A, vector<string> &B) {
        // base case
        if(i >= A.size()) {
            return 1;
        }
        
        // transition
        int ans = 0;
        string temp = "";
        for(int j=i; j<A.size(); j++) {
            temp += A[j];
            if(isPresent(temp, B)) {
                ans = ans || state(j+1, A, B);
            }
        }
        return ans;
    }

    int wordBreak(string A, vector<string> &B) {
        int ans = state(0, A, B);
        return ans;
    }