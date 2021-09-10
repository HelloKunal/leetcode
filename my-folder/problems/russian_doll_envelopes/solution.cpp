class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        
        vector<int> dp(envelopes.size());
        int omax = 0;
        for(int i = 0; i < envelopes.size(); i++) {
            
            int tmax = 0;
            for(int j = 0; j < i; j++) {
                if(envelopes[j][1] < envelopes[i][1] && envelopes[j][0] < envelopes[i][0]) {
                    if(dp[j] > tmax) {
                        tmax = dp[j];
                    }
                }
            }
            
            dp[i] = tmax + 1;
            if(dp[i] > omax) {
                omax = dp[i];
            }
        }
        
        return omax;    
        
    }
};