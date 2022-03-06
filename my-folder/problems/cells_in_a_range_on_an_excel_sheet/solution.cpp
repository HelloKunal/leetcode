class Solution {
public:
    vector<string> cellsInRange(string s) {
        char startLet = s[0], endLet = s[3];
        int startNum = s[1] - '0', endNum = s[4] - '0';
        
        vector<string> res;
        for(char i = startLet; i <= endLet; i++) {
            for(int j = startNum; j <= endNum; j++) {
                string oneRes = "";
                oneRes+=i;
                oneRes+=to_string(j);
                res.push_back(oneRes);
            }
        }
        
        return res;
    }
};