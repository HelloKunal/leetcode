class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> gapDP(n, vector<int> (n, 0));
        
        // gap strategy
        for(int g = 0; g < n; g++) {
            for(int i = 0, j = g; j < n; i++, j++) {
                
                int miTemp = INT_MIN;
                for(int k = i; k <= j; k++) {
                    int left = k == i ? 0 : gapDP[i][k-1];
                    int right = k == j ? 0 : gapDP[k+1][j];
                    
                    int val = nums[k];                    
                    if(i > 0) val *= nums[i-1];          
                    if(j < n-1) val *= nums[j+1];
                    
                    int total = left + right + val;
                    miTemp = max(miTemp, total);                    
                }
                
                gapDP[i][j] = miTemp;
            }
        }
        
        return gapDP[0][n-1];
    }
};