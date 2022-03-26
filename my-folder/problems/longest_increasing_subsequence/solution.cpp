class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> LISArray(n, 1);
        
        int LIS = 0;
        for(int i = 0; i < n; i++) {
            
            int maxBefore = 0;
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    maxBefore = max(maxBefore, LISArray[j]);
                }
            }
            
            LISArray[i] = maxBefore + 1;
        }
        
        return *max_element(LISArray.begin(), LISArray.end());
    }
};