class Solution {
public:
    bool canConstruct(string s, int k) {
        int sLen = s.length();
        vector<int> charCount(26, 0);
        for(char c : s) charCount[c-'a']++;
        
        int odd = 0, even = 0;
        for(int i = 0; i < 26; i++) {
            int count = charCount[i];
            
            if(count % 2 == 1) {
                odd++;
                even += (count-1)/2;
            } else {
                even += count/2;
            }
        }
        
        if(k > sLen) return false;
        if(odd > k) return false;
        return true;
    }
};