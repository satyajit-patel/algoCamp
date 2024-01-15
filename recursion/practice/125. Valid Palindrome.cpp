class Solution {
public:
    int index;
    string str;

    bool f1() {
        int i = 0, j = str.size()-1;
        while(i <= j) {
            if(str[i] != str[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    bool f2(int i, int j) {
        // base case
        if(i >= j) {
            return true;
        }
        if(str[i] != str[j]) {
            return false;
        }

        // transition
        bool ans = f2(i+1, j-1);
        if(!ans) {
            return ans;
        }
        return ans;
    }

    bool f3(int j) {
        // cout<<"HI\n";
        // base case
        if(str[j] == NULL) {
            return true;
        }
        // if(j == 8) {
        //     return true;
        // }
        if(index > j) {
            return true;
        }

        // transition
        bool ans = f3(j+1);
        ans = (str[index] == str[j]) && ans;
        // cout<<str[index]<<" "<<str[j]<<"->"<<ans<<endl;
        index++;
        return ans;
    }

    bool isPalindrome(string& s) {
        string purified = "";
        for(auto& it: s) {
            if(isalnum(it)) {
                purified += tolower(it);
            }
        }
        str.clear(), str = purified;
        // bool ans = f1();
        // bool ans = f2(0, str.size()-1);
        index = 0;
        // without knowing size
        bool ans = f3(0);
        return ans;
    }
};