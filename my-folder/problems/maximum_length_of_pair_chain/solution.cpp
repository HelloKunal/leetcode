class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int numPairs = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> dp(numPairs);
        
        int omax = 0;
        for(int i = 0; i < numPairs; i++) {
            int t = 0;
            for(int j = 0; j < i; j++) {
                if(pairs[j][1] < pairs[i][0]) {
                    if(dp[j] > t) {
                        t = dp[j];
                    }
                }
            }
            
            dp[i] = t + 1;
            omax = max(dp[i], omax);
        }
        
        return omax;
    }
};