// naive is n2: look for first and last occurance of each letter. make intervaks and merge overlapping intervals.

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int sLength = s.length();
        vector<int> res;
        int lastLetterOcc [26];
        
        for (int i = 0; i < sLength; i++)
        {
            lastLetterOcc [s[i] - 'a'] = i;
        }
        
        int i = 0;
        while (i < sLength)
        {
            int end = lastLetterOcc[s[i] - 'a'];
            int j = i;
            while (j != end)
            {
                end = max (end, lastLetterOcc[s[j++] - 'a']);
            }
            
            res.push_back (j - i + 1);
            i = j + 1;
        }
        
        return res;
    }
};