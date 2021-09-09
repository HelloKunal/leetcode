class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        
        int res = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            int t = 0;
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    if(dp[j] > t) {
                        t = dp[j];
                    }
                }
            }
            
            dp[i] = t+1;
            res = max(res,dp[i]);
        }
        
        return res;
    }
};