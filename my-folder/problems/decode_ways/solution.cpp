class Solution {
public:
    int numDecodings(string s) {
        int stringLen = s.length();
        vector<int> dpArray(stringLen+1);
        
        dpArray[0] = 1;
        dpArray[1] = (s[0] == '0') ? 0 : 1;
        
        for(int i = 2; i <= stringLen; i++) {
            int oneDigit = stoi(s.substr(i-1, 1));
            int twoDigit = stoi(s.substr(i-2, 2));
            
            if(oneDigit >= 1) {
                dpArray[i] += dpArray[i-1];
            }
            
            if(twoDigit >= 10 && twoDigit <= 26) {
                dpArray[i] += dpArray[i-2];
            }
        }
        
        return dpArray[stringLen];
    }
};