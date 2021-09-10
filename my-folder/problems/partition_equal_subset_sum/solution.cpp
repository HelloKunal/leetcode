class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i : nums) {
            sum += i;
        }
        if(sum % 2 == 1) return false;
        int k = sum / 2;
        vector<vector<bool>> dp(nums.size()+1, vector<bool>(k+1, false));
        for(int i = 0; i <= nums.size(); i++) {
            for(int j = 0; j <= k; j++) {
                if(i == 0 && j == 0) dp[i][j] = true;
                else if(i == 0) dp[i][j] = false;
                else if(j == 0) dp[i][j] = true;
                else {
                    if(dp[i-1][j] == true) dp[i][j] = true;
                    else {
                        if(j >= nums[i-1]) {
                            if(dp[i-1][j-nums[i-1]] == true) dp[i][j] = true;
                        }
                    }
                }
            }
        }
        return dp[nums.size()][k];
    }
};