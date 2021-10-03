class Solution {
public:
    int minimumMoves(string s) {
        int stringLen = s.length();
        int res = 0;
        for(int i = 0; i < stringLen; i++) {
            if(s[i] == 'X') {
                s[i] = 'O';
                if(i+1 < stringLen) s[i+1] = 'O';
                if(i+2 < stringLen) s[i+2] = 'O';                
                res++;
            }
        }
        
        return res;
    }
};