class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int yAxis = dungeon.size();
        int xAxis = dungeon[0].size();
        vector<vector<int>> dpDung(yAxis, vector<int> (xAxis));
        
        dpDung[yAxis-1][xAxis-1] = min(0, dungeon[yAxis-1][xAxis-1]);
        for(int i = yAxis-2; i >= 0; i--) {
            dpDung[i][xAxis-1] = min(0, dpDung[i+1][xAxis-1] + dungeon[i][xAxis-1]);
        }
        for(int i = xAxis-2; i >= 0; i--) {
            dpDung[yAxis-1][i] = min(0, dpDung[yAxis-1][i+1] + dungeon[yAxis-1][i]);
        }
        for(int i = yAxis-2; i >= 0; i--) {
            for(int j = xAxis-2; j >= 0; j--) {
                dpDung[i][j] = min(0, max(dpDung[i+1][j], dpDung[i][j+1]) + dungeon[i][j]);
            }
        }
        
        return abs(dpDung[0][0])+1;
    }
};