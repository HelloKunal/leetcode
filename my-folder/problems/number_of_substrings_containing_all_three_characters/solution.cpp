class Solution {
public:
    int numberOfSubstrings(string s) {
        int sLength = s.length();
        int res = 0;
        
        int i = 0, j = 0;
        int count[3] = {0, 0, 0};
        int ans = 0;
        for (i = 0; i < sLength; i++)
        {
            count[s[i]-'a']++;
            
            while(count[0] && count[1] && count[2] && j<sLength)
            {
                ans++;
                count[s[j]-'a']--;
                j++;                
            }
            
            res += ans;
        }
        
        return res;
    }
};