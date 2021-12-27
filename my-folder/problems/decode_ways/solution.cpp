class Solution {
public:
    int numDecodings(string s) {
        int sLen = s.length();
        vector<int> dp(sLen+1);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        
        for(int i = 2; i <= sLen; i++) {
            int oneDigit = stoi(s.substr(i-1, 1));
            int twoDigit = stoi(s.substr(i-2, 2));
            
            if(oneDigit >= 1) {
                dp[i] += dp[i-1];
            }
            
            if(twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i-2];
            }
        }        
        
        return dp[sLen];
    }
};