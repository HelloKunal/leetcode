class Solution {
public:
    bool isMatch(string s, string p) {
        int pLen = p.length();
        int sLen = s.length();
        
        vector<vector<bool>> dpArray(pLen+1, vector<bool> (sLen+1));
        for(int y = pLen; y >= 0; y--) {
            for(int x = sLen; x >= 0; x--) {
                if(y == pLen && x == sLen) dpArray[y][x] = true;
                else if(y == pLen) dpArray[y][x] = false;
                else if(x == sLen) dpArray[y][x] = (p[y] == '*') ? dpArray[y+1][x] : false;
                else {
                    if(p[y] == '*') {
                        dpArray[y][x] = dpArray[y+1][x] || dpArray[y][x+1];
                    } else if(p[y] == '?') {
                        dpArray[y][x] = dpArray[y+1][x+1];
                    } else {
                        if(s[x] == p[y]) dpArray[y][x] = dpArray[y+1][x+1];
                        else dpArray[y][x] = false;
                    }
                }
            }
        }
        
        return dpArray[0][0];
    }
};