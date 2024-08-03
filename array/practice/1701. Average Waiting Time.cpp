class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0;
        int n = customers.size();
        int startTime = 0;

        for(int i=0; i<n; i++) {
            int arrivalTime = customers[i][0];
            int burstTime = customers[i][1];

            if(startTime < arrivalTime) {
                startTime = arrivalTime;
            }

            int finistTime = (startTime + burstTime);
            int waitTime = finistTime - arrivalTime;

            startTime = finistTime;
            ans += waitTime;
        }

        return (ans / n);
    }
};