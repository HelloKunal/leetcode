class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int sLength = s.length();
        int res = 0;
        
        int i = 0, j = 0;
        int cost = 0;
        for (i = 0; i < sLength; i++)
        {
            cost += abs(s[i]-t[i]);
            
            while (j < sLength && cost > maxCost)
            {
                cost -= abs(s[j]-t[j]);
                j++;
            }
            
            res = max(res, i-j+1);
        }
        
        return res;
    }
};