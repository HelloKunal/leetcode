class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        vector<int> dpLIS(n);
        int omax = 0;
        for(int i = 0; i < n; i++) {
            
            int tmax = 0;
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0) {
                    tmax = max(tmax, dpLIS[j]);
                }
            }
            
            dpLIS[i] = tmax + 1;
            omax = max(omax, dpLIS[i]);
        }
        
        vector<int> res;
        int prev = -1;
        for(int i = n-1; i >= 0; i--) {
            if(dpLIS[i] == omax && (prev % nums[i] == 0 || prev == -1)) {
                prev = nums[i];
                omax--;
                res.push_back(nums[i]);
            }
        }
        
        return res;
    }
};