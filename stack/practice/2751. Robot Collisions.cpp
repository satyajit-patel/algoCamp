class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int> ans;
        int n = healths.size();
        vector<int> robotsPosition(n);

        for(int i = 0; i < n; i++) {
            robotsPosition[i] = i;
        }

        auto lamda = [&](int& a, int& b) {
            return positions[a] < positions[b];
        };

        std::sort(robotsPosition.begin(), robotsPosition.end(), lamda);

        stack<int> st;
        for(auto& index: robotsPosition) {
            if(directions[index] == 'R') {
                st.push(index);
            } else { // i.e attacking from left side
                while(!st.empty() && healths[index] > 0) {
                    int top_index = st.top();
                    st.pop();

                    if(healths[index] > healths[top_index]) {
                        healths[index]--;
                        healths[top_index] = 0;
                    } else if(healths[top_index] > healths[index]) {
                        healths[top_index]--;
                        healths[index] = 0;
                        st.push(top_index); // make sure to push again
                    } else {
                        healths[index] = 0;
                        healths[top_index] = 0;
                    }
                }
            }
        }

        for(auto& it: healths) {
            if(it > 0) {
                ans.push_back(it);
            }
        }

        return ans;
    }
};