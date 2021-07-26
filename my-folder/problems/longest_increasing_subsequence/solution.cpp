class Solution {
public:
    int lowerbound (vector<int>& ans, int X)
    {
        int mid, left = 0, right = ans.size();
        
        while (left < right)
        {
            mid = (left) + (right - left) / 2;
            
            if (ans[mid] >= X)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        
        if (left < ans.size() && ans[left] < X)
            left++;
        
        return left;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> ans;
        ans.push_back(nums[0]);
        int j = 0;
        
        for (int i = 1, y = nums.size(); i < y; i++)
        {
            if (nums[i] > ans.back())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                ans[lowerbound (ans, nums[i])] = nums[i];
            }
        }
        
        return ans.size();
    }
};