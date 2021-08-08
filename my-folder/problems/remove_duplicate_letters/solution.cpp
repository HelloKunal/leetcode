class Solution {
public:
    string removeDuplicateLetters(string s) {
        int sLength = s.length();
        vector<int> letterCount (256, 0);
        vector<bool> letterAlreadySelected (256, false);
        
        for (char c : s)
        {
            letterCount [c]++;
        }
        
        string res = "0";
        for (char c : s)
        {
            letterCount[c]--;
            
            if (letterAlreadySelected[c])
                continue;
            
            while (res.back() > c && letterCount[res.back()])
            {
                letterAlreadySelected[res.back()] = false;
                res.pop_back();
            }
            
            res += c;
            letterAlreadySelected[c] = true;
        }
        
        return res.substr(1);
    }
};