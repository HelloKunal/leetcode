class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int numsSize = nums.size();
        vector<int> res;
        if (numsSize == 0 || k == 0)
        {
            return res;
        }
        
        deque<int> d;
        for (int i = 0; i < numsSize; i++)
        {
            while (d.size() > 0 && d.front() < i - k + 1)
            {
                d.pop_front();
            }
            
            while (d.size() > 0 && nums[d.back()] < nums[i])
            {
                d.pop_back();
            }
            
            d.push_back(i);
            if (i >= k - 1)
            {
                res.push_back(nums[d.front()]);
            }
        }
        
        return res;
        
    }
};