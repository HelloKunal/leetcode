class Solution {
public:
    int minCut(string s) {
        vector<vector<bool>> gapDP(s.length(), vector<bool>(s.length()));
        
        for(int g = 0; g < s.length(); g++) {
            for(int i = 0, j = g; j < s.length(); i++, j++) {
                if(g == 0) {
                    gapDP[i][j] = true;
                } else if(g == 1) {
                    gapDP[i][j] = s[i] == s[j];
                } else {
                    if(s[i] == s[j] && gapDP[i+1][j-1] == true) {
                        gapDP[i][j] = true;
                    } else {
                        gapDP[i][j] = false;
                    }
                }
            }
        }
        
        vector<int> DP(s.length());
        for(int j = 1; j < s.length(); j++) {
            if(gapDP[0][j]) {
                DP[j] = 0;
            } else {                
                int min = INT_MAX;
                for(int i = j; i >= 1; i--) {
                    if(gapDP[i][j]) {
                        if(DP[i-1] < min) {
                            min = DP[i-1];
                        }
                    }
                }

                DP[j] = min+1;
            }
        }
        
        return DP[s.length()-1];
    }
};