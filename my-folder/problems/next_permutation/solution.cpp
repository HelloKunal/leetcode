class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int numsSize = nums.size();
        int indexOne = -1;
        for(int i = numsSize-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                indexOne = i;
                break;
            }
        }
        
        if(indexOne == -1) {
            sort(nums.begin(), nums.end());
            return;
        }
        
        for(int i = numsSize-1; i >= 0; i--) {
            if(nums[i] > nums[indexOne]) {
                swap(nums[i], nums[indexOne]);
                break;
            }
        }
        
        sort(nums.begin()+indexOne+1, nums.end());
    }
};