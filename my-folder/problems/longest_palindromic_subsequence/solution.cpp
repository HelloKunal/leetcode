class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int sLen = s.length();
        
        vector<vector<int>> dpArr(sLen+1, vector<int> (sLen+1));
        for(int i = 0; i <= sLen; i++) dpArr[i][0] = 0;
        for(int i = 0; i <= sLen; i++) dpArr[0][i] = 0;
        
        string copyS = s;
        reverse(s.begin(), s.end());
        for(int i = 1; i <= sLen; i++) {
            for(int j = 1; j <= sLen; j++) {
                if(s[i-1] == copyS[j-1]) {
                    dpArr[i][j] = 1 + dpArr[i-1][j-1];
                } else {
                    dpArr[i][j] = max(dpArr[i-1][j], dpArr[i][j-1]);
                }
            }
        }
        
        return dpArr[s.length()][s.length()];
     }
};