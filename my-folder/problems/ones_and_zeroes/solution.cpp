class Solution {
public:
    vector<vector<vector<int>>> memoArray;
    int findMaxForm(vector<string>& strs, int m, int n) {
        memoArray.assign(m+1, vector<vector<int>> (n+1, vector<int> (strs.size(), -1)));
        return findMaxFormUtil(strs, m, n, 0, 0);
    }
    
    int findMaxFormUtil(vector<string>& strs, int m, int n, int i, int maxSubset) {
        if(m < 0 || n < 0) return 0;
        if(i >= strs.size()) return 0;
        if(m == 0 && n == 0) return 0;
        if(memoArray[m][n][i] != -1) return memoArray[m][n][i];
        
        int localM = 0, localN = 0;
        for(char c : strs[i]) {
            if(c == '0') localM++;
            else if(c == '1') localN++;
        }
        
        if(m >= localM && n >= localN) return memoArray[m][n][i] = max(1 + findMaxFormUtil(strs, m-localM, n-localN, i+1, maxSubset+1), findMaxFormUtil(strs, m, n, i+1, maxSubset));
        else return findMaxFormUtil(strs, m, n, i+1, maxSubset);
    }
};