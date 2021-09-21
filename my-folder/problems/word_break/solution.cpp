class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int stringLen = s.length();
        vector<bool> dpArray(stringLen+1);
        dpArray[0] = true; // Null always present in wordDict
        
        for(int i = 1; i <= stringLen; i++) {
            for(int j = 0; j < i; j++) {
                if(dpArray[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end()) {
                    dpArray[i] = true;
                    break;
                }
            }
        }
        
        return dpArray[stringLen];
    }
};