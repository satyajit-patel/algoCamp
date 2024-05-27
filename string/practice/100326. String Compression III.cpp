pair<int, int> f(int i, string& s) {
        int size = 1;
        int index = i+1;
        while(s[index] == s[index-1]) {
            index++;
            size++;
            if(size == 9) {
                return {size, index};
            }
        }
        return {size, index};
    }
    
    string compressedString(string &s) {
        string ans = "";
        int n = s.size();
        int i=0;
        while(i < n) {
            pair<int, int> p = f(i, s);
            int cost = p.first;
            int nextIndex = p.second;
            ans += to_string(cost);
            ans += s[i];
            i = nextIndex;
        }
        return ans;
    }