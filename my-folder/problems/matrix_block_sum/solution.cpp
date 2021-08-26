class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int xAxis = mat[0].size();
        int yAxis = mat.size();
        vector<vector<int>> matrix(yAxis+1, vector<int>(xAxis+1, 0));
        for(int i = 1; i <= yAxis; i++) {
            for(int j = 1; j <= xAxis; j++) {
                matrix[i][j] += matrix[i][j-1] + matrix[i-1][j] - matrix[i-1][j-1] + mat[i-1][j-1];
            }
        }
        
        vector<vector<int>> answer(yAxis, vector<int>(xAxis));
        for(int i = 0; i < yAxis; i++) {
            for(int j = 0; j < xAxis; j++) {
               
                int top = i - k >= 0 ? i - k : 0;
                int bottom = i + k < yAxis ? i + k : yAxis-1;
                int right = j + k < xAxis ? j + k : xAxis-1;
                int left = j - k >= 0 ? j - k : 0;
                
                answer[i][j] = matrix[bottom+1][right+1] - matrix[bottom+1][left] - matrix[top][right+1] + matrix[top][left];
            }
        }
        
        return answer;
    }
};