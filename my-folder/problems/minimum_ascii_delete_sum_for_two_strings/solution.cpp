class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dpArr(s1.length()+1, vector<int> (s2.length()+1));
        for(int i = s1.length(); i >= 0; i--) {
            for(int j = s2.length(); j >= 0; j--) {
                if(i == s1.length() && j == s2.length()) {
                    dpArr[i][j] = 0;
                } else if(i == s1.length()) {
                    dpArr[i][j] = (int)s2[j] + dpArr[i][j+1];
                } else if(j == s2.length()) {
                    dpArr[i][j] = (int)s1[i] + dpArr[i+1][j];
                } else {
                    if(s1[i] == s2[j]) {
                        dpArr[i][j] = dpArr[i+1][j+1];
                    } else {
                        dpArr[i][j] = min((int)s1[i] + dpArr[i+1][j], (int)s2[j] + dpArr[i][j+1]);
                    }                    
                }
            }
        }
        
        return dpArr[0][0];
    }
};