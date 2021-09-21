class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int yMax = matrix.size();
        int xMax = matrix[0].size();
        int maxSide = 0;
        
        vector<vector<int>> dpArr(yMax, vector<int> (xMax));
        for(int y = 0; y < yMax; y++) dpArr[y][xMax-1] = matrix[y][xMax-1] - '0', maxSide = max(maxSide, dpArr[y][xMax-1]);
        for(int x = 0; x < xMax; x++) dpArr[yMax-1][x] = matrix[yMax-1][x] - '0', maxSide = max(maxSide, dpArr[yMax-1][x]);
        
        for(int y = yMax-2; y >= 0; y--) {
            for(int x = xMax-2; x >= 0; x--) {
                if(matrix[y][x] == '0') dpArr[y][x] = 0;
                else dpArr[y][x] = min(dpArr[y+1][x+1], min(dpArr[y+1][x], dpArr[y][x+1])) + 1;
                
                maxSide = max(maxSide, dpArr[y][x]);
            }
        }
        
        return maxSide*maxSide;
    }
};