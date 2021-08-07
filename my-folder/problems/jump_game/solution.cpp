class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int last_big_jump = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {if (i == n - 1)
                {
                    return true;
                }
                else if (last_big_jump <= 0)
                {
                    return false;
                }
            }
            else
            {
                if (nums[i] > last_big_jump)
                    last_big_jump = nums[i];
            }
            
            last_big_jump--;
        }
        
        return true;
    }
};