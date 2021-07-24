class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if (b.empty())
            return 0;
        
        vector<int> lps (b.size(), 0);
        for (int i = 1, len = 0; i < b.size();)
        {
            if (b[i] == b[len])
                lps[i++] = ++len;
            
            else if (len == 0)
                lps[i++] = 0;
            
            else
                len = lps[len - 1];
            
        }
        
        for (int i = 0, j = 0; j < a.size() + b.size();)
        {
            if (i == b.size())
                return (j - 1) / a.size() + 1;
            
            if (a[j % a.size()] == b[i])
            {
                i++;
                j++;
            }
            else if (i == 0)
                j++;
            else if (i > 0)
                i = lps[i - 1];
        }
        
        return -1;
    }
};