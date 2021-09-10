class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        if(n == 1) return {nums[0]};
        vector<int> dp(n);
        dp[0] = 1;
        int omax = 0;
        for(int i = 1; i < n; i++) {
            int tmax = 0;
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0) {
                    if(dp[j] > tmax) {
                        tmax = dp[j];
                    }
                }
            }
            dp[i] = tmax + 1;
            
            if(dp[i] > omax) {
                omax = dp[i];
            }
        }
        
        vector<int> res;
        int prev = -1;
        for(int i = n-1; i >= 0; i--) {
            if(dp[i] == omax && (prev%nums[i] == 0 || prev == -1)) {
                res.push_back(nums[i]);
                omax--;
                prev = nums[i];
            }
        }
        
        return res;
    }
};