class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int prev = nums[0];
        int count = 1;
        for(int num : nums) {
            if(prev == num) count++;
            else count--;
            
            if(count == 0) prev = num, count++;
        }
        
        count = 0;
        for(int num : nums) {
            if(num == prev) count++;
        }
        
        if(count >= ceil(nums.size()/2)) return prev;
        else return -1;
    }
};