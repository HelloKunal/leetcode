class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        
        while (high >= low)
        {
            int mid = (high + low) >> 1;
            if (nums[mid] == target)
                return mid;
            
            else if (nums[mid] >= nums[low])
            {
                if (nums[mid] >= target && nums[low] <= target)
                {
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            else
            {
                if (nums[high] >= target && nums[mid] <= target)
                {
                    low = low + 1;                    
                }
                else
                    high = mid -1;
            }
        }
        
        return -1;
    }
};