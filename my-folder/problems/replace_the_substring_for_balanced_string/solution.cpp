class Solution {
public:
    int balancedString(string s) {
        int sLength = s.length();
        int res = sLength;
        
        unordered_map<char, int> um;
        int i = 0, j = 0, k = sLength/4;
        for (char c : s)
        {
            um[c]++;
        }
        
        for(i = 0; i < sLength; i++)
        {
            um[s[i]]--;
            
            while (j < sLength && um['Q'] <= k && um['W'] <= k && um['E'] <= k && um['R'] <= k)
            {
                res = min (res, i-j+1);
                um[s[j]]++;
                j++;
            }
            
        }
        
        return res;        
    }
};