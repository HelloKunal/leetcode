class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i = 1; i <= numRows; i++) {
            vector<int> temp(i, 1);
            if(i > 2) {
                for(int j = 2; j < i; j++) {
                    temp[j-1] = res[i-2][j-2] + res[i-2][j-1];
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};