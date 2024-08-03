 /*
        Input: deadends = ["0201","0101","0102","1212","2002"], 
        target = "0202"
        Output: 6
    */

    int bfs(string& start, auto& st, string& target) {
        queue<pair<string, int>> q;
        q.push({start, 0});

        while(!q.empty()) {
            start = q.front().first;
            int curStep = q.front().second;
            q.pop();

            if(start == target) {
                return curStep;
            }

            for(int i=0; i<4; i++) {
                char ch = start[i];

                char inc = (ch == '9') ? '0' : ch+1;
                char dec = (ch == '0') ? '9' : ch-1;

                start[i] = inc;
                if(!st.count(start)) {
                    q.push({start, curStep+1});
                    st.insert(start);
                }
                start[i] = dec;
                if(!st.count(start)) {
                    q.push({start, curStep+1});
                    st.insert(start);
                }

                start[i] = ch;
            }
        }
        return -1;
    }

    int openLock(vector<string>& deadends, string target) {
        set<string> st = {deadends.begin(), deadends.end()};
        string start = "0000";
        if(st.count(start)) {
            return -1;
        }
        int ans = bfs(start, st, target);
        return ans;
    }