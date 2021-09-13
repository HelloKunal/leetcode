class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_best = 0, best = nums[0];
        for(int i : nums) {
            curr_best += i;
            
            if(curr_best > best) {
                best = curr_best;
            }
            if(curr_best < 0) {
                curr_best = 0;
            }
        }
        
        return best;
    }
};