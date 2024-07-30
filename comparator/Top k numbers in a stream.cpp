class Solution {
public:
    /*
        https://www.geeksforgeeks.org/problems/top-k-numbers3425/1
        Input:
        N=5, K=4
        arr[] = {5, 2, 1, 3, 2} 
        Output: 
        5 
        2 5 
        1 2 5 
        1 2 3 5 
        2 1 3 5 
    */
    
    struct compClass {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        }
    };
    
    void add(set<pair<int, int>, compClass>& st, vector<vector<int>>& ans, int k) {
        vector<int> temp;
        for(auto it=st.begin(); it!=st.end() && temp.size()<k; it++) {
            temp.push_back(it->first);
        }
        ans.push_back(temp);
    }

    vector<vector<int>> kTop(vector<int>& arr, int n, int k) {
        vector<vector<int>> ans;
        map<int, int> mp;
        set<pair<int, int>, compClass> st;
    
        for(auto& it: arr) {
            if(st.count({it, mp[it]})) {
                st.erase(st.find({it, mp[it]}));
            }
            
            mp[it]++;
            st.insert({it, mp[it]});
            
            add(st, ans, k);
        }
        
        return ans;
    }
};
