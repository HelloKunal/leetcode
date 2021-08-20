class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int numsSize = nums.size();
        int res = numsSize + 1;
        
        deque<int> d;
        int i = 0;
        for (i = 0; i < numsSize; i++)
        {
            if (i > 0)
                nums[i] += nums[i-1];
            
            if (nums[i] >= k)
                res = min(res, i+1);
            
            while (d.size() > 0 && nums[i] - nums[d.front()] >= k)
            {
                res = min(res, i - d.front());
                d.pop_front();
            }
            
            while (d.size() > 0 && nums[i] <= nums[d.back()])
            {
                d.pop_back();
            }
            
            d.push_back(i);
            
        }
        
        return (res <= numsSize) ? res: -1;        
    }
};