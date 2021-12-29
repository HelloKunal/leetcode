class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int omax = 0;
        int n = pairs.size();
        vector<int> DP(n);
        for(int i = 0; i < n; i++) {
            int tmax = 0;
            for(int j = 0; j < i; j++) {
                if(pairs[j][1] < pairs[i][0]) {
                    tmax = max(tmax, DP[j]);
                }
            }
            
            DP[i] = tmax + 1;
            omax = max(omax, DP[i]);
        }
        
        
        return omax;
    }
};