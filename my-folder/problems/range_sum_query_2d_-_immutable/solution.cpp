class NumMatrix {
public:
    vector<vector<int>> mat; 
    NumMatrix(vector<vector<int>>& matrix) {
        int xAxis = matrix[0].size();
        int yAxis = matrix.size(); 
        mat.assign(yAxis+1, vector<int>(xAxis+1, 0));
        
        for(int y = 1; y <= yAxis; y++) {
            for(int x = 1; x <= xAxis; x++) {
                mat[y][x] = matrix[y-1][x-1] + mat[y-1][x] + mat[y][x-1] - mat[y-1][x-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // +1 because dp array start from 0
        int res = mat[row2+1][col2+1] - mat[row2+1][col1] - mat[row1][col2+1] + mat[row1][col1];
        
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */