class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int size_n = nums.size();
        vector<vector<int>> dp(size_n, vector<int>(size_n));
        
        for(int g = 0; g < size_n; g++) {
            for(int i = 0, j = g; j < size_n; i++, j++) {
                
                int max_Ele = INT_MIN;
                for(int k = i; k <= j; k++) {
                    int left = k == i ? 0 : dp[i][k-1];
                    int right = k == j ? 0 : dp[k+1][j];
                    int curr = nums[k] * (i == 0 ? 1 : nums[i-1]) * (j == size_n-1 ? 1 : nums[j+1]);
                    
                    int total = left + right + curr;
                    max_Ele = max(max_Ele, total);
                }
                dp[i][j] = max_Ele;
            }
            
        }
        
        return dp[0][size_n-1];
    }
};