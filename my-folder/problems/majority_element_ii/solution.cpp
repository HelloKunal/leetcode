class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        if(nums.size() == 1) return {nums[0]};
        else if(nums.size() == 0) return {};
        int prev1 = nums[0];
        int prev2 = nums[1];
        int count1 = 0, count2 = 0;
        
        for(int num : nums) {
            if(num == prev1) count1++;            
            else if(num == prev2) count2++;            
            else if(count1 <= 0) {
                count1 = 1;
                prev1 = num;
            } else if(count2 <= 0) {
                count2 = 1;
                prev2 = num;
            } else count2--, count1--;
        }
        
        count1 = 0, count2 = 0;

        for(int num : nums) {
            if(num == prev1) count1++;
            else if(num == prev2) count2++;
        }
        
        vector<int> res;
        if(count1 > floor(nums.size()/3)) res.push_back(prev1);
        if(count2 > floor(nums.size()/3)) res.push_back(prev2);
        
        return res;
    }
};