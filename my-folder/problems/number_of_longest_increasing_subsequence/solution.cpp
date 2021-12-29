class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> DP(n);
        vector<int> countArr(n, 1);
        int omax = 0;
        for(int i = 0; i < n; i++) {
            int tmax = INT_MIN;
            for(int j = 0; j < i; j++) { 
                if(nums[j] < nums[i]) {
                    if(DP[j] + 1 > DP[i]) {
                        DP[i] = DP[j] + 1;
                        countArr[i] = countArr[j];
                    } else if(DP[j] + 1 == DP[i]) {
                        countArr[i] += countArr[j];
                    }
                }
            }
        
            omax = max(omax, DP[i]);
        }
        
        
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(DP[i] == omax) res += countArr[i];
        }
        return res;
    }
};