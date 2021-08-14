class Solution {
public:
    bool canConstruct(string s, int k) {
        int sLength = s.length();
        vector<int> vt(26, 0);
        for (char c : s)
        {
            vt[c - 'a']++;
        }
        
        int odd = 0;
        int even = 0;
        for (int i = 0; i < 26; i++)
        {
            int t = vt[i];
            
            if (t % 2 == 1)
            {
                odd++;
                even += (t - 1) / 2;
            }
            else
            {
                even += t/2;
            }
        }
            
        if (k > sLength)
            return false;

        if (odd > k)
            return false;

        return true;
    }
};