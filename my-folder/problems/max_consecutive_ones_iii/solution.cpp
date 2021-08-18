class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int numsSize = nums.size();
        int i = 0, j = 0;
        int count = 0;
        int res = INT_MIN;
        
        while (i < numsSize)
        {
            if (nums[i] == 0) count++;
            
            while (count > k && j < numsSize)
            {
                if (nums[j] == 0)
                    count--;
                j++;
            }
            
            res = max (res, i - j + 1);
            i++;
        }
        
        return res;
        
    }
};