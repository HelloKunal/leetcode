class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> gapDP(n, vector<bool> (n));
        
        for(int g = 0; g < n; g++) {
            for(int i = 0, j = g; j < n; i++, j++) {
                if(g == 0) gapDP[i][j] = true;
                else if(g == 1) gapDP[i][j] = s[i] == s[j];
                else {
                    if(s[i] == s[j] && gapDP[i+1][j-1]) gapDP[i][j] = true;
                    else gapDP[i][j] = false;
                }
            }
        }
        
        vector<int> DP(n);
        for(int j = 1; j < n; j++) {
            if(gapDP[0][j]) {
                // start to j whole palindrome
                DP[j] = 0;
            } else {
                // palindrome in between
                int mi = INT_MAX;
                for(int i = j; i >= 1; i--) {
                    if(gapDP[i][j]) {
                        mi = min(mi, DP[i-1]);
                    }
                }
                
                DP[j] = mi+1;                 
            }
        }
        
        return DP[n-1];
    }
};