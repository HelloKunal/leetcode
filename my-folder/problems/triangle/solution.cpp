class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.back());
        int lvl = triangle.size();
        if(lvl == 1) {
            return triangle[0][0];
        }
        for(int layer = lvl-1; layer >= 0; layer--) {
            for(int i = 0; i < layer; i++) {
                dp[i] = min(dp[i], dp[i+1]) + triangle[layer-1][i];
            }
        }
        
        return dp[0];
    }
};