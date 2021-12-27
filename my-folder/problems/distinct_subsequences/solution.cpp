#define ll unsigned long long

class Solution {
public:
    int numDistinct(string s, string t) {
        int sLen = s.length(), tLen = t.length();
        vector<vector<ll>> dp(tLen+1, vector<ll> (sLen+1));
        
        // empty string cant have another string as subsequence
        for(int i = 0; i <= tLen; i++) dp[i][0] = 0;
        // empty string is subsequence after all
        for(int i = 0; i <= sLen; i++) dp[0][i] = 1;
        
        for(int i = 1; i <= tLen; i++) {
            for(int j = 1; j <= sLen; j++) {
                if(t[i-1] != s[j-1]) {
                    dp[i][j] = dp[i][j-1];
                } else {
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                }
            }
        }        
        
        return dp[tLen][sLen];
    }
};