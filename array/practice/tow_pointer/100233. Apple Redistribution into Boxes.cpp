/*
        Constraints:
        1 <= n == apple.length <= 50
        1 <= m == capacity.length <= 50
        1 <= apple[i], capacity[i] <= 50
        
        Input: apple = [1,3,2], capacity = [4,3,1,5,2]
        Output: 2
        
        input:
        [1,8,3,3,5]
        [3,9,5,1,9]
        output: 3
    */
    
    static bool comp(int a, int b) {
        return a > b;
    }
    
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int j = 0;
        int leftSum = 0;
        int rightSum = 0;
        
        sort(capacity.begin(), capacity.end(), comp);
        
        rightSum += capacity[j];
        
        for(int i=0; i<apple.size(); i++) {
            leftSum += apple[i];
            while(leftSum > rightSum) {
                j++;
                rightSum += capacity[j];
            }
        }
        return j+1;
    }