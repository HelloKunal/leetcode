class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target+1);
        dp[0] = 1;
        for(int i = 1; i <= target; i++) {
            dp[i] = 0;
            for(int j : nums) {
                if(i >= j) dp[i] += dp[i-j];
                if(dp[i] > INT_MAX) break;
            }
            
        }
        
        return dp[target];
    }
};