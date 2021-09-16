class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int numSize = nums.size();
        if(numSize <= 2) {
            return numSize;
        }
        vector<unordered_map<int, int>> dp(numSize);
        int maxLen = 2;
        for(int i = 0; i < numSize; i++) {
            for(int j = i+1; j < numSize; j++) {
                int k = nums[j] - nums[i];
                if(dp[i].find(k) != dp[i].end()) {
                    dp[j][k] = dp[i][k] + 1;
                } else {
                    dp[j][k] = 2;
                }
                
                maxLen = max(maxLen, dp[j][k]);
            }
        }
        
        return maxLen;
    }
};