class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix[0].size();
        int n = matrix.size();
        vector<vector<int>> dpSq(n, vector<int> (m));
        
        int res = 0;
        for(int y = n-1; y >= 0; y--) {
            for(int x = m-1; x >= 0; x--) {
                if(y == n-1 || x == m-1) {
                    dpSq[y][x] = matrix[y][x] - '0';
                } else {
                    if(matrix[y][x] == '0') dpSq[y][x] = 0;
                    else {
                        dpSq[y][x] = min(dpSq[y+1][x+1], min(dpSq[y+1][x], dpSq[y][x+1])) + 1;
                    }
                }
                
                res = max(res, dpSq[y][x]);
            }
        }
        
        return res*res;
    }
};