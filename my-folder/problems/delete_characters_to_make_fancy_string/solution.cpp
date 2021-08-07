class Solution {
public:
    string makeFancyString(string s) {
        int lengthOfString = s.length();
        if (lengthOfString < 3)
            return s;
        
        string fancyString = "";
        
        for (int i = 0; i < lengthOfString; i++)
        {
            int consecutiveCommonChar = 1;
            if (s[i] == s[i+1] && i < lengthOfString - 1)
            {
                while (s[i] == s[i+1])
                {
                    consecutiveCommonChar++;
                    i++;
                }
                
                consecutiveCommonChar = (consecutiveCommonChar >= 3) ? 2 : consecutiveCommonChar;
                for (int j = 0; j < consecutiveCommonChar; j++)
                    fancyString += s[i];
                
            }
            else            
                fancyString += s[i];
        }
        
        return fancyString;
    }
};