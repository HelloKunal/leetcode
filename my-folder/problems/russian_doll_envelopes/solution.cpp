class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        
        int n = envelopes.size();
        vector<int> dpLIS(n);
        int oMax =0;
        for(int i = 0; i < n; i++) {
            
            int tmax = 0;
            for(int j = 0; j < i; j++) {
                if(envelopes[i][1] > envelopes[j][1] && envelopes[i][0] > envelopes[j][0]) {
                    tmax = max(tmax, dpLIS[j]);
                }
            }
            
            dpLIS[i] = tmax + 1;
            oMax = max(oMax, dpLIS[i]);
        }
        
        return oMax;
    }
};