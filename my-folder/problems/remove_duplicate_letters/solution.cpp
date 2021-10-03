class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> letterCount(256, 0);
        vector<bool> letterPreset(256, false);
        
        for(char c : s) {
            letterCount[c]++;
        }
        
        string res = "0";
        for(char c : s) {
            letterCount[c]--;
            if(letterPreset[c]) continue;
            
            while(res.back()>c && letterCount[res.back()]) {
                letterPreset[res.back()] = false;
                res.pop_back();
            }
            
            res += c;
            letterPreset[c] = true;
        }
        
        return res.substr(1);
    }
};