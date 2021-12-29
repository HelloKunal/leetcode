class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int sum = 0;
        for(int n : nums) sum += n;
        int n = nums.size();
        vector<vector<int>> dpArr(n, vector<int> (n));
        
        for(int g = 0; g < n; g++) {
            for(int i = 0, j = g; j < n; i++, j++) {
                if(g == 0) {
                    dpArr[i][j] = nums[i];
                } else if(g == 1) {
                    dpArr[i][j] = max(dpArr[i][j-1], dpArr[i+1][j]);
                } else {
                    int val1 = nums[j] + min(dpArr[i][j-2], dpArr[i+1][j-1]);
                    int val2 = nums[i] + min(dpArr[i+2][j], dpArr[i+1][j-1]);
                    
                    dpArr[i][j] = max(val1, val2);
                }
            }
        }

        return dpArr[0][n-1] >= (sum - dpArr[0][n-1]);
    }
};