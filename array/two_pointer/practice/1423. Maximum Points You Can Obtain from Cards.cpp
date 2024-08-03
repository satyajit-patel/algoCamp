 /*
        Input: cardPoints = [1,2,3,4,5,6,1], k = 3
        Output: 12
    */

    int maxScore(vector<int>& cardPoints, int k) {
        int maxPoint = INT_MIN;
        int n = cardPoints.size();

        int leftSum = 0;
        for(int i=0; i<k; i++) {
            leftSum += cardPoints[i];
        }
        maxPoint = max(maxPoint, leftSum);
        int j = n-1;
        for(int i=k-1; i>=0; i--) {
            leftSum -= cardPoints[i];
            leftSum += cardPoints[j];
            j--;
            maxPoint = max(maxPoint, leftSum);
        }

        return maxPoint;
    }