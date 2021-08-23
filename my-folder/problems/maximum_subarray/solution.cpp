class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArrayRec(nums, 0, nums.size() - 1);
        
    }
    
    int maxSubArrayRec(vector<int>& nums, int l, int r)
    {
        if(l > r)
        {
            return INT_MIN;
        }
        
        int m = l + (r-l)/2;
        int maxL = maxSubArrayRec(nums, l, m - 1);
        int maxR = maxSubArrayRec(nums, m + 1, r);
        
        int sumL = 0, sumR = 0;
        for(int i = m - 1, sum = 0; i >= l; i--)
        {
            sum += nums[i];
            sumL = max(sum, sumL);            
        }
        for(int i = m + 1, sum = 0; i <= r; i++)
        {
            sum += nums[i];
            sumR = max(sum, sumR);            
        }
        
        return max(max(maxL, maxR), sumL + sumR + nums[m]);
    }
};