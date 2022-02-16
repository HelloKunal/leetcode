class Solution {
public:
    int strStr(string haystack, string needle) {
        int nedHash = 0;
        if(needle == "") return 0;
        if(haystack.length() < needle.length()) return -1;
        for(char c : needle) {
            nedHash += c - 'a';
        }
        
        int hayHash = 0;
        for(int i = 0; i < haystack.size(); i++) {
            hayHash += (haystack[i] - 'a');
            if(i >= needle.size() - 1) {
                if(hayHash == nedHash) {
                    // return 1;
                    bool pos = true;
                    for(int j = 0; j < needle.size(); j++) {
                        if(haystack[i + j - needle.size() + 1] != needle[j]) {
                            pos = false;
                            break;
                        }
                    }
                    
                    if(pos) return i - needle.size() + 1;
                }
                
                hayHash -= (haystack[i - needle.size() + 1] - 'a');
            }
        }
        
        return -1;
    }
};