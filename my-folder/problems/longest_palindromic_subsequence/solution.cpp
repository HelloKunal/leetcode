class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int stringLen = s.length();
        vector<vector<int>> dpArray(stringLen, vector<int> (stringLen));
        
        for(int g = 0; g < stringLen; g++) {
            for(int i = 0, y = g; y < stringLen; y++, i++) {
                
                if(g == 0) dpArray[i][y] = 1;
                else if(g == 1) {
                    if(s[i] == s[y]) dpArray[i][y] = 2;
                    else dpArray[i][y] = 1;                
                }
                else {
                    if(s[i] == s[y]) dpArray[i][y] = 2 + dpArray[i+1][y-1];
                    else dpArray[i][y] = max(dpArray[i][y-1], dpArray[i+1][y]);
                }
            }
        }
        
        return dpArray[0][stringLen-1];
    }
};