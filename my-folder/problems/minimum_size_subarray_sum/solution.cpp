class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int numsSize = nums.size();
        int res = numsSize + 1;
        
        int i = 0, j = 0;
        for (i = 0; i < numsSize; i++)
        {
            k -= nums[i];
            
            while (k <= 0 && j < numsSize)
            {
                res = min (res, i-j+1);
                k += nums[j];
                j++;
            }
            
        }
        
        return res % (numsSize + 1);       
    }
};