class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> gapDP(n, vector<int> (n));
        
        for(int g = 0; g < n; g++) {
            for(int i = 0, j = g; j < n; i++, j++) {
                if(g == 0 || g == 1) gapDP[i][j] = 0;
                else if(g == 2) gapDP[i][j] = values[i] * values[i+1] * values[i+2];
                else {
                    int tmin = INT_MAX;
                    for(int k = i+1; k < j; k++) {
                        int triangle = values[i]*values[j]*values[k];
                        tmin = min(tmin, triangle+gapDP[i][k]+gapDP[k][j]);
                    }   
                    
                    gapDP[i][j] = tmin;
                }                
            }
        }
        
        return gapDP[0][n-1];        
    }
};