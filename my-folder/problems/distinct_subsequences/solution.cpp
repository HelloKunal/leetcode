class Solution {
public:
    int numDistinct(string s, string t) {
        int len_s = s.length();
        int len_t = t.length();
        
        vector<vector<unsigned long long>> dp(len_t+1, vector<unsigned long long>(len_s+1, 0));
        for(int i = 1; i <= len_s; i++) {
            if(t[0] == s[i-1]) {
                dp[1][i] = dp[1][i-1] + 1;
            } else {
                dp[1][i] = dp[1][i-1];
            }
        }
        for(int i = 2; i <= len_t; i++) {
            for(int j = 1; j <= len_s; j++) {
                if(t[i-1] == s[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1]; 
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        
        return dp[len_t][len_s];
    }
};