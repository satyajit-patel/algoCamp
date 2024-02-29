 /*
        s = "16"
        Output:
        1
        
        s = "54141111648421214584416464555"
        Output:
        -1
    */
    
    int DivisibleByEight(string s) {
        int n = s.size();
        if(n > 3) {
            int lastTreeDigitNum = stoi(s.substr(n-3));
            if(lastTreeDigitNum%8 == 0) {
                return 1;
            }
            return -1;
        }
        int num = stoi(s);
        if(num%8 == 0) {
            return 1;
        }
        return -1;
    }