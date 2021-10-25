class Solution {
public:
    vector<int> partitionLabels(string s) {
        int stringLen = s.length();
        vector<int> sizeLabels;
        int lastOccurLetters[26];
        for(int i = 0; i < stringLen; i++) {
            lastOccurLetters[s[i] - 'a'] = i;
        }
        
        int i = 0;
        while(i < stringLen) {
            int lOL = lastOccurLetters[s[i] - 'a'];
            int j = i;
            while(j != lOL) {
                lOL = max(lOL, lastOccurLetters[s[j++] - 'a']);
            }
            
            sizeLabels.push_back(j-i+1);
            i = j+1;
        }
        
        return sizeLabels;
    }
};