class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sLength = s.length();
        int res = 0, start = 0, end = 0;
        unordered_map<char, int> um;
        
        while (end < sLength)
        {
            um[s[end]]++;

            while (um[s[end]] > 1)
            {
                um[s[start]]--;
                start++;
            }
                   
            res = max (res, end - start + 1);
            end++;
        }
                   
        return res;
    }
};