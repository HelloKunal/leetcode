class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int res = 0;
        vector<vector<int>> gapDP(n, vector<int> (n));
        for(int g = 0; g < n; g++) {
            for(int i = 0, j = g; j < n; i++, j++) {
                if(g == 0) {
                    gapDP[i][j] = true;
                    res++;
                } else if(g == 1) {
                    if(s[i] == s[j]) {gapDP[i][j] = true; res++;}
                    else gapDP[i][j] = false;
                } else {
                    if(s[i] == s[j] && gapDP[i+1][j-1]) {gapDP[i][j] = true; res++;}
                    else gapDP[i][j] = false;
                }
            }
        }
        
        return res;
    }
};