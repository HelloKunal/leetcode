class Solution {
public:
    string simplifyPath(string path) {
        vector<string> str;
        int n = path.length();
        
        for (int i = 0; i < n; i++)
        {
            string s = "";
            while (path[i] != '/' && i < n)
            {
                s += path[i];
                i++;
            }
            
            if (s == "" || s == ".")    continue;
            if (s == ".." && !str.empty())  str.pop_back();
            else if (s != "..") str.push_back (s);
            
        }
        string ans = "";
        for (auto s : str)
            ans += "/" + s;
        
        return str.empty() ? "/" : ans;
    }
};