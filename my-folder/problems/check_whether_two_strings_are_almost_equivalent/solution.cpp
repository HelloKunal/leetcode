class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int wf1[26] = {0};
        int wf2[26] = {0};
        int n = word1.length();
        for(int i = 0; i < n; i++) {
            wf1[word1[i]-'a']++;
            wf2[word2[i]-'a']++;
        }
        
        bool ret = true;
        for(int i = 0; i < 26; i++) {
            if(abs(wf1[i]-wf2[i]) > 3) {
                ret = false;
                break;
            }
        }
        
        return ret;
    }
};