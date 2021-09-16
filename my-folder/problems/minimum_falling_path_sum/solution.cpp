class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp1(matrix.back());
        vector<int> dp2(matrix.back());
        
        for(int layer = n-2; layer >= 0; layer--) {
            for(int i = 0; i < n; i++) {
                if(i == 0) {
                    dp2[i] = min(dp1[i], dp1[i+1]) + matrix[layer][i];
                    
                } else if(i == n-1) {
                    dp2[i] = min(dp1[i], dp1[i-1]) + matrix[layer][i];
                    
                } else {
                    dp2[i] = min(dp1[i], min(dp1[i-1], dp1[i+1])) + matrix[layer][i];
                }
            }
            swap(dp1, dp2);
        }
        
        int mini = INT_MAX;
        for(int i : dp1) {
            mini = min(mini, i);
        }
        
        return mini;
    }
};