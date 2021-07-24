class Solution {
public:
    vector<int> lpsarray (string needle, int n)
    {
        vector<int> temp (n, 0);
        int len = 0;
        for (int i = 1; i < n;)
        {
            if (needle[i] == needle[len])
            {
                temp[i++] = ++len;
            }
            else if (len)
            {
                len = temp[len - 1];
            }
            else
            {
                temp[i++] = 0;
            } 
        }
        
        return temp;
    }
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        
        if (n == 0)
            return 0;
        
        vector<int> lps = lpsarray(needle, n);
        for (int i = 0, j = 0; i < m;)
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            
            if (j == n)
            {
                return i - j;
                j = lps[j - 1];
            }
            
            if (i < m && haystack[i] != needle[j])
            {
                j ? j = lps[j - 1] : i++;
            }
        }
        
        return -1;
    }
};