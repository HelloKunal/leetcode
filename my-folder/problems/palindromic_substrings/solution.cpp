class Solution {
public:
    int countSubstrings(string s) {
        int size_s = s.length();
        vector<vector<bool>> dpArr(size_s, vector<bool>(size_s, false));
        
        int res = 0;
        for(int g = 0; g < size_s; g++) {
            for(int i = 0, j = g; j < size_s; i++, j++) {
                if(g == 0) {
                    dpArr[i][j] = true;
                    res++;
                } else if(g == 1) {
                    if(s[i] == s[j]) {
                        dpArr[i][j] = true;
                        res++;
                    }
                } else {
                    if(s[i] == s[j]) {
                        if(dpArr[i+1][j-1] == true) {
                            res++;
                            dpArr[i][j] = true;
                        }
                    }
                }
            }
        }
        
        return res;
    }
};