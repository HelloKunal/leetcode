class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int yMax = matrix.size();
        int xMax = matrix[0].size();
        
        int start = 0, end = yMax*xMax -1;
        while(end != start) {
            int mid = (start + end - 1) / 2;
            int ele = matrix[mid / xMax][mid % xMax];
            if(ele == target) return true;
            else if(ele < target) {
                start = mid+1;
            } else {
                end = mid;
            }
        }
        
        if(matrix[end / xMax][end % xMax] == target) return true;
        return false;
    }
};