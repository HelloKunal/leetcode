class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return slidingWindow(nums, goal) - slidingWindow(nums, goal-1);
    }
    
    // at most goal sum
    int slidingWindow(vector<int> &nums, int goal) {
        if(goal < 0)    return 0;
        int left = 0, right = 0;
        int res = 0;
        for(right = 0; right < nums.size(); right++) {
            goal -= nums[right];
            
            while(goal < 0) {
                goal += nums[left];
                left++;
            }
            
            res += right - left + 1;
        }
        
        return res;
    }
};