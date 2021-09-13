class Solution {
public:
    void sortColors(vector<int>& nums) {
        int numSize = nums.size();
        int start = 0, end = numSize-1;
        for(int i = start; i <= end; i++) {
            if(nums[i] == 0) {
                swap(nums[i], nums[start++]);
            } else if(nums[i] == 2) {
                swap(nums[i], nums[end--]);
                i--;
            }
        }
    }
};