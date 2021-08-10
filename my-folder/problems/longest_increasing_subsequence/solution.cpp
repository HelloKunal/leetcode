class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0;
        vector<int> dp(nums.size()) ;
        for(int i = 0; i < nums.size(); ++i){
            res = max(res, 1+rec(dp, nums, i));
        }
        return res;
    }
    
    int rec(vector<int>& dp, vector<int>& nums, int idx){
        if(idx==nums.size()) return 0;
        if (dp[idx]) return dp[idx];
        int res = 0;
        for(int i = idx+1; i<nums.size(); ++i){
            if(nums[i]>nums[idx]){
                res = max(res, 1+rec(dp, nums,i));
            }
        }
        return dp[idx] = res;
    }
};