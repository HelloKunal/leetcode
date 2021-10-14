class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> um;
        int res = 0, j = 0;
        for(int i = 0; i < s.length(); i++) {
            um[s[i]]++;
            
            while(um[s[i]] > 1) {
                um[s[j]]--;
                j++;
            }
            
            res = max(res , i-j+1);
        }
        
        return res;
    }
};