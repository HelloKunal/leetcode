class Solution {
public:
    int characterReplacement(string s, int k) {
        int sLength = s.length();
        int res = 0;
        
        int i = 0, j = 0;
        int maxCount = 0;
        vector<int> sArr(26, 0);
        for (i = 0; i < sLength; i++)
        {
            sArr[s[i]-'A']++;
            
            maxCount = max(maxCount, sArr[s[i]-'A']);
            
            if ((i-j+1) - maxCount > k)
            {
                sArr[s[j]-'A']--;
                j++;
            }
            
            res = max(res, i-j+1);
        }
        
        return res;
    }
};