class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        bool res = true;
        for(int y = 0; y < matrix.size(); y++) {
            vector<bool> temp(matrix.size()+1, false);
            for(int x = 0; x < matrix.size(); x++) {
                if(temp[matrix[y][x]]) {
                    res = false;
                    break;
                } else {
                    temp[matrix[y][x]] = true;
                }
            }
            if(!res) break;
        }
        
        if(!res) return false;
        
        for(int x = 0; x < matrix.size(); x++) {
            vector<bool> temp(matrix.size()+1, false);
            for(int y = 0; y < matrix.size(); y++) {
                if(temp[matrix[y][x]]) {
                    res = false;
                    break;
                } else {
                    temp[matrix[y][x]] = true;
                }
            }
            if(!res) break;
        }
        
        if(!res) return false;
        else return true;
    }
};