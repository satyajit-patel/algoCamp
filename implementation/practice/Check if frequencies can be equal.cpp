/*
        https://www.geeksforgeeks.org/problems/check-frequencies4211/1
        is it possible to DEL atmost 1 char to make equal freq ele
        input => xxyyz
        output => 1 (xxyy)
        
        input => xyyz
        output => xyz
    */
    
    bool f1(map<char, int> map, int minOccurance) {
        for(auto& it: map) {
	        if(it.second > minOccurance) {
	            map[it.first]--;
	            break;
	        }
	    }
	    
	    for(auto& it: map) {
	        if(it.second != minOccurance) {
	            return false;
	        }
	    }
	    return true;
    }
    
    bool f2(map<char, int> map, int minOccurance) {
        int anotherOccurance = INT_MAX;
        for(auto& it: map) {
            if(map[it.first] == minOccurance) {
                map[it.first]--;
                if(map[it.first] == 0) {
                    map.erase(map.find(it.first));
                }
            }
            if(it.second != minOccurance) {
                anotherOccurance = it.second;
            }
        }
        
        for(auto& it: map) {
	        if(it.second != anotherOccurance) {
	            return false;
	        }
	    }
	    return true;
        
    }

	bool sameFreq(string& s) {
	    map<char, int> map;
	    for(auto& it: s) {
	        map[it]++;
	    }
	    int minOccurance = INT_MAX;
	    for(auto& it: map) {
	        minOccurance = min(minOccurance, it.second);
	    }
	    
	    bool case1 = f1(map, minOccurance);
	    if(case1) {
	        return true;
	    }
	    bool case2 = f2(map, minOccurance);
	    if(case2) {
	        return true;
	    }
	    return false;
	}