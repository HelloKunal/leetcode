class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        int n = len2;
        vector<int> dp(n+1);
        for(int i = 1; i <= n; i++) {
            dp[i] = i;
        }
        
        int pre;
        for(int i = 1; i <= len1; i++) {
            pre = dp[0];
            dp[0] = i;
            for(int j = 1; j <= len2; j++) {
                int temp = dp[j];
                if(word1[i-1] == word2[j-1]) dp[j] = pre;
                else dp[j] = min(pre, min(dp[j], dp[j-1])) + 1;
                pre = temp;
            }
        }
        
        return dp[n];
    }
};