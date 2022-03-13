class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(k == 0) return nums[0];
        if(nums.size() == 1 && k % 2 == 1) return -1;
        int maxEle = -1;
        
        int i = 0;
        for(i = 0; i < k-1 && i < nums.size(); i++) {
            maxEle = max(maxEle, nums[i]);
        }
        
        i++;
        if(i < nums.size() && nums[i] > maxEle) return nums[i];
        if(maxEle == -1) return -1;
        return maxEle;
        
    }
};