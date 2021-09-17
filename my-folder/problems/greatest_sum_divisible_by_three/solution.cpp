class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        
        vector<int> dp(3);
        for(int num : nums) {
            for(int i : vector<int>(dp)) {
                dp[(num+i) % 3] = max(dp[(num+i)%3], num+i);
            }
        }
        
        return dp[0];
    }
};