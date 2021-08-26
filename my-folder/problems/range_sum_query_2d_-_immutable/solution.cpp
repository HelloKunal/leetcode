class NumMatrix {
public:
    vector<vector<int>> pSumMatrix;
    NumMatrix(vector<vector<int>>& matrix) {
        int xAxis = matrix[0].size();
        int yAxis = matrix.size();
        pSumMatrix.resize(yAxis+1, vector<int>(xAxis+1, 0));
        for(int i = 1; i <= yAxis; i++) {
            for(int j = 1; j <= xAxis; j++) {
                pSumMatrix[i][j] = pSumMatrix[i-1][j] + pSumMatrix[i][j-1] - pSumMatrix[i-1][j-1] + matrix[i-1][j-1];
            }
        }        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return (pSumMatrix[row2+1][col2+1] - pSumMatrix[row2+1][col1] - pSumMatrix[row1][col2+1] + pSumMatrix[row1][col1]);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */