class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int sizeOfNums = nums.size();
        if (sizeOfNums <= 1)
            return sizeOfNums;
        
        int up = 1, down = 1;
        for (int i = 1; i < sizeOfNums; i++)
        {
            if (nums[i] > nums[i-1])
                up = down + 1;
            if (nums[i] < nums[i-1])
                down = up + 1;
        }
        
        return max(up, down);
    }
};