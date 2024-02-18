 /*
        Input: nums = [3,2,1,4,5]
        Output: 2
        Explanation: We perform the following operations:
        - Delete the first two elements, with score 3 + 2 = 5, nums = [1,4,5].
        - Delete the first two elements, with score 1 + 4 = 5, nums = [5].
        We are unable to perform any more operations as nums contain only 1 element.
    
        Constraints:
        2 <= nums.length <= 100
        1 <= nums[i] <= 1000
        
        f(n) = O(n^4)
        
        // debug
        Input:
        [2,2,3,2,4,2,3,3,1,3]
        Output:
        2
        Expected:
        1
    */
    
    int maxOperations(vector<int>& nums) {
        int opr = 0;
        int prevScore = 0;
        int n = nums.size();
        int i = 0;
        while(i<n) {
            if(i+1 < n) {
                int curScore = nums[i] + nums[i+1];
                if(prevScore==0 || prevScore==curScore) {
                    opr++;
                    prevScore = curScore;
                } else {
                    break;
                }
            }
            i += 2;
        }
        return opr;
    }