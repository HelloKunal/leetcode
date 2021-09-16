class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int numDays = days.size();
        int numCost = costs.size();
        vector<int> DP(numDays+1, 365*costs[0]);
        DP[numDays] = 0;
        for(int i = numDays-1; i >= 0; i--) {
            int d7 = i, d30 = i;
            while(d7 < numDays && days[d7] < days[i] + 7) d7++;
            while(d30 < numDays && days[d30] < days[i] + 30) d30++;
            DP[i] = min({costs[0] + DP[i+1], costs[1] + DP[d7], costs[2] + DP[d30]});
        }
        
        return DP[0];
    }
};