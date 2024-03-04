/*
	    Input: 
        n = 4
        arr[] =  {"54", "546", "548", "60"}
        Output: "6054854654"
        Explanation: 
        Given numbers are {"54", "546", "548", "60"}, the 
        arrangement "6054854654" gives the largest value.
	*/
	
	static bool comp(string& s1, string& s2) {
	    return (s1+s2) > (s2+s1);
	}
	
	string printLargest(int n, vector<string> &arr) {
	    string ans = "";
	    sort(arr.begin(), arr.end(), comp);
	    for(auto& it: arr) {
	        ans += it;
	    }
	    return ans;
	}