class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end(), greater<int> ());
        sort(g.begin(), g.end(), greater<int> ());
        
        int i = 0, res = 0;
        for(int j = 0; j < s.size() && i < g.size(); j++) {
            if(s[j] >= g[i]) res++;
            else j--;
            i++;
        }
        
        return res;
    }
};