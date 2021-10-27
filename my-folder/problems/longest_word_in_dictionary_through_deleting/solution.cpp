bool compareS(string a, string b) {
    if(a.size() == b.size()) {
        return b > a;
    }
    return a.size() > b.size();
}

class Solution {
public:
    bool dfs(string str, int curr, vector<int> adj[], int prev) {
        if(curr == str.length()) return true;
        if((adj[str[curr]].size() == 0)) return false;
        
        for(int next : adj[str[curr]]) {
            if(next > prev) {
                return dfs(str, curr+1, adj, next);
            }
        }
        
        return false;
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        vector<string> res;
        vector<int> adj[256];
        for(int i = 0; i < s.length(); i++) {
            adj[s[i]].push_back(i);
        }      


        vector<string> ans;
        for(string str : dictionary) {
            if(dfs(str, 0, adj, -1)) ans.push_back(str);
        }
        sort(ans.begin(), ans.end(), compareS);
        return ans.size() == 0 ? "" : ans[0];
    }
};