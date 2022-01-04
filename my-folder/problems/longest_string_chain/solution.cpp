bool compare(string &a, string &b) {
    return a.length()<b.length();
}

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        int n = words.size();
        
        int omax = 0;
        unordered_map<string, int> DP;
        for(string word : words) {
            for(int i = 0; i < word.length(); i++) {
                string pre = word.substr(0, i) + word.substr(i+1);
                DP[word] = max(DP[word], DP.find(pre) == DP.end() ? 1 : DP[pre]+1);
            }
            
            omax = max(omax, DP[word]);
        }
        
        return omax;
    }
};