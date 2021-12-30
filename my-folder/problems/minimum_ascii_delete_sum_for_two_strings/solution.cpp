class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> DP(s1.length()+1, vector<int> (s2.length()+1));
        for(int i = s1.length(); i >= 0; i--) {
            for(int j = s2.length(); j >= 0; j--) {
                if(i == s1.length() && j == s2.length()) DP[i][j] = 0;
                else if(i == s1.length()) DP[i][j] = s2[j] + DP[i][j+1];
                else if(j == s2.length()) DP[i][j] = s1[i] + DP[i+1][j];
                else {
                    if(s1[i] == s2[j]) DP[i][j] = DP[i+1][j+1];
                    else DP[i][j] = min(s1[i] + DP[i+1][j], s2[j] + DP[i][j+1]);
                }
            }
        }
        
        return DP[0][0];
    }
};