class Solution {
public:
    bool canJump(vector<int>& nums) {
        int msf = 0, ms = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            msf = max(msf, nums[i] + i);
            
            if(i == ms) {
                if(msf <= i && nums[i] == 0) {
                    return false;
                }
                ms = msf;
            }
        }
        
        return true;
    }
};