class Solution {
public:
    void dfs(int curr, string s, vector<string>& path, vector<vector<string>>& ret) {
        if(curr == s.length()) {
            ret.push_back(path);
            return;
        }
        
        for(int i = curr; i < s.length(); i++) {
            if(isPalindromic(s, curr, i)) {
                path.push_back(s.substr(curr, i-curr+1));
                dfs(i+1, s, path, ret);
                path.pop_back();
            }
        }
    }
    
    bool isPalindromic(string s, int i, int j) {
        while(i <= j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> path;
        if(s.size() == 0) return ret;
        
        dfs(0, s, path, ret);
        return ret;
    }
};