// https://www.interviewbit.com/problems/meeting-rooms/

/*
    Input 1:
    A = [   [0, 30]
            [5, 10]
            [15, 20]
        ]
    Output 1:
    2 
*/

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int start[n], end[n];
    for(int i=0; i<n; i++) {
        start[i] = A[i][0];
        end[i] = A[i][1];
    }
    
    int maxi = INT_MIN;
    int i = 0, j = 0;
    int numOfRoom = 0;
    sort(start, start+n);
    sort(end, end+n);
    
    /*
        explanation
        0, 5, 15
        i
        10, 20, 30
        j 
    */
    while(i < n && j < n) {
        if(end[j] <= start[i]) {
            numOfRoom--;
            j++;
        } else {
            numOfRoom++;
            maxi = max(maxi, numOfRoom);
            i++;
        }
    }
    return maxi;
}
