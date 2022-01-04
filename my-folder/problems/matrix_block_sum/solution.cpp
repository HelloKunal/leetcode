class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> preSum(m, vector<int> (n));
        for(int i = 0; i < m; i++) {
            int sumHere = 0;
            for(int j = 0; j < n; j++) {
                sumHere += mat[i][j];
                preSum[i][j] = sumHere;
            }
        }
        
        vector<vector<int>> res;
        for(int i = 0; i < m; i++) {
            vector<int> temp;
            for(int j = 0; j < n; j++) {
                int sumHere = 0;
                for(int r = i - k; r <= i+k; r++) {
                    if(r < 0) continue;
                    if(r >= m) break;
                    int right = min(n-1, j+k);
                    int left = max(-1, j-k-1);
                    sumHere += preSum[r][right];
                    if(left >= 0) sumHere -= preSum[r][left];
                }
                temp.push_back(sumHere);
            }
            res.push_back(temp);
        }
        
        return res;
    }
};