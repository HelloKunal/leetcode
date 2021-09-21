class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int numsSize = nums.size();
        vector<int> dpArray(numsSize);
        
        int res = INT_MIN;
        for(int i = 0; i < numsSize; i++) {
            
            int maxVal = 0;
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    maxVal = max(maxVal, dpArray[j]);
                }
            }
            
            dpArray[i] = maxVal + 1;
            res = max(res, dpArray[i]);
        }
        
        return res;
    }
};