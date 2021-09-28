class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool specialCase = matrix[0][0] == 0 ? true: false;
        bool row = false, col = false;
        int yMax = matrix.size(), xMax = matrix[0].size();
        if(specialCase == false) {
            for(int y = 1; y < yMax; y++) {
                if(matrix[y][0] == 0) row = true;
            }
            for(int x = 1; x < xMax; x++) {
                if(matrix[0][x] == 0) col = true;
            }
        }
        
        for(int y = 1; y < yMax; y++) {
            for(int x = 1; x < xMax; x++) {
                if(matrix[y][x] == 0) {
                    matrix[0][x] = 0;
                    matrix[y][0] = 0;
                }
            }
        }
        
        for(int y = 1; y < yMax; y++) {
            if(matrix[y][0] == 0) {
                for(int x = 1; x < xMax; x++) {
                    matrix[y][x] = 0;
                }
            }
        }
        for(int x = 1; x < xMax; x++) {
            if(matrix[0][x] == 0) {
                for(int y = 1; y < yMax; y++) {
                    matrix[y][x] = 0;
                }
            }
        }
        if(specialCase) {
            for(int y = 1; y < yMax; y++) {
                matrix[y][0] = 0;
            }
            for(int x = 1; x < xMax; x++) {
                matrix[0][x] = 0;
            }
        } else {
            if(col) {            
                for(int x = 0; x < xMax; x++) {
                    matrix[0][x] = 0;
                }
            }
            if(row) {
                for(int y = 0; y < yMax; y++) {
                    matrix[y][0] = 0;    
                }   
            }
        }
    }
};