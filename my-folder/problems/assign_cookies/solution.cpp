class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        int noOfChildren = g.size();
        int noOfCookies = s.size();
        
        sort (g.begin(), g.end());
        sort (s.begin(), s.end());
        
        int noOfContentChildren = 0;
        while (noOfCookies > 0 && noOfChildren > 0)
        {
            if (s[noOfCookies - 1] >= g[noOfChildren - 1])
            {
                noOfContentChildren++;
                noOfCookies--;
            }
            noOfChildren--;
        }
        
        return noOfContentChildren;
    }
};