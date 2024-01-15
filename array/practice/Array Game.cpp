// https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-135/problems
class Solution {
public:
    int min_operations(int n, vector<int>&arr, vector<int>&brr) {
	    int ans = 0;
	    queue<int> q;
	    for(auto& it: arr) {
	        q.push(it);
	    }
	    int index = 0;
	    while(!q.empty()) {
	        if(q.front() == brr[index]) {
	            index++;
	            q.pop();
	        } else {
	            int num = q.front();
	            q.pop();
	            q.push(num);
	        }
	        ans++;
	    }
	    return ans;
    }
};
