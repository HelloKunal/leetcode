class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int numDays = days.size();
        vector<int> DP(numDays+1, 365*costs[0]);
        DP[numDays] = 0;
        for(int i = numDays-1; i >= 0; i--) {
            int dw = i, dm = i;
            while(dw < numDays && days[dw] < days[i] + 7) dw++;
            while(dm < numDays && days[dm] < days[i] + 30) dm++;
            DP[i] = min({costs[0] + DP[i+1], costs[1] + DP[dw], costs[2] + DP[dm]});
        }
        
        return DP[0];
    }
};