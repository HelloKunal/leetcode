class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int yMax = matrix.size();
        int xMax = matrix[0].size();
        int y = 0, x = xMax-1;
        while(y >= 0 && x >= 0 && y < yMax && x < xMax) {
            if(matrix[y][x] == target) return true;
            else if(matrix[y][x] > target) {
                x--;
            } else {
                y++;
            }
        }
        
        return false; 
    }
};